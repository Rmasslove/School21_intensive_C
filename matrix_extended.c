#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void output_menu();
int input_method_and_len(int *method, int *len_1, int *len_2);
int input_static(int **a, int len_1, int len_2);
int input_pointer(int ***a, int *b, int len_1, int len_2);
int input_two(int ***a, int **b, int len_1, int len_2);
int input_solo(int ***a, int len_1, int len_2);
void output(int *min_arr, int *max_arr, int **a, int len_1, int len_2);
void find_min(int **min_arr, int **dynamic_arr, int len_1, int len_2);
void find_max(int **max_arr, int **dynamic_arr, int len_1, int len_2);

int main() {
    output_menu();
    int method, len_1, len_2;
    input_method_and_len(&method, &len_1, &len_2);
    int arr[MAXSIZE][MAXSIZE];
    int *arr_ptrs[MAXSIZE];
    int **ptr;
    for (int i = 0; i < MAXSIZE; i++) {
        arr_ptrs[i] = arr[i];
    }
    ptr = arr_ptrs;
    int **dynamic_arr = NULL;
    int *values_arr = NULL;
    int *min_arr, *max_arr;
    switch (method) {
        case 1: {
            if (input_static(ptr, len_1, len_2) == -1) {
                printf("n/a");
                return 0;
            }
            find_min(&min_arr, ptr, len_1, len_2);
            find_max(&max_arr, ptr, len_1, len_2);
            output(min_arr, max_arr, ptr, len_1, len_2);
            break;
        }
        case 2: {
            if (input_pointer(&dynamic_arr, values_arr, len_1, len_2) == -1) {
                printf("n/a");
                return 0;
            }
            find_min(&min_arr, dynamic_arr, len_1, len_2);
            find_max(&max_arr, dynamic_arr, len_1, len_2);
            output(min_arr, max_arr, dynamic_arr, len_1, len_2);
            free(dynamic_arr);
            break;
        }
        case 3: {
            if (input_two(&dynamic_arr, &values_arr, len_1, len_2) == -1) {
                printf("n/a");
                return 0;
            }
            find_min(&min_arr, dynamic_arr, len_1, len_2);
            find_max(&max_arr, dynamic_arr, len_1, len_2);
            output(min_arr, max_arr, dynamic_arr, len_1, len_2);
            free(dynamic_arr);
            free(values_arr);
            break;
        }
        case 4: {
            if (input_solo(&dynamic_arr, len_1, len_2) == -1) {
                printf("n/a");
                return 0;
            }
            find_min(&min_arr, dynamic_arr, len_1, len_2);
            find_max(&max_arr, dynamic_arr, len_1, len_2);
            output(min_arr, max_arr, dynamic_arr, len_1, len_2);
            for (int i = 0; i < len_2; i++) {
                free(dynamic_arr[i]);
            }
            free(dynamic_arr);
            break;
        }
    }
    free(min_arr);
    free(max_arr);
}

void output_menu() {
    printf("Choose method:\n1 - Static array\n2 - Pointer array\n3 - Two arrays\n4 - One array\n");
}

int input_method_and_len(int *method, int *len_1, int *len_2) {
    char temp1, temp2;
    if (scanf("%d%c", method, &temp1) != 2 || temp1 != '\n' || *method <= 0 || *method >= 5) {
        printf("n/a");
        return -1;
    }
    if (*method == 1) {
        if (scanf("%d%c%d%c", len_1, &temp1, len_2, &temp2) != 4 || temp1 != ' ' || *len_1 > 100 ||
            *len_1 <= 0 || *len_2 > 100 || *len_2 <= 0 || temp2 != '\n') {
            printf("n/a");
            return -1;
        }
    } else {
        if (scanf("%d%c%d%c", len_1, &temp1, len_2, &temp2) != 4 || temp1 != ' ' || *len_1 <= 0 ||
            *len_2 <= 0 || temp2 != '\n') {
            printf("n/a");
            return -1;
        }
    }
    return 0;
}

int input_static(int **a, int len_1, int len_2) {
    char temp;
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            if (scanf("%d%c", &(a[i][j]), &temp) != 2 || temp != ' ') {
                if (j + 1 == len_2 && temp == '\n') {
                    break;
                }
                return -1;
            }
        }
        if (temp != '\n') return -1;
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
                return -1;
            }
        }
        if (temp != '\n') return -1;
    }
    return 0;
}

void output(int *min_arr, int *max_arr, int **a, int len_1, int len_2) {
    for (int i = 0; i < len_1; i++) {
        for (int j = 0; j < len_2; j++) {
            printf("%d", a[i][j]);
            if (j + 1 < len_2) printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < len_1; i++) {
        printf("%d", max_arr[i]);
        if (i + 1 < len_1) printf(" ");
    }
    printf("\n");
    for (int i = 0; i < len_2; i++) {
        printf("%d", min_arr[i]);
        if (i + 1 < len_2) printf(" ");
    }
}

void find_min(int **min_arr, int **dynamic_arr, int len_1, int len_2) {
    int min;
    *min_arr = (int *)malloc(len_2 * sizeof(int));
    // len_2 - horizontal_count
    for (int i = 0; i < len_2; i++) {
        min = dynamic_arr[0][i];
        for (int j = 1; j < len_1; j++) {
            if (dynamic_arr[j][i] < min) min = dynamic_arr[j][i];
        }
        (*min_arr)[i] = min;
    }
}

void find_max(int **max_arr, int **dynamic_arr, int len_1, int len_2) {
    int max;
    *max_arr = (int *)malloc(len_1 * sizeof(int));
    // len_1 - vertical_count
    for (int i = 0; i < len_1; i++) {
        max = dynamic_arr[i][0];
        for (int j = 1; j < len_2; j++) {
            if (dynamic_arr[i][j] > max) max = dynamic_arr[i][j];
        }
        (*max_arr)[i] = max;
    }
}
