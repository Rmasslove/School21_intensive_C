#include <stdio.h>

int sum(int a, int b) { return (a + b); }

int sub(int a, int b) { return (a - b); }

int mul(int a, int b) { return (a * b); }

int divis(int a, int b) { return (a / b); }

int main() {
    float fa, fb;

    int rs, rm, ru, rd;

    scanf("%f%f", &fa, &fb);

    int a = fa;
    int b = fb;

    if (a != fa || b != fb) {
        printf("n/a");
        return -1;
    }

    rs = sum(a, b);
    rm = sub(a, b);
    ru = mul(a, b);
    if (b == 0) {
        printf("%d %d %d n/a", rs, rm, ru);
        return -1;
    }
    rd = divis(a, b);

    printf("%d %d %d %d", rs, rm, ru, rd);

    return 0;
}
