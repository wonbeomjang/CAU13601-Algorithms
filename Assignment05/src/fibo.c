#pragma once
#include "../headers/fibo.h"

int fibo(int n) {
	static int fiboNum[MAXNUM] = { 0, 1, 1 };

	if (fiboNum[n] != 0)	return fiboNum[n];

	fiboNum[n] = fibo(n - 1) + fibo(n - 2);

	return fiboNum[n];
}
