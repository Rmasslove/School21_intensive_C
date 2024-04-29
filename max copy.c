#include <stdio.h>

int main() {
    float fa, fb;

    if (scanf("%f%f", &fa, &fb) != 2) {
        printf("n/a");
        return -1;
    }

    int a = fa;
    int b = fb;

    if (a != fa || b != fb) {
        printf("n/a");
        return -1;
    }
    if (a > b) {
        printf("%d", a);
    } else {
        printf("%d", b);
    }
    return 0;
}
