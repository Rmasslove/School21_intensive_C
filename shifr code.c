#include <stdio.h>
#include <stdlib.h>

int main() {
    char plaintext[100], ciphertext[100];
    int key, i;

    printf("Введите текст для шифрования: ");
    fgets(plaintext, 100, stdin);

    printf("Введите ключ шифрования (целое число от 0 до 25): ");
    scanf("%d", &key);

    for(i = 0; plaintext[i] != '\0'; i++) {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = plaintext[i] + key;
            if(ciphertext[i] > 'z') {
                ciphertext[i] -= 'z' - 'a' + 1;
            }
        }
        else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = plaintext[i] + key;
            if(ciphertext[i] > 'Z') {
                ciphertext[i] -= 'Z' - 'A' + 1;
            }
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    return 0;
}
