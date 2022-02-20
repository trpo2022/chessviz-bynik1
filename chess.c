#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void cleaner(char **chess)
{
     for (int i = 0; i < 9; i++) {
        free(chess[i]);
    }
    free(chess);
    exit(-1);
}


void create_chess(char** chess)
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

void step_chess(char** chess, char* step)
{
    long int x = strlen(step);
    int start_Pos_Let, start_Pos_Num, end_Pos_Let, end_Pos_Num;
    char type, figure, end;
    if (x == 5) {
        start_Pos_Let = step[0];
        start_Pos_Num = step[1];
        type = step[2];
        end_Pos_Let = step[3];
        end_Pos_Num = step[4];
    } else if (x == 6) {
        figure = tolower(step[0]);
        start_Pos_Let = step[1];
        start_Pos_Num = step[2];
        type = step[3];
        end_Pos_Let = step[4];
        end_Pos_Num = step[5];      
    } else if (x >= 7) {
        figure = tolower(step[0]);
        start_Pos_Let = step[1];
        start_Pos_Num = step[2];
        type = step[3];
        end_Pos_Let = step[4];
        end_Pos_Num = step[5];
        end = step[6];
    }
    

    start_Pos_Let -= '`';  
    start_Pos_Num -= '0';
    end_Pos_Let -= '`';
    end_Pos_Num -= '0';


    printf("%d %d %d %d %ld %c\n", start_Pos_Let, start_Pos_Num, end_Pos_Let, end_Pos_Num, x, figure);

    if (x < 5 || x > 10) {  
        printf("Вы ввели некорректный ход!\n");
        cleaner(chess);
    } else if (start_Pos_Num > 8 || start_Pos_Num < 1 || end_Pos_Num > 8 || end_Pos_Num < 1 || start_Pos_Let > 8 || start_Pos_Let < 1 || end_Pos_Let > 8 || end_Pos_Let < 1) {
        printf("Вы вышли за пределы поля!\n");
        cleaner(chess);
    } else if (figure != tolower(chess[start_Pos_Num][start_Pos_Let]) && x == 6) {
        if (chess[start_Pos_Num][start_Pos_Let] == ' ') {
            printf("На этом месте нет фигуру!\n");
        } else {
            printf("Вы берете не ту фигуру!\n");
        }
        cleaner(chess);
    } else if (chess[start_Pos_Num][start_Pos_Let] == ' ') {
        printf("На этом месте нет фигуру!\n");
        cleaner(chess);
    } else if ((type == '-' && chess[end_Pos_Num][end_Pos_Let] != ' ') || (type == 'x' && chess[end_Pos_Num][end_Pos_Let] == ' ') || (type != '-' && type != 'x')) {
        printf("Вы используете некорректный тип хода!\n");
        cleaner(chess);
    } else if (x >= 7 && (end != '+' && end != '#' && end != 'e')) {
        printf("Вы используете некорректный !\n");
        cleaner(chess);       
    }else if(start_Pos_Let == end_Pos_Let && start_Pos_Num == end_Pos_Num){
        printf("Вы остались на месте походите ещё раз");
        cleaner(chess);
    }


    if(figure == 'r' && start_Pos_Let != end_Pos_Let && start_Pos_Num != end_Pos_Num){
        printf("Неправильный ход ладьёй");
    } else if(figure == 'r' && start_Pos_Let == end_Pos_Let )




    chess[end_Pos_Num][end_Pos_Let] = chess[start_Pos_Num][start_Pos_Let];
    chess[start_Pos_Num][start_Pos_Let] = ' ';   

}

void print_chess(char** chess)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", chess[i][j]);
        }
        printf("\n");
    }
}

int checkking(char** chess) {
    int flag = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (chess[i][j] == 'k' || chess[i][j] == 'K') {
                flag++;
            }
        }       
    }
    return flag;
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

    create_chess(chess);
    print_chess(chess);
    scanf("%s", step);

    while (checkking(chess) == 2) {
        step_chess(chess, step);
        print_chess(chess);
        scanf("%s", step); 
    }

   
}
