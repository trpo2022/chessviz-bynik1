#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void createchess(char** chess)
{
    int i, j;
    char x = '`', z = '8';
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (j == 0 && z != '0') {
                chess[i][j] = z;
                z--;
            } else if (i == 8) {
                chess[i][j] = x;
                x++;
            } else if (i == 1) {
                chess[i][j] = 'p';
            } else if (i == 0 && (j == 1 || j == 8)) {
                chess[i][j] = 'r';
            } else if (i == 0 && (j == 2 || j == 7)) {
                chess[i][j] = 'n';
            } else if (i == 0 && (j == 3 || j == 6)) {
                chess[i][j] = 'b';
            } else if (i == 0 && j == 4) {
                chess[i][j] = 'q';
            } else if (i == 0 && j == 5) {
                chess[i][j] = 'k';
            } else if (i == 6) {
                chess[i][j] = 'P';
            } else if (i == 7 && (j == 1 || j == 8)) {
                chess[i][j] = 'R';
            } else if (i == 7 && (j == 2 || j == 7)) {
                chess[i][j] = 'N';
            } else if (i == 7 && (j == 3 || j == 6)) {
                chess[i][j] = 'B';
            } else if (i == 7 && j == 4) {
                chess[i][j] = 'Q';
            } else if (i == 7 && j == 5) {
                chess[i][j] = 'K';
            } else {
                chess[i][j] = ' ';
            }
        }
    }
    chess[8][0] = ' ';
}


void printchess(char** chess)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", chess[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int i;
    char** chess;
    char step[30];
    chess = (char**)malloc(9 * sizeof(char*));
    for (i = 0; i < 9; i++) {
        chess[i] = (char*)malloc(9 * sizeof(char));
    }

    createchess(chess);
    printchess(chess);
    scanf("%s", step);

   

    for (i = 0; i < 9; i++) {
        free(chess[i]);
    }
    free(chess);
    return 0;
}
