#include <stdio.h>

int main() {
    int soma = 0;
    int count = 0;
    int num;

    while (1) {
        printf("Informe um número inteiro (0 para encerrar): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num % 3 == 0) {
            soma += num;
            count++;
        }
    }

    if (count > 0) {
        float media = (float)soma / count;
        printf("A média dos números divisíveis por 3 é: %.2f\n", media);
    } else {
        printf("Nenhum número divisível por 3 foi inserido.\n");
    }

    return 0;
}
