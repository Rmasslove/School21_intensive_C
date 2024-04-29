

#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *number, int *flag);
void output(int *buffer, int length);
int cycleShift(int *buffer, int length, int number);

int main() {
    int length, buffer[NMAX], number;
    int flag;
    input(buffer, &length, &number, &flag);
    if (flag == 1) {
        int r = cycleShift(buffer, length, number);
        if (r == 1) {
            output(buffer, length);
        }
    }

    return 0;
}

void input(int *buffer, int *length, int *number, int *flag) {
    char lastChar;
    if ((scanf("%d%c", length, &lastChar) == 2 && lastChar == '\n') && (*length > 0 && *length <= NMAX)) {
        for (int *p = buffer; p - buffer < *length; p++) {
            if ((scanf("%d%c", p, &lastChar) == 2) && ((lastChar == ' ' && (p - buffer + 1 < *length)) ||
                                                       (lastChar == '\n' && (p - buffer + 1 == NMAX)))) {
                *flag = 1;

            } else {
                printf("n/a");
                *flag = 0;
                break;
            }
            if (p - buffer == *length - 1) {
                if ((scanf("%d%c", number, &lastChar) == 2 && lastChar == '\n')) {
                    *flag = 1;
                } else {
                    printf("n/a");
                    *flag = 0;
                    break;
                }
            }
        }

    } else {
        printf("n/a");
        *flag = 0;
    }
}

int cycleShift(int *buffer, int length, int number) {
    if (number > 0) {
        for (int i = 0; i < number; i++) {
            int temp = buffer[0];
            for (int j = 1; j < length; j++) {
                buffer[j - 1] = buffer[j];
            }
            buffer[length - 1] = temp;
        }
    } else if (number < 0) {
        for (int i = number; i < 0; i++) {
            int temp = buffer[length - 1];
            for (int j = length - 2; j > -1; j--) {
                buffer[j + 1] = buffer[j];
            }
            buffer[0] = temp;
        }
    }

    return 1;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer + 1 < length) {
            printf(" ");
        }
    }
}
