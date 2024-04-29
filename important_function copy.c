#include <math.h>
#include <stdio.h>

float form(float x) {
    x = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) - x * pow((10 + x), (2 / x)) -
        1.01;
    return x;
}

int main() {
    float x;

    if (scanf("%f", &x) != 1) {
        printf("n/a");
        return -1;
    }

    x = form(x);
    printf("%.1f", x);

    return 0;
}
