#include <stdio.h>

int main() {

    int soma = 0, i = 0;

    while (i <= 100) {
        soma += i;
        i++;
    }
    printf("A soma dos números de 1 a 100 é: %d", soma);
    return 0;
}
