#include <stdio.h>
#define LEN 10

int input(int *a);
void output(int *a, int *step);
void sortA(int *a);
void sortB(int *a, int N);

int main() {
    int data[LEN];

    int step = 0;
    int flag;
    flag = input(data);
    int N = data[LEN - 1];
    if (flag == 1) {
        sortA(data);
        output(data, &step);
        sortB(data, N);
        output(data, &step);
    }

    return 0;
}

int input(int *a) {
    int flag = 1;
    for (int *p = a; p - a < LEN; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a");
            flag = 0;
            break;
        } else {
            char ch = getchar();
            if ((ch == ' ' && (p - a + 1 < 10)) || (ch == '\n' && (p - a + 1 == LEN))) {
                flag = 1;
            } else {
                printf("n/a");
                flag = 0;
                break;
            }
        }
    }

    return flag;
}

void sortA(int *a) {
    for (int limit = LEN - 1; limit > 0; limit -= 1) {
        for (int i = 0; i < limit; i += 1) {
            if (a[i] > a[i + 1]) {
                int temporary = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temporary;
            }
        }
    }
}

void sortB(int *a, int N) {
    long i = 0, j = N - 1;
    int temp, p;

    p = a[N >> 1];

    do {
        while (a[i] < p) i++;
        while (a[j] > p) j--;

        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) sortB(a, j);
    if (N > i) sortB(a + i, N - i);
}

void output(int *a, int *step) {
    if (*step == 1) {
        printf("\n");
    }

    for (int *p = a; p - a < LEN; p++) {
        printf("%d", *p);
        if (p - a + 1 < LEN) {
            printf(" ");
        }
    }
    *step = 1;
}
