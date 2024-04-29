#include <stdio.h>
#define LEN 10

int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int data[LEN];

    int flag;
    flag = input(data);
    if (flag == 1) {
        sort(data);
        output(data);
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

void sort(int *a) {
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

void output(int *a) {
    for (int *p = a; p - a < LEN; p++) {
        printf("%d", *p);
        if (p - a + 1 < LEN) {
            printf(" ");
        }
    }
}
