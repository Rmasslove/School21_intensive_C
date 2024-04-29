#include <stdio.h>

#define N 15
#define M 13

void transform(int buf[N][M], int **matr, int n);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void draw_sun(int sun_data[6][5], int **picture);
void output(int **picture, int n, int m);
void draw_trunk(int tree_foliage[], int **picture);
void draw_tree(int tree_trunk[], int **picture);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(picture_data, picture, N);

    make_picture(picture, N, M);
    output(picture, N, M);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    draw_sun(sun_data, picture);
    draw_tree(tree_foliage, picture);
    draw_trunk(tree_trunk, picture);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[7][i] = frame_w[i];
        picture[14][i] = frame_w[i];
    }
    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][6] = frame_h[i];
        picture[i][12] = frame_h[i];
    }
}

void draw_sun(int sun_data[6][5], int **picture) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[1 + i][7 + j] = sun_data[i][j];
        }
    }
}

void draw_tree(int tree_trunk[], int **picture) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            picture[3 + i][2 + j] = tree_trunk[j];
            picture[2 + j][3 + i] = tree_trunk[j];
        }
    }
}

void draw_trunk(int tree_foliage[], int **picture) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            picture[6 + i + j][3] = tree_foliage[j];
            picture[6 + i + j][4] = tree_foliage[j];
        }
    }
    for (int j = 0; j < 4; j++) {
        picture[10][2 + j] = tree_foliage[j];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int buf[N][M], int **matr, int n) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf[i];
    }
}

void output(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture[i][j]);
            if (j + 1 < m) printf(" ");
        }
        if (i + 1 < n) printf("\n");
    }
}
