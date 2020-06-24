#pragma once
#include "../headers/matrix.h"
#include "../headers/utils.h"


Matrix matMul(Matrix m1, Matrix m2) {
	assert(m1.numCol == m2.numRow);
	Matrix res;
    int sum, i, j, k;

	res.numRow = m1.numRow;
	res.numCol = m2.numCol;


	for (i = 0; i < m1.numRow; i++) {
		for (j = 0; j < m2.numCol; j++) {
			sum = 0;
			for (k = 0; k < m1.numCol; k++) {
				sum += (m1.arr[i][k] * m2.arr[k][j]);
			}
			res.arr[i][j] = sum;
		}
	}

	return res;
}

Matrix makeMatrix(int numRow, int numCol) {
	Matrix m;
	int i, j;
	m.numRow = numRow;
	m.numCol = numCol;

	for (i = 0; i < numRow; i++) {
		for (j = 0; j < numCol; j++) {
			m.arr[i][j] = rand() % 5;
		}
	}

	return m;
}

void printMatrix(Matrix m) {
	int i, j;
	for (i = 0; i < m.numRow; i++) {
		putc('|', stdout);
		for (j = 0; j < m.numCol; j++) {
			printf("%5d", m.arr[i][j]);
		}
		puts("|");
	}
}

pair matrixChainOrder(int p[], int len) {
	int n = len - 1;
	int** m = alloc2dArr(n + 1, n + 1);
	int** s = alloc2dArr(n + 1, n + 1);
	int i, j, k, l, sum;
	pair res;

	for (i = 1; i <= n; i++)
		m[i][i] = 0;

	for (l = 2; l <= n; l++) {
		for (i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++) {
				sum = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (sum < m[i][j]) {
					m[i][j] = sum;
					s[i][j] = k;
				}
			}
		}
	}

	res.first = m;
	res.second = s;

	return res;
}
	
Matrix matrixChain(Matrix m[], int *order[], int start, int end) {
	if (start == end)
		return m[start];

	int mid = order[start + 1][end + 1];
	push(_stack, mid);
	Matrix front = matrixChain(m, order, start, mid - 1);
	Matrix rear = matrixChain(m, order, mid, end);
	Matrix result = matMul(front, rear);

	return result;
}

