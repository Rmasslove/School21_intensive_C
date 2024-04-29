#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int input(int *length);
int inputXY(int *lengthX, int *lengthY);
int staticArr(int dataStatic[][LEN], int lengthX, int lengthY);
// int singleArrM(int ***single_array_matrix, int M, int N);
void output(int length, int lengthX, int lengthY);

int main() {
    int length, lengthX, lengthY;
    int dataStatic[LEN][LEN];
    int flag;

    flag = input(&length);

    if (flag == 1) {
        flag = inputXY(&lengthX, &lengthY);
    }

    if (flag == 1) {
        if (length == 1) {
            int r = staticArr(dataStatic, lengthX, lengthY);
            output(length, lengthX, lengthY);
            if (r == 1) {
                free(dataStatic);
            }
        }
    }

    return 0;
}

int input(int *length) {
    int flag = 1;
    char lastChar;
    if ((scanf("%d%c", length, &lastChar) == 2 && lastChar == '\n') && (*length > 0 && *length <= 4)) {
        flag = 1;
    } else {
        printf("n/a");
        flag = 0;
    }
    return flag;
}

int inputXY(int *lengthX, int *lengthY) {
    int flag = 1;
    char lastChar;
    if ((scanf("%d%d%c", lengthX, lengthY, &lastChar) == 3 && lastChar == '\n') &&
        (*lengthX > 0 && *lengthX <= LEN) && (*lengthY > 0 && *lengthY <= LEN)) {
        flag = 1;
    } else {
        printf("n/a");
        flag = 0;
    }
    return flag;
}

int staticArr(int dataStatic[][LEN], int lengthX, int lengthY) {
    for (int i = 0; i < lengthX; i++) {
        for (int j = 0; j < lengthY; j++) {
            dataStatic[i][j] = j;
        }
    }
    return 1;
}

// int singleArrM(int ***single_array_matrix, int M, int N) {
//     int **single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int *));
//     int *ptr = (int *)(single_array_matrix + M);
//     int count = 0;

//     for (int i = 0; i < M; i++) {
//         single_array_matrix[i] = ptr + N * i;
//     }
//     for (int i = 0; i < M; i++) {
//         for (int j = 0; j < N; j++) {
//             single_array_matrix[i][j] = ++count;
//         }
//     }
//     for (int i = 0; i < M; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d ", single_array_matrix[i][j]);
//         }
//     }
//     return 1;
// }

void output(int length, int lengthX, int lengthY) { printf("%d%d%d", length, lengthX, lengthY); }
