#include "../headers/utils.h"

int** alloc2dArr(int numRow, int numCol) {
	int **arr = (int**)calloc(numRow, sizeof(int*));
	int i, j;
	for (i = 0; i < numRow; i++) {
		arr[i] = (int*)calloc(numCol, sizeof(int));
	}

	return arr;
}

void free2dArr(int** arr, int numRow) {
	int i;
	for (i = 0; i < numRow; i++) free(arr[i]);
	free(arr);
}

stack* makeStack() {
	stack* s = calloc(1, sizeof(stack));
	
	return s;
}

void push(stack *s, int n) {
	s->item[s->size] = n;
	s->size++;
}

int pop(stack *s) {
	s->size--;
	return s->item[s->size];
}