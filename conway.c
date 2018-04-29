#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

struct Node{
     int x;
     int y;
     struct Node *next;
};

struct List{
	struct Node *head;
};

struct httpOutput{
  char *allData;
  size_t size;
};

struct Node *CreateNode(){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node) + sizeof(int) + sizeof(int));
	node->x = 101;
	node->y=101;
	node->next=NULL;

	return node;
}

struct List *CreateList(){
	struct List *list = (struct List *)malloc(sizeof(struct List));
	list->head = NULL;

	return list;
}

void FreeAll(struct List *list){
	struct Node *current = (*list).head;
	struct Node *prev;
	while(current != NULL){
		prev = current;
		current = current->next;
		free(prev);
	};
}

void traverseList(struct List *list){
	struct Node *node = list->head;
	while(node->next != NULL){
		printf("x:%i  y:%i\n",node->x,node->y);
		node = node->next;
	}
}

static size_t addDataCallback(void *newData, size_t size, size_t nmemb, void *buffer)
{
  size_t newDataSize = size * nmemb;
  struct httpOutput *output = (struct httpOutput *)buffer;
 
  output->allData = realloc(output->allData, output->size + newDataSize + 1);
  if(output->allData == NULL) {
    printf("memory error\n");
    return 0;
  }
 
  memcpy(&(output->allData[output->size]), newData, newDataSize);
  output->size += newDataSize;
  output->allData[output->size] = '\0';
 
  return newDataSize;
}

void parseHTTPOutput(char *string, struct List *list){
	char currentNumber;
	char *trash;
	char newline = '\n';
	char end = '\0';
	int i = 0;
	int flag = 0;
	struct Node *node = CreateNode();
	struct Node *prev = node;
	list->head = node;
	while(strcmp(&string[i],&end) != 0){
		if(isdigit(string[i])){
			currentNumber = string[i];

		}else{
			long int number = strtol(&currentNumber,&trash,10);
			if(flag == 0){
				node->x = number;
				flag = 1;
			}else{
				node->y = number;
				if(strcmp(&string[i+1],&end) != 0){
					node = CreateNode();
					prev->next = node;
					prev = node;
				}
				flag = 0;
			}
			

		}
		i++;
	}

	

}


void initializeWithRandomPositions(int prevmatrix[10][10],int curmatrix[10][10], struct List *list){
	struct Node *node = list->head;
	while(node->next != NULL){
		prevmatrix[node->x][node->y] = 1;
		curmatrix[node->x][node->y] = 1;
		node = node->next;
	}

}

void conway(int prevmatrix[10][10], int curmatrix[10][10]){
	int left = -1;
	int right = 1;
	int bottom = -1;
	int top = 1;
	int rows = sizeof(*prevmatrix)/sizeof(*prevmatrix[0]);
	int columns = sizeof(prevmatrix[0])/sizeof(prevmatrix[0][0]);
	int i;
	int j;
	int neighbors_alive = 0;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			switch(i){
				case 0:
					top = 0;
					bottom = 1;
					break;
				case 9:
					top=1;
					bottom = 0;
					break;
				default:
					top = -1;
					bottom = 1;
					break;
			}

			switch(j){
				case 0:
					left = 0;
					right = 1;
					break;
				case 9:
					left = -1;
					right = 0;
					break;
				default:
					left = -1;
					right = 1;
					break;
			}
			
			if(top != 0){
				if(prevmatrix[i+top][j] == 1){
					neighbors_alive +=1;
				}
			}
			if(top !=0 && right != 0){
				if(prevmatrix[i+top][j+right] == 1){
					neighbors_alive +=1;
				}
			}
			if(top !=0 && left !=0){
				if(prevmatrix[i+top][j+left] == 1){
					neighbors_alive +=1;
				}
			}
			if(bottom != 0){
				if(prevmatrix[i+bottom][j] == 1){
					neighbors_alive +=1;
				}
			}
			if(bottom != 0 && right != 0){
				if(prevmatrix[i+bottom][j+right] == 1){
					neighbors_alive +=1;
				}
			}
			if(bottom != 0 && left != 0){
				if(prevmatrix[i+bottom][j+left] == 1){
					neighbors_alive +=1;
				}
			}
			if(left != 0){
				if(prevmatrix[i][j+left] == 1){
					neighbors_alive += 1;
				}
			}
			if(right != 0){
				if(prevmatrix[i][j+right] == 1){
					neighbors_alive += 1;
				}
			}

			if(curmatrix[i][j] == 1){
				if(neighbors_alive < 2 || neighbors_alive > 3){
					curmatrix[i][j] = 0;
				}
			}else{
				if(neighbors_alive == 3){
					curmatrix[i][j] =1;
				}
			}
			left = -1;
			right = 1;
			neighbors_alive = 0;
		}
		top = -1;
		bottom = 1;
	}
	return;
}

