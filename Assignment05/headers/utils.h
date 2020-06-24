#pragma once
#include <stdlib.h>
#include <stdio.h>


typedef struct {
	int size;
	int item[100];
} stack;

typedef struct {
	void* first;
	void* second;
} pair;


int** alloc2dArr(int numRow, int numCol);
void free2dArr(int** arr, int numRow);

stack* makeStack();
void push(stack* s, int n);
int pop(stack* s);