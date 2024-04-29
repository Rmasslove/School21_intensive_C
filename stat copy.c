#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int flag;
    flag = input(data, &n);
    if (flag == 1) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
    printf("\n");
}

int max(int *a, int n) {
    int max = 0;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }

    return max;
}
int min(int *a, int n) {
    int min = n;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }

    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d ", max_v);
    printf("%d ", min_v);
    printf("%.6f ", mean_v);
    printf("%f", variance_v);
}
