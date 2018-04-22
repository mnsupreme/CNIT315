#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
     int data;
     struct Node *next;
};

struct List{
	struct Node *head;
};




void initializeWithRandomPositions(int *matrix[10][10], struct List *list){

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
					break;
				case 10:
					bottom = 0;
					break;
				default:
					bottom = -1;
					top = 1;
					break;
			}

			switch(j){
				case 0:
					left = 0;
					break;
				case 10:
					right = 0;
					break;
				default:
					left = -1;
					right = 1;
					break;
			}
			if(prevmatrix[i+top][j] == 1){
				neighbors_alive +=1;
			}
			if(prevmatrix[i+top][j+right] == 1){
				neighbors_alive +=1;
			}
			if(prevmatrix[i+top][j+left] == 1){
				neighbors_alive +=1;
			}
			if(prevmatrix[i+bottom][j] == 1){
				neighbors_alive +=1;
			}
			if(prevmatrix[i+bottom][j+right] == 1){
				neighbors_alive +=1;
			}
			if(prevmatrix[i+bottom][j+left] == 1){
				neighbors_alive +=1;
			}

			if(prevmatrix[i][j] == 1){
				if(neighbors_alive < 2 || neighbors_alive > 3){
					curmatrix[i][j] = 0;
				}
			}else{
				if(neighbors_alive == 3){
					curmatrix[i][j] =1;
				}
			}
			
			bottom = -1;
			top = 1;
			neighbors_alive = 0;
		}
		left = -1;
		right = 1;
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

void run(int prevmatrix[10][10], int curmatrix[10][10],int numItters){
	int i;
	for(i=0;i<numItters;i++){
		conway(prevmatrix,curmatrix);
		prevmatrix = curmatrix;
		printMatrix(curmatrix);
		printf("\n");
	} 
	return;

}

int main(){

int prevmatrix[10][10] = {
	{1,0,0,0,0,0,0,0,1,1},
	{0,1,1,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0},
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

printf("rows %i\n",sizeof(prevmatrix)/sizeof(prevmatrix[0]));
printf("columns %i\n",sizeof(curmatrix[0])/sizeof(curmatrix[0][0]));
	
run(prevmatrix,curmatrix,10);



return 0;
}
