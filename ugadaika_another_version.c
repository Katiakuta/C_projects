#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


const char* word(int n) {
    if ((n % 100) > 10 && (n % 100) < 15) {
        return "Попыток";
    }
    
    if (n % 100 == 1) {
        return "Попытку";
    } else if ((n % 100 == 2) || (n % 100 == 3) || (n % 100 == 4)) {
        return "Попытки";
    } else {
        return "Попыток";
    }
}

int user(int r) {
        int x = -1;
        int n = 1;
        while (x != r) {
            printf("Введите целое цисло от 0 до 1000 = ");
            scanf("%d", &x);
            if (x < r) {    
                printf("Загаданное число больше\n");
                n += 1;
            } else if (x > r) {
                printf("Загаданное число меньше\n");
                n +=1;
            } else {
                const char* k = word(n);
                printf("Вы угадали за %d %s\n", n, k);
                return 1;
            }
        } 
    }


int comp_choice() {
    int low = 0;
    int high = 1000;
    int attempts = 1;
    char ch;
    do {
        int n = low + (high - low) / 2;
        printf("Ваше число больше / меньше / равно %d ? (Введите '<', '>', '=')\n", n);
        scanf(" %c", &ch);
        if (ch == '<') {
            high = n - 1;
            attempts++;
        } else if (ch == '>') {
            low = n + 1;
            attempts++;
        } else if (ch == '=') {
            printf("%d — это и есть ваше число! Угадано за %d %s.\n", n, attempts, word(attempts));
        } else {
            printf("Не тот символ! Попробуйте еще раз.\n");
        }
    } while (ch != '=');
}


int main() {
    setlocale(LC_ALL, "Rus");
    srand((unsigned int)(time(NULL)));

    int x;
    int y;

    printf("Выберите режим 1 или 2 (1 - угадывает игрок, 2 - компьютер)\n");
    if (scanf("%d", &x) == 1){ 
        if (x == 1) {
            user(rand()%1000 + 1);
        } else if (x == 2) {
            printf("Пожалуйста, введите целое число, которое хотите загадать: ");
            scanf("%d", &y);
            comp_choice();
        } else {
            printf("Увы, это ни один и ни два :3\n");
        }
    }
    return 0;
}