void printMatrix(int matrix[10][10]){
	int rows = sizeof(*matrix)/sizeof(*matrix[0]);
	int columns = sizeof(matrix[0])/sizeof(matrix[0][0]);
	int i;
	int j;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){

			if(matrix[i][j] == 0){
				printf(".");
			}else{
				printf("*");
			}
		}
		printf("\n");
	}

}

void setArray(int prevmatrix[10][10], int curmatrix[10][10]){
	int rows = sizeof(*prevmatrix)/sizeof(*prevmatrix[0]);
	int columns = sizeof(prevmatrix[0])/sizeof(prevmatrix[0][0]);
	int i;
	int j;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			prevmatrix[i][j] = curmatrix[i][j];
		}
	}
}

void run(int prevmatrix[10][10], int curmatrix[10][10],int numItters){
	int i;
	for(i=0;i<numItters;i++){
		conway(prevmatrix,curmatrix);
		setArray(prevmatrix,curmatrix);
		printMatrix(curmatrix);
		printf("\n"); 
	} 
	return;

}



int main(){
int selection = 3;
int iterations = 0;
int exit = 0;
int positions = 0;
char stringIterations[2];
struct List *list = CreateList();
char radom[] = "https://www.random.org/integers/?num=50&min=0&col=1&base=10&format=plain&rnd=new&max=";

int prevmatrix[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

int curmatrix[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};

while(exit != 0){
	while(selection != 0 || selection != 1){
		printf("WELCOME TO CONWAY'S GAME OF LIFE!\n\n");
		printf("please make a selection:\n");
		printf("1: play\n");
		printf("0: exit\n");
		scanf("%i\n",&selection);
		if(selection != 0 || selection != 1){
			printf("Invalid selection. Please try again\n\n");
		}
	}
	if(selection == 1){
		while(iterations<= 0){
			printf("please enter the number of iterations you would like to run the game for:\n\n");
			scanf("%i\n",&iterations);
			if(iterations <= 0){
				printf("Number of iterations must be greater than 0.\n\n");
			}
		}
		while(positions < 30 || positions >99){
			printf("please enter the number of random starting positions you would like to have please enter a number between (30-99):\n\n");
			scanf("%i\n", positions)
			if(positions<30 || positions>99){
				printf("You must select between 30-99 random starting positions.\n\n");
			}
		}

		positions = positions * 2;


		CURL *curl;
  		CURLcode response;
  		struct httpOutput output;
  		output.allData = (char *)malloc(sizeof(char));  
  		output.size = 0;    
  		curl_global_init(CURL_GLOBAL_ALL);
  		curl = curl_easy_init();
  		curl_easy_setopt(curl, CURLOPT_URL, url);
  		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, addDataCallback);
  		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&output);
  		response = curl_easy_perform(curl);

  
  		if(response != CURLE_OK) {
    		fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(response));
  		}
  		else {
  		parseHTTPOutput(output.allData,list);
  		traverseList(list);
  		initializeWithRandomPositions(prevmatrix,curmatrix,list);
  		run(prevmatrix,curmatrix,iterations);

 		}
 
  
  		curl_easy_cleanup(curl);
  		free(output.allData);
  		curl_global_cleanup();
  		FreeAll(list);
  		list->head = NULL;
	}else{
		printf("Goodbye!\n\n");
		exit = 1;
	}

}



  free(list);

return 0;
}
