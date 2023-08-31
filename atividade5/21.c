#include <stdio.h>

int main() {
    int count = 0;
    int num;

    while (1) {
        printf("Informe um número inteiro (0 para encerrar): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num > 99 || num < -99) {
            count++;
        }
    }

    printf("Quantidade de números com mais de três dígitos: %d\n", count);

    return 0;
}
