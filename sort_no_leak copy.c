#include <stdio.h>
#include <stdlib.h>
#define LEN 10

int input(int **a, int *length);
void output(int *a, int length);
void sort(int *a, int length);

int main() {
    int length, *data = NULL;

    int flag;

    flag = input(&data, &length);

    if (flag == 1) {
        sort(data, length);
        output(data, length);
    }
    free(data);

    return 0;
}

int input(int **a, int *length) {
    int flag = 1;
    char lastChar;
    if ((scanf("%d%c", length, &lastChar) == 2 && lastChar == '\n') && (*length > 0 && *length <= LEN)) {
        *a = (int *)malloc(sizeof(int) * (*length));
        for (int i = 0; i < *length; i++) {
            if ((scanf("%d%c", (*a + i), &lastChar) == 2) &&
                ((lastChar == ' ' && (i < *length)) || (lastChar == '\n' && (i == *length - 1)))) {
                flag = 1;
            } else {
                printf("n/a");
                flag = 0;
                break;
            }
        }
    } else {
        printf("n/a");
        flag = 0;
    }

    return flag;
}

void sort(int *a, int length) {
    for (int limit = length - 1; limit > 0; limit -= 1) {
        for (int i = 0; i < limit; i += 1) {
            if (a[i] > a[i + 1]) {
                int temporary = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temporary;
            }
        }
    }
}

void output(int *a, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", a[i]);
        if (i + 1 < length) {
            printf(" ");
        }
    }
}
