#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
     int data;
     struct Node *next
}

struct List{
	struct Node *head;
}


void initializeWithRandomPositions(int *matrix[10][10], struct List *list){

}

void conway(int *prevmatrix[10][10], int *curmatrix[10][10]){
	int left;
	int right;
	int top;
	int bottom;
	int top-right;
	int top-left;
	int bottom-left;
	int bottom-right;
	int rows = sizeof(*prevmatrix)/sizeof(*prevmatrix[0]);
	int columns = sizeof(*prevmatrix)/sizeof(*prevmatrix[0][0]);
	int i;
	int j;
	
}

void run(int *prevmatrix[10][10], int *curmatrix[10][10],int numItters){
	int i;
	for(i=0;i<numItters;i++){
		*prevmatrix = *curmatrix;
	} 

}

int main(){

	
}