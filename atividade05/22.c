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

        if (num >= 50 && num <= 100) {
            soma += num;
            count++;
        }
    }

    if (count > 0) {
        float media = (float)soma / count;
        printf("A média dos números entre 50 e 100 é: %.2f\n", media);
    } else {
        printf("Nenhum número entre 50 e 100 foi inserido.\n");
    }

    return 0;
}
