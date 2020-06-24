#pragma once
typedef struct  {
	int itemNum;
	int value;
	double weight;
	double valuePerWeight;
	double used;
} knapsackItem;

void sortItemByValPerWeight(knapsackItem *item, int n);

double computeMaxValue(knapsackItem item[], int n, double maxWeight);
void sortItemById(knapsackItem *item, int n);