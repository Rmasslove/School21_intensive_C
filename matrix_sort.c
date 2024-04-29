#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void output_menu();
int input_method_and_len(int *method, int *len_1, int *len_2);
int input_pointer(int ***a, int *b, int len_1, int len_2);
int input_two(int ***a, int **b, int len_1, int len_2);
int input_solo(int ***a, int len_1, int len_2);
void sort_arr(int **a, int len_1, int len_2);
void output(int **a, int len_1, int len_2);

int main() {
    output_menu();
    int method, len_1, len_2;
    input_method_and_len(&method, &len_1, &len_2);
    int **dynamic_arr = NULL;
    int *values_arr = NULL;
    switch (method) {
        case 1: {
            if (input_solo(&dynamic_arr, len_1, len_2) == -1) {
                return 0;
            }
            sort_arr(dynamic_arr, len_1, len_2);
            output(dynamic_arr, len_1, len_2);
            for (int i = 0; i < len_2; i++) {
                free(dynamic_arr[i]);
            }
            free(dynamic_arr);
            break;
        }
        case 2: {
            if (input_pointer(&dynamic_arr, values_arr, len_1, len_2) == -1) {
                return 0;
            }
            sort_arr(dynamic_arr, len_1, len_2);
            output(dynamic_arr, len_1, len_2);
            free(dynamic_arr);
            break;
        }
        case 3: {
            if (input_two(&dynamic_arr, &values_arr, len_1, len_2) == -1) {
                return 0;
            }
            sort_arr(dynamic_arr, len_1, len_2);
            output(dynamic_arr, len_1, len_2);
            free(dynamic_arr);
            free(values_arr);
            break;
        }
    }
}

void output_menu() { printf("Choose method:\n1 - One array\n2 - Pointer array\n3 - Two arrays\n"); }

int input_method_and_len(int *method, int *len_1, int *len_2) {
    char temp1, temp2;
    if (scanf("%d%c", method, &temp1) != 2 || temp1 != '\n' || *method <= 0 || *method >= 5) {
        printf("n/a");
        return -1;
    }
    if (scanf("%d%c%d%c", len_1, &temp1, len_2, &temp2) != 4 || temp1 != ' ' || *len_1 <= 0 || *len_2 <= 0 ||
        temp2 != '\n') {
        printf("n/a");
        return -1;
    }
    return 0;
}

int input_pointer(int ***a, int *b, int len_1, int len_2) {
    char temp;
    *a = (int **)malloc(len_1 * len_2 * sizeof(int) + len_1 * sizeof(int *));
    if (!a) {
        printf("n/a");
        return -1;
    }
    b = (int *)((*a) + len_1);
    if (!b) {
        printf("n/a");
        return -1;
    }
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            if (scanf("%d%c", &(b[j + i * len_1]), &temp) != 2 || temp != ' ') {
                if (j + 1 == len_2 && temp == '\n') {
                    break;
                }
                printf("n/a");
                return -1;
            }
        }
        if (temp != '\n') return -1;
    }
    for (int i = 0; i < len_1; i++) {
        (*a)[i] = b + len_2 * i;
    }
    return 0;
}

int input_two(int ***a, int **b, int len_1, int len_2) {
    char temp;
    *a = (int **)malloc(len_1 * sizeof(int *));
    if (!a) {
        printf("n/a");
        return -1;
    }
    *b = (int *)malloc(len_1 * len_2 * sizeof(int));
    if (!*b) {
        printf("n/a");
        return -1;
    }
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            if (scanf("%d%c", &((*b)[j + i * len_1]), &temp) != 2 || temp != ' ') {
                if (j + 1 == len_2 && temp == '\n') {
                    break;
                }
                printf("n/a");
                return -1;
            }
        }
        if (temp != '\n') return -1;
    }
    for (int i = 0; i < len_1; i++) {
        (*a)[i] = *b + len_2 * i;
    }
    return 0;
}

int input_solo(int ***a, int len_1, int len_2) {
    char temp;
    *a = (int **)malloc(len_1 * sizeof(int *));
    if (!a) {
        printf("n/a");
        return -1;
    }
    for (int i = 0; i < len_1; i++) {
        (*a)[i] = (int *)malloc(len_2 * sizeof(int));
    }
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            if (scanf("%d%c", &((*a)[i][j]), &temp) != 2 || temp != ' ') {
                if (j + 1 == len_2 && temp == '\n') {
                    break;
                }
                printf("n/a");
                return -1;
            }
        }
        if (temp != '\n') return -1;
    }
    return 0;
}

void sort_arr(int **a, int len_1, int len_2) {
    int temp_arr[len_1];
    int sum;
    int *temp_temp_arr;
    int temp;
    for (int i = 0; i < len_1; i++) {
        sum = 0;
        for (int j = 0; j < len_2; j++) {
            sum += a[i][j];
        }
        temp_arr[i] = sum;
    }
    for (int i = 0; i < len_1; i++) {
        for (int j = i; j < len_1; j++) {
            if (temp_arr[i] > temp_arr[j]) {
                temp_temp_arr = a[i];
                a[i] = a[j];
                a[j] = temp_temp_arr;
                temp = temp_arr[i];
                temp_arr[i] = temp_arr[j];
                temp_arr[j] = temp;
            }
        }
    }
}

void output(int **a, int len_1, int len_2) {
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            printf("%d", a[i][j]);
            if (j + 1 < len_2) printf(" ");
        }
        if (i + 1 < len_1) printf("\n");
    }
}
