#include <stdio.h>

int main() {

    int produto = 1, i = 1;

    while (i <= 5) {
        produto *= i;
        i++;
    }
    printf("O produto dos números de 1 a 5 é: %d", produto);
    return 0;
}
