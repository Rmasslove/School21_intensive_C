#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input(int **a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int *data;
    int len;
    if (input(&data, &len) == -1) return 0;
    sort(data, len);
    output(data, len);
    free(data);
    return 0;
}

int input(int **a, int *n) {
    char temp;
    if (scanf("%d%c", n, &temp) != 2 || temp != '\n') {
        printf("n/a");
        return -1;
    }
    *a = (int *)calloc(*n, sizeof(int));
    if (!*a) {
        printf("n/a");
        return -1;
    }
    for (int *p = *a; p - *a < *n; p++) {
        if (scanf("%d%c", p, &temp) != 2 || temp != ' ') {
            if (p - *a == *n - 1 && temp == '\n') break;
            printf("n/a");
            return -1;
        }
    }
    if (temp != '\n') {
        printf("n/a");
        return -1;
    }
    return 0;
}

void sort(int *a, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
}
