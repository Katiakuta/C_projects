#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int color(int x1, int y1, int x2, int y2) {
    if ( (x1 + y1) % 2 == (x2 + y2) % 2) {
        return 1;
    } else {
        return 0;
    }
}

int rook(int x1, int y1, int x2, int y2) {
    if ((x1 == x2) || (y1 == y2)) {
        return 1;
    } else {
        return 0;
    }
}

int bishop(int x1, int y1, int x2, int y2) {
    for (int k = 1;k <8;k+=1) {
        if (abs(x2 - x1) == abs(y2 - y1)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int king(int x1, int y1, int x2, int y2) {
    if (abs(x2-x1) < 2 && abs(y2-y1) < 2 && (x1 != x2 && y1 != y2)) {
        return 1;
    } else {
        return 0;
    }
}

int queen(int x1, int y1, int x2, int y2) {
    if ((rook(x1,y1,x2,y2)) || (bishop(x1,y1,x2,y2)) ) {
        return 1;
    } else {
        return 0;
    }
}


int main() {

    setlocale(LC_ALL, "Rus");

    int x1, y1, x2, y2;
    printf("Введите координаты клеток (X1 Y1) и (X2 Y2) от 1 до 8 (Пример: 1 2 3 4): ");
    if (scanf("%d %d %d %d", &x1,&y1,&x2,&y2) != 4 ) {
        printf("Ошибка ввода");
        return 1;
    } else if (
        (x1 < 1 || x1 > 8) || (x2 < 1 || x2 > 8) || (y1 < 1 || y1 > 8) || (y2 < 1 || y2 > 8)) {
        printf("Такой клетки не существует!");
        return 1;
    } else if ((x1 == x2) && (y1 == y2)){
        printf("Это одна и та же клетка!");
        return 1;
    }

    if (color(x1,y1,x2,y2)) {
        printf("Клетки одного цвета.\n");
    } else {
        printf("Клетки разного цвета.\n");
    }

    printf("Угрожает ладья %s\n", rook(x1,y1,x2,y2) ? "Да" : "Нет");
    printf("Угрожает слон %s\n", bishop(x1,y1,x2,y2) ? "Да" : "Нет");
    printf("Угрожает король %s\n", king(x1,y1,x2,y2) ? "Да" : "Нет");
    printf("Угрожает ферзь %s\n", queen(x1,y1,x2,y2) ? "Да" : "Нет");

    return 0;
}
