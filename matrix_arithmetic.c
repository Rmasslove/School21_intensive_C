#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int **matrix_result);
int transpose(int ***matrix, int **temp_arr, int *n, int *m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int **matrix_result);
int input_solo(int ***a, int *len_1, int *len_2);
int input_method_and_len(int *method);
void output(int **a, int len_1, int len_2);

int main() {
    int method;
    int len_1, len_2, len_3, len_4;
    if (input_method_and_len(&method) == -1) return 0;
    int **dynamic_arr_1;
    int **dynamic_arr_2;
    switch (method) {
        case 1:
            if (input_solo(&dynamic_arr_1, &len_1, &len_2) == -1) {
                return 0;
            }
            if (input_solo(&dynamic_arr_2, &len_3, &len_4) == -1) {
                return 0;
            }
            if (len_1 != len_3 || len_2 != len_4) {
                printf("n/a");
                return 0;
            }
            int **res_arr = (int **)malloc(len_1 * sizeof(int *));
            if (!res_arr) {
                printf("n/a");
                return -1;
            }
            for (int i = 0; i < len_1; i++) {
                res_arr[i] = (int *)malloc(len_2 * sizeof(int));
            }
            sum(dynamic_arr_1, len_1, len_2, dynamic_arr_2, res_arr);
            output(res_arr, len_1, len_2);
            for (int i = 0; i < len_1; i++) {
                free(dynamic_arr_2[i]);
            }
            free(dynamic_arr_2);
            for (int i = 0; i < len_1; i++) {
                free(res_arr[i]);
            }
            free(res_arr);
            for (int i = 0; i < len_1; i++) {
                free(dynamic_arr_1[i]);
            }
            free(dynamic_arr_1);
            break;
        case 2:
            if (input_solo(&dynamic_arr_1, &len_1, &len_2) == -1) {
                return 0;
            }
            if (input_solo(&dynamic_arr_2, &len_3, &len_4) == -1) {
                return 0;
            }
            res_arr = (int **)malloc(len_1 * sizeof(int *));
            if (!res_arr) {
                printf("n/a");
                return -1;
            }
            for (int i = 0; i < len_1; i++) {
                res_arr[i] = (int *)malloc(len_4 * sizeof(int));
            }
            if (len_2 != len_3) {
                printf("n/a");
                return -1;
            }
            mul(dynamic_arr_1, len_1, len_2, dynamic_arr_2, res_arr);
            output(res_arr, len_1, len_4);

            for (int i = 0; i < len_3; i++) {
                free(dynamic_arr_2[i]);
            }
            free(dynamic_arr_2);
            for (int i = 0; i < len_1; i++) {
                free(res_arr[i]);
            }
            free(res_arr);
            for (int i = 0; i < len_1; i++) {
                free(dynamic_arr_1[i]);
            }
            free(dynamic_arr_1);
            break;
        case 3:
            if (input_solo(&dynamic_arr_1, &len_1, &len_2) == -1) {
                return 0;
            }
            int **temp_arr = (int **)malloc(len_2 * sizeof(int *));
            for (int i = 0; i < len_2; i++) {
                temp_arr[i] = (int *)malloc(len_1 * sizeof(int));
            }
            transpose(&dynamic_arr_1, temp_arr, &len_1, &len_2);
            output(dynamic_arr_1, len_1, len_2);
            for (int i = 0; i < len_1; i++) {
                free(temp_arr[i]);
            }
            free(temp_arr);
            break;
    }
    return 0;
}

int input_method_and_len(int *method) {
    char temp1;
    if (scanf("%d%c", method, &temp1) != 2 || temp1 != '\n' || *method <= 0 || *method >= 4) {
        printf("n/a");
        return -1;
    }
    return 0;
}

int input_solo(int ***a, int *len_1, int *len_2) {
    char temp1, temp2;
    if (scanf("%d%c%d%c", len_1, &temp1, len_2, &temp2) != 4 || temp1 != ' ' || *len_1 <= 0 || *len_2 <= 0 ||
        temp2 != '\n') {
        printf("n/a");
        return -1;
    }
    char temp;
    *a = (int **)malloc(*len_1 * sizeof(int *));
    if (!a) {
        printf("n/a");
        return -1;
    }
    for (int i = 0; i < *len_1; i++) {
        (*a)[i] = (int *)malloc(*len_2 * sizeof(int));
    }
    for (int i = 0; i < *len_1; i++) {
        for (int j = 0; j < *len_2; j++) {
            if (scanf("%d%c", &((*a)[i][j]), &temp) != 2 || temp != ' ') {
                if (j + 1 == *len_2 && temp == '\n') {
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

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int **matrix_result) {
    for (int i = 0; i < n_first; i++) {
        for (int j = 0; j < m_first; j++) {
            matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    return 0;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int **matrix_result) {
    int sum;
    for (int i = 0; i < n_first; i++) {
        for (int k = 0; k < m_first; k++) {
            sum = 0;
            for (int j = 0; j < m_first; j++) {
                sum += matrix_first[i][j] * matrix_second[j][k];
            }
            matrix_result[i][k] = sum;
        }
    }
    return 0;
}

int transpose(int ***matrix, int **temp_arr, int *n, int *m) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            temp_arr[j][i] = (*matrix)[i][j];
        }
    }
    int temp = *n;
    *n = *m;
    *m = temp;
    for (int i = 0; i < *m; i++) {
        free((*matrix)[i]);
    }
    free((*matrix));
    (*matrix) = temp_arr;
    return 0;
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
