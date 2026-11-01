#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");

    int c;
    int in_num = 0;
    int counter = 0;


    while((c = getchar()) != '.') {
        if ((isdigit(c) == 1) && (in_num == 0)) {
            counter++;
            in_num = 1;
        } else if (isdigit(c) != 1) {
            in_num = 0;
        }
    }
    printf("Количество чисел = %d\n", counter );
    return 0;
}