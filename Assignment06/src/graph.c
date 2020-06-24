//
// Created by jtiger958 on 2020/06/23.
//

#include "../headers/graph.h"
#include <stdlib.h>

void push(Node *node) {
    struct entry *elem;
    elem = malloc(sizeof(struct entry));
    if (elem) {
        elem->node = node;
    }
    TAILQ_INSERT_HEAD(&shead, elem, next);
}

Node* pop() {
    Node *node;
    struct entry *elem;
    elem = TAILQ_FIRST(&shead);
    node = elem->node;
    TAILQ_REMOVE(&shead, elem, next);
    free(elem);
    return node;
}

int isEmptyS() {
    return TAILQ_EMPTY(&shead);
}

void clearS() {
    while(!TAILQ_EMPTY(&shead)) {
        struct entry *elem = TAILQ_FIRST(&shead);
        TAILQ_REMOVE(&shead, elem, next);
    }
}

void enqueue(Node *node) {
    struct entry *elem;
    elem = malloc(sizeof(struct entry));
    if (elem) {
        elem->node = node;
    }
    TAILQ_INSERT_HEAD(&qhead, elem, next);
}

Node *dequeue() {
    Node *node;
    struct entry *elem;
    elem = TAILQ_LAST(&qhead, nqueue);
    node = elem->node;
    TAILQ_REMOVE(&qhead, elem, next);
    free(elem);

    return node;
}

Node *dequeueMinDis() {
    Node *node;
    struct entry *elem;
    struct entry *minElem = TAILQ_FIRST(&qhead);
    TAILQ_FOREACH(elem, &qhead, next) {
        if(minElem->node->distance > elem->node->distance) {
            minElem = elem;
        }
    }
    TAILQ_REMOVE(&qhead, minElem, next);

    return minElem->node;
}

int isEmptyQ() {
    return TAILQ_EMPTY(&qhead);
}

void clearQ() {
    while(!TAILQ_EMPTY(&qhead)) {
        struct entry *elem = TAILQ_FIRST(&qhead);
        TAILQ_REMOVE(&qhead, elem, next);
    }
}