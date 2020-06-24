#include "../headers/knapsack.h"

void sortItemByValPerWeight(knapsackItem *item, int n) {
    int i, j;
    knapsackItem temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (item[j].valuePerWeight < item[j + 1].valuePerWeight) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

void sortItemById(knapsackItem *item, int n) {
    int i, j;
    knapsackItem temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (item[j].itemNum < item[j + 1].itemNum) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

double computeMaxValue(knapsackItem item[], int n, double maxWeight) {
    int i;
    double remained, maxValue;

    maxValue = 0;
    for (i = 0; i < n; i++) {
        remained = item[i].weight;
        if (maxWeight >= remained) {
            maxWeight -= remained;
            maxValue += item[i].value;
            remained = 0;
        }
        else {
            maxValue += item[i].valuePerWeight * maxWeight;
            remained -= maxWeight;
            maxWeight = 0;
        }
        item[i].used = item[i].weight - remained;
        item[i].weight = remained;
    }

    return maxValue;
}