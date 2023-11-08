#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = (int *)malloc(10 * sizeof(int));
    int tamanho_atual = 10;
    int contador = 0;
    int numero;

    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os números (digite 0 para encerrar):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (contador == tamanho_atual) {
            int *novo_vetor = (int *)malloc((tamanho_atual + 10) * sizeof(int));

            if (novo_vetor == NULL) {
                printf("Erro na alocação de memória.\n");
                free(vetor);
                return 1;
            }

            for (int i = 0; i < tamanho_atual; i++) {
                novo_vetor[i] = vetor[i];
            }

            free(vetor);
            vetor = novo_vetor;
            tamanho_atual += 10;
            free(novo_vetor);
        }

        vetor[contador] = numero;
        contador++;
    }

    printf("Vetor lido:\n");

    for (int i = 0; i < contador; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);
    vetor = NULL;

    return 0;
}
