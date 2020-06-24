//
// Created by jtiger958 on 2020/06/18.
//

#pragma once

#include "utils.h"

#define MAXLEN 10
#define UP 0
#define LEFT 1
#define CROSS 2

typedef struct {
    int row;
    int col;
} point;

typedef struct {
    char word[MAXLEN];
    int len;
} word;

word LCS(word w1, word w2);

#pragma once
