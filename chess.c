#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void createchess(char** chess)
{
    int i, j;
    char x = 'a', z = '1';
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (i == 0 && j != 0) {
                chess[i][j] = x;
                x++;
            } else if (j == 0 && i != 0) {
                chess[i][j] = z;
                z++;
            } else if (i == 2) {
                chess[i][j] = 'P';
            } else if (i == 1 && (j == 1 || j == 8)) {
                chess[i][j] = 'R';
            } else if (i == 1 && (j == 2 || j == 7)) {
                chess[i][j] = 'N';
            } else if (i == 1 && (j == 3 || j == 6)) {
                chess[i][j] = 'B';
            } else if (i == 1 && j == 4) {
                chess[i][j] = 'Q';
            } else if (i == 1 && j == 5) {
                chess[i][j] = 'K';
            } else if (i == 7) {
                chess[i][j] = 'p';
            } else if (i == 8 && (j == 1 || j == 8)) {
                chess[i][j] = 'r';
            } else if (i == 8 && (j == 2 || j == 7)) {
                chess[i][j] = 'n';
            } else if (i == 8 && (j == 3 || j == 6)) {
                chess[i][j] = 'b';
            } else if (i == 8 && j == 4) {
                chess[i][j] = 'q';
            } else if (i == 8 && j == 5) {
                chess[i][j] = 'k';
            } else {
                chess[i][j] = ' ';
            }
        }
    }
}

void stepchess(char** chess, char* step)
{
    long int x = strlen(step);
    int startPosLet, startPosNum, endPosLet, endPosNum;
    char type, figure, end;
    if (x == 5) {
        startPosLet = step[0];
        startPosNum = step[1];
        type = step[2];
        endPosLet = step[3];
        endPosNum = step[4];
    } else if (x == 6) {
        figure = step[0];
        startPosLet = step[1];
        startPosNum = step[2];
        type = step[3];
        endPosLet = step[4];
        endPosNum = step[5];      
    } else if (x >= 7) {
        figure = step[0];
        startPosLet = step[1];
        startPosNum = step[2];
        type = step[3];
        endPosLet = step[4];
        endPosNum = step[5];
        end = step[6];
    }
    

    startPosLet -= '`';  
    startPosNum -= '0';
    endPosLet -= '`';
    endPosNum -= '0';


    //printf("%d %d %d %d %ld %c\n", startPosLet, startPosNum, endPosLet, endPosNum, x, figure);

    if (x < 5 || x > 6) {
        printf("Вы ввели некорректный ход!\n");
        exit(-1);
    } else if (startPosNum > 8 || startPosNum < 1 || endPosNum > 8 || endPosNum < 1 || startPosLet > 8 || startPosLet < 1 || endPosLet > 8 || endPosLet < 1) {
        printf("Вы вышли за пределы поля!\n");
        exit(-1);
    } 

    chess[endPosNum][endPosLet] = chess[startPosNum][startPosLet];
    chess[startPosNum][startPosLet] = ' ';   

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

    
    stepchess(chess, step);
    printchess(chess);


    for (i = 0; i < 9; i++) {
        free(chess[i]);
    }
    free(chess);
    return 0;
}
