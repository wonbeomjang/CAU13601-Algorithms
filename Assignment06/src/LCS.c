#include "../headers/LCS.h"
#include <stdio.h>

word LCS(word w1, word w2) {
    point dxdy[3] = {{-1, 0}, {0, -1}, {-1, -1}};
    int m = w1.len;
    int n = w2.len;
    int **b = alloc2DIntArr(m + 2, n + 2);
    int **c= alloc2DIntArr(m + 2, n + 2);
    word result;
    point p;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(w1.word[i - 1] == w2.word[j - 1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = CROSS;
            }
            else if (c[i - 1][j] >= c[i][j - 1]){
                c[i][j] = c[i - 1][j];
                b[i][j] = UP;
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = LEFT;
            }
        }
    }

    for(int row = m, col = n; row > 0 && col > 0;) {
        p = dxdy[b[row][col]];

        if(b[row][col] == CROSS)
            result.word[c[row][col] - 1] = w1.word[row - 1];

        row += p.row;
        col += p.col;
    }
    result.len = c[w1.len][w2.len];
    result.word[result.len] = '\n';

    delete2DIntArr(c, m + 1);
    delete2DIntArr(b, m + 1);

    return result;
}