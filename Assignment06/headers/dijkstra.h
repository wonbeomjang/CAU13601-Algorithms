//
// Created by jtiger958 on 2020/06/23.
//

#pragma once

#include "graph.h"

void dijkstra(Node graph[], Node *src, int** adjacent, int** weight, int numNode);

void printPath(Node graph[], Node *des);