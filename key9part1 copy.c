/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *flag);
void output(int *numbers, int number, int count);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int length, buffer[NMAX];
    int numbers[NMAX];
    int number;
    int flag;
    input(buffer, &length, &flag);
    if (flag == 1) {
        number = sum_numbers(buffer, length);
        if (number > 0) {
            int count = find_numbers(buffer, length, number, numbers);
            if (count > 0) {
                output(numbers, number, count);
            }
        }
    }

    return 0;
}

void input(int *buffer, int *length, int *flag) {
    char lastChar;
    if ((scanf("%d%c", length, &lastChar) == 2 && lastChar == '\n') && (*length > 0 && *length <= NMAX)) {
        for (int *p = buffer; p - buffer < *length; p++) {
            if ((scanf("%d%c", p, &lastChar) == 2) && ((lastChar == ' ' && (p - buffer + 1 < *length)) ||
                                                       (lastChar == '\n' && (p - buffer + 1 == *length)))) {
                *flag = 1;
            } else {
                printf("n/a");
                *flag = 0;
                break;
            }
        }
    } else {
        printf("n/a");
        *flag = 0;
    }
}

void output(int *numbers, int number, int count) {
    printf("%d\n", number);
    for (int *p = numbers; p - numbers < count; p++) {
        printf("%d", *p);
        if (p - numbers + 1 < count) {
            printf(" ");
        }
    }
    printf("\n");
}
/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length - 1; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && (number % buffer[i] == 0)) {
            numbers[count] = buffer[i];
            count++;
        }
    }

    return count;
}
