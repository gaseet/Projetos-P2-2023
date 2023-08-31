#include <stdio.h>

int main() {
    int menorImparPositivo = -1;
    int num;

    while (1) {
        printf("Informe um número inteiro (0 para encerrar): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num > 0 && num % 2 != 0 && (menorImparPositivo == -1 || num < menorImparPositivo)) {
            menorImparPositivo = num;
        }
    }

    if (menorImparPositivo != -1) {
        printf("O menor valor positivo e ímpar digitado é: %d\n", menorImparPositivo);
    } else {
        printf("Nenhum valor positivo e ímpar foi inserido.\n");
    }

    return 0;
}
