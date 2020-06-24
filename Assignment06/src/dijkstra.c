//
// Created by jtiger958 on 2020/06/23.
//

#include "../headers/dijkstra.h"
#include <stdio.h>

void dijkstra(Node graph[], Node *src, int** adjacent, int** weight, int numNode) {
    int i, j;
    Node *u;
    Node *v;
    src->pi = 0;
    src->distance = 0;
    clearS();

    for(i = 0; i < numNode; i++) {
        enqueue(&graph[i]);
    }

    while (!isEmptyQ()) {
        u = dequeueMinDis();
        u->visited = 1;
        for(i = 0; i < numNode; i++) {
            if(adjacent[u->val][i] && !graph[i].visited) {
                v = &graph[i];
                if(v->distance > u->distance + weight[u->val][v->val]) {
                    v->distance = u->distance + weight[u->val][v->val];
                    v->pi = u->name;
                }
            }
        }
    }
}

void printPath(Node graph[], Node *des) {
    int i;
    Node *v = des;
    clearS();
    push(v);
    while (v->pi) {
        for (i = 0; i < 5; i++) {
            if (v->pi == graph[i].name) {
                push(&graph[i]);
                v = &graph[i];
                break;
            }
        }
    }

    while (!isEmptyS()) {
        v = pop();
        printf("(name: %c, distance: %d)-> ", v->name, v->distance);
    }

    printf("\b\b\b   ");
}