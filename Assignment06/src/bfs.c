//
// Created by jtiger958 on 2020/06/18.
//
#include "../headers/bfs.h"

void bfs(Node graph[], int start, int **adjacent, int numNode) {
    clearQ();
    Node *u;
    Node *v;
    u = &graph[start];
    u->pi = 0;
    u->distance = 0;
    u->visited = 1;

    enqueue(u);
    while (!isEmptyQ()) {
        u = dequeue();
        for(int i = 0; i < numNode; i++) {
            if(adjacent[u->val][i] && !graph[i].visited) {
                v = &graph[i];
                v->distance = u->distance + 1;
                v->pi = u->name;
                v->visited = 1;
                enqueue(v);
            }
        }
    }
}


