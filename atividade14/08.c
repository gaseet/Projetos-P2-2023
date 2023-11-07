#include <stdio.h>
#include <stdlib.h>

int main() {
    int* vetor = NULL;
    int tamanho = 0;
    int numero;

    while (1) {
        printf("Digite um numero (ou um numero negativo para sair): ");
        scanf("%d", &numero);

        if (numero < 0) {
            break;
        }

        tamanho++;
        vetor = (int*)realloc(vetor, tamanho * sizeof(int));

        if (vetor == NULL) {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }

        vetor[tamanho - 1] = numero;
    }

    printf("\nValores lidos:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);  // Libera a memória alocada
    return 0;
}
