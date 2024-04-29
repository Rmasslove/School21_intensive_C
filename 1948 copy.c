#include <stdio.h>

int primeNumber(int y) {
    int u = y - 1;
    while (u > 1) {
        int r = y;
        while (r > 0) {
            r = r - u;
            if (r == 0) {
                return 0;
            }
        }
        u = u - 1;
    }
    return 1;
}

int decreaseF(int r, int x) {
    while (x > 0) {
        x = x - r;
        if (x == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int x;
    char lastChar;

    if (scanf("%d%c", &x, &lastChar) != 2 || lastChar != '\n') {
        printf("n/a");
        return -1;
    }

    if (x == 0 || x == 1 || x == -1) {
        printf("n/a");
        return -1;
    }

    if (x < 0) {
        x = x * -1;
    }

    int flag = x;
    int r = 0;
    while (x > 2) {
        x = x - 1;
        r = primeNumber(x);
        if (r == 1) {
            int t = 0;
            t = decreaseF(x, flag);
            if (t == 1) {
                flag = x;
                break;
            }
        }
    }

    printf("%d", flag);

    return 0;
}
