#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int flag;
    flag = input(data, &n);
    if (flag == 1) {
        squaring(data, n);
        output(data, n);
    }

    return 0;
}

int input(int *a, int *n) {
    int flag = 1;
    char lastChar;
    if ((scanf("%d%c", n, &lastChar) == 2 && lastChar == '\n') && (*n > 0 && *n <= NMAX)) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                printf("n/a");
                flag = 0;
                break;
            } else {
                char ch = getchar();
                if ((ch == ' ' && (p - a + 1 < *n)) || ch == '\n') {
                    flag = 1;
                } else {
                    printf("n/a");
                    flag = 0;
                    break;
                }
            }
        }
    } else {
        printf("n/a");
        flag = 0;
    }

    return flag;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) {
            printf(" ");
        }
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}
