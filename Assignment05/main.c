#include <stdio.h>
#include <stdlib.h>
#include "headers/matrix.h"
#include "headers/fibo.h"
#include "headers/knapsack.h"


int main() {
	/*
	*
	* Qustion 1: Fibonacci numbers using dynamic programming
	*
	*/
	int i, j, k;
	_stack = makeStack();

	puts("\nQustion 1: Fibonacci numbers using dynamic programming");
	printf("\nn = %3d: fibonacci(%3d) = %3d\n", 5, 5, fibo(5));
	printf("n = %3d: fibonacci(%3d) = %3d\n", 10, 10, fibo(10));
	puts("");




	/*
	*
	* Qustion 2: Fibonacci numbers using dynamic programming
	*
	*/
	int dimension[] = { 5, 3, 7, 10 };
	int numChain = sizeof(dimension) / sizeof(*dimension) - 1;
	int **cost;
	Matrix chain[4];
	Matrix result;

	// Make matrix with defined demansion
	for (i = 0; i < numChain; i++) {
		chain[i] = makeMatrix(dimension[i], dimension[i + 1]);
		chain[i].num = i;
	}
	puts("----------------------------------------------------------------------------------------");

	puts("\nQuestion2: Implement a matrix-chain multiplication algorithm using dynamic programming");

	// Compute optimal chain order
	pair p = matrixChainOrder(dimension, numChain + 1);

	// Compute matrix multiplication using computed order
	result = matrixChain(chain, p.second, 0, numChain - 1);

	puts("\nInput Matrix 1");
	printMatrix(chain[0]);
	puts("\nInput Matrix 2");
	printMatrix(chain[1]);
	puts("\nInput Matrix 3");
	printMatrix(chain[2]);

	// print matrix multiplication result
	puts("\nresult matrix");
	printMatrix(result);

	printf("\nindex and corresponding dimension \n");
	for (i = 0; i < numChain + 1; i++) {
		printf("%d [dim: %d] / ", i, dimension[i]);
	}
	puts("\b\b\b  ");

	// print chain order (print middle dimension)
	// m = {3, 2, 1}, [3 x 2] [2 x 1] -> 1 [dim: 2]
	printf("\ncomputation order displayed using index is \n");
	j = _stack->size;
	for (i = 0; i < j; i++) {
		k = pop(_stack);
		printf("%d [dim: %d] -> ", k, dimension[k]);
	}
	puts("\b\b\b  ");

	// print thie minimum number of computations.
	cost = p.first;
	printf("\nminimum number of computations: %d\n", cost[1][numChain]);
	puts("----------------------------------------------------------------------------------------");


	/*
	*
	* Qustion 3: Implement an algorithm for the fractional knapsack problem
	*
	*/
	double maxWeight = 16;
	double weight[6] = { 6, 10, 3, 5, 1, 3 };
	int value[6] = { 60, 20, 12, 80, 30, 60 };
	knapsackItem item[6];
	double maxValue;
	puts("\n\nQustion 3: Implement an algorithm for the fractional knapsack problem");
	printf("\nMaximum weight: %lf\n", maxWeight);

	for (i = 0; i < 6; i++) {
		item[i].itemNum = i + 1;
		item[i].value = value[i];
		item[i].weight = weight[i];
		item[i].valuePerWeight = value[i] / weight[i];
	}

    sortItemByValPerWeight(item, 6);
	printf("\n%10s %10s %10s %15s\n", "Item", "Weight", "Value", "value / weight");
	for (int i = 0; i < 6; i++) {
		printf("%10d %10lf %10d %15f\n", item[i].itemNum, item[i].weight, item[i].value, item[i].valuePerWeight);
	}

	maxValue = computeMaxValue(item, 6, maxWeight);

//    sortItemById(item, 6);

	printf("\nMax Value: %lf\n", maxValue);


    printf("\n%10s %10s\n", "Item", "Used");
    for (int i = 0; i < 6; i++) {
        printf("%10d %10lf\n", item[i].itemNum, item[i].used);
    }

	printf("\n%10s %10s\n", "Item", "Remained weight");
	for (int i = 0; i < 6; i++) {
		printf("%10d %10lf\n", item[i].itemNum, item[i].weight);
	}
	puts("----------------------------------------------------------------------------------------");

	return 0;
}