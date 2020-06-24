#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"
#define MAXSIZE 10
#define MAXLEN 5

typedef struct {
	int numRow;
	int numCol;
	int num;
	int arr[MAXSIZE][MAXSIZE];
} Matrix;

stack* _stack;

Matrix matMul(Matrix m1, Matrix m2);
Matrix makeMatrix(int numRow, int numCol);
void printMatrix(Matrix m);
pair matrixChainOrder(int p[], int len);
Matrix matrixChain(Matrix m[], int* order[], int start, int end);

