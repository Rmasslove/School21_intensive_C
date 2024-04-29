/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
double search(int *a, int n, double m, double v);
void output(int s);

int main() {
    int n, data[NMAX];
    int flag;
    flag = input(data, &n);
    if (flag == 1) {
        double m = mean(data, n);
        double v = variance(data, n);
        double s = search(data, n, m, v);
        output(s);
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

double mean(int *a, int n) {
    double mean = 0;
    for (int *p = a; p - a < n; p++) {
        mean = mean + (*p);
    }
    mean = (double)mean / (double)n;
    return mean;
}

double variance(int *a, int n) {
    double mean = 0;
    double vari = 0;
    for (int *p = a; p - a < n; p++) {
        mean = mean + (*p);
    }
    mean = (double)mean / (double)n;
    for (int *p = a; p - a < n; p++) {
        vari = vari + pow(*p - mean, 2);
    }
    vari = (double)vari / (double)n;

    return vari;
}

double search(int *a, int n, double m, double v) {
    int result;
    double c = m + 3 * sqrt(v);
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= m && *p <= c && *p != 0) {
            result = *p;
            break;
        } else {
            result = 0;
        }
    }
    return result;
}

void output(int s) { printf("%d\n", s); }
