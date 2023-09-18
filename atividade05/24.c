#include <stdio.h>

int main() {
    int num;
    int primeiroNumero = 0;
    int ultimoNumero = 0;
    int countPares = 0;
    int countImpares = 0;

    while (1) {
        printf("Informe um número inteiro (0 para encerrar): ");
        scanf("%d", &num);

        if (num == 0) {
            if (primeiroNumero != 0) {
                int numeroAtual = primeiroNumero + 1;
                while (numeroAtual < ultimoNumero) {
                    if (numeroAtual % 2 == 0) {
                        countPares++;
                    } else {
                        countImpares++;
                    }
                    numeroAtual++;
                }

                printf("Total de números pares entre o primeiro e o último: %d\n", countPares);
                printf("Total de números ímpares entre o primeiro e o último: %d\n", countImpares);
            }
            break;
        }

        if (primeiroNumero == 0) {
            primeiroNumero = num;
        }
        ultimoNumero = num;
    }

    return 0;
}
