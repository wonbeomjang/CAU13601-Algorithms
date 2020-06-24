//
// Created by jtiger958 on 2020/06/18.
//

#include "../headers/utils.h"

#include <stdlib.h>



int **alloc2DIntArr(int numRow, int numCol) {
    int **arr = (int**)malloc(numRow * sizeof(int*));

    for(int i = 0; i < numCol; i++) {
        arr[i] = (int*)calloc(numCol, sizeof(int));
    }

    return arr;
}

void delete2DIntArr(int *arr[], int numRow) {
    for(int i = 0; i < numRow; i++) {
        free(arr[i]);
    }
    free(arr);
}