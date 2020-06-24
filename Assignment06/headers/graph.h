//
// Created by jtiger958 on 2020/06/23.
//

#pragma once

#include <sys/queue.h>
#include <limits.h>
TAILQ_HEAD(nqueue, entry) qhead;
TAILQ_HEAD(nstack, entry) shead;

typedef struct {
    int val;
    int distance;
    char name;
    char pi;
    int visited;
} Node;

struct entry {
    Node *node;
    TAILQ_ENTRY(entry) next;
};

void push(Node *node);
Node* pop();
int isEmptyS();
void clearS();

void enqueue(Node *node);
void clearQ();
Node *dequeue();
Node *dequeueMinDis();
int isEmptyQ();
