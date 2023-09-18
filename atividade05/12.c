#include <stdio.h>

int main() {
    int numero;
    int total = 0;
    int count = 1;

    while (1) {
        printf("Digite o %d número inteiro (-1 para sair): ", count);
        scanf("%d", &numero);

        if (numero == -1) {
            break;
        }

        total += numero;
        count++;
    }

    if (count > 0) {
        float media = (float) total / (count - 1);
        printf("A média dos números digitados é: %.2f\n", media);
    } else {
        printf("Nenhum número foi digitado.\n");
    }

    return 0;
}
