#include <stdio.h>
#include "headers/LCS.h"
#include "headers/bfs.h"
#include "headers/dijkstra.h"


int main() {
    int i, j;
    word w1 = {{'A', 'B', 'C', 'B', 'D', 'A', 'B', '\n'}, 7};
    word w2 = {{'B', 'D', 'C', 'A', 'B', 'A', '\n'}, 6};
    word result = LCS(w1, w2);

    printf("Word 1: %s", w1.word);
    printf("Word 2: %s", w2.word);
    printf("Longest Common Sequence: %s", result.word);
    printf("Length: %d\n", result.len);

    Node bfsGraph[8] = {{0, INT_MAX, 'r'}, {1, INT_MAX, 's'}, {2, INT_MAX, 't'}, {3, INT_MAX, 'u'},
                        {4, INT_MAX, 'v'}, {5, INT_MAX, 'w'}, {6, INT_MAX, 'x'}, {7, INT_MAX, 'y'}};

    int bfsAdjacentInit[8][8] = {
            {0, 1, 0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 1, 1, 0},
            {0, 0, 1, 0, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0, 0, 1, 0},
            {0, 0, 1, 1, 0, 1, 0, 1},
            {0, 0, 0, 1, 0, 0, 1, 0}
    };

    int **adjacent = alloc2DIntArr(8, 8);

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            adjacent[i][j] = bfsAdjacentInit[i][j];
        }
    }

    bfs(bfsGraph, 1, (int **) adjacent, 8);
    delete2DIntArr(adjacent, 8);


    for(i = 0; i < 8; i++) {
        printf("Node value: %c, distance: %d, pi: %c\n", bfsGraph[i].name, bfsGraph[i].distance, bfsGraph[i].pi);
    }


    int diAdjacentInit[5][5] = {
            {0, 1, 0, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 1},
            {0, 1, 1, 0, 1},
            {1, 0, 1, 0, 0}
    };

    int weightInit[5][5] = {
            {0, 10, 0, 5, 0},
            {0, 0, 1, 2, 0},
            {0, 0, 0, 0, 4},
            {0, 3, 9, 0, 2},
            {7, 0, 6, 0, 0}
    };

    int **weight;


    adjacent = alloc2DIntArr(5, 5);
    weight = alloc2DIntArr(5, 5);

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            adjacent[i][j] = diAdjacentInit[i][j];
        }
    }

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            weight[i][j] = weightInit[i][j];
        }
    }

    Node diGraph[5] = {{0, INT_MAX, 's'}, {1, INT_MAX, 't'}, {2, INT_MAX, 'x'},
                       {3, INT_MAX, 'y'}, {4, INT_MAX, 'z'} };

    Node *v;
    Node *s = &diGraph[0];
    v = &diGraph[3];

    dijkstra(diGraph, s, adjacent, weight, 5);


    puts("");
    printf("Path (name: %c, distance: %d) -> (name: %c, distance: %d) \n", s->name, s->distance, v->name, v->distance);
    printPath(diGraph, v);
    printf("\nTotal Cost: %d\n", v->distance);

    puts("");
    v = &diGraph[4];
    printf("Path (name: %c, distance: %d) -> (name: %c, distance: %d) \n", s->name, s->distance, v->name, v->distance);
    printPath(diGraph, v);
    printf("\nTotal Cost: %d\n", v->distance);



    puts("");
    for(i = 0; i < 5; i++) {
        printf("Node value: %c, distance: %d, pi: %c\n", diGraph[i].name, diGraph[i].distance, diGraph[i].pi);
    }

    delete2DIntArr(adjacent, 5);
    delete2DIntArr(weight, 5);
}