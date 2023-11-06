#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    printf("Informe o tamanho do vetor a ser criado: ");
    scanf("%d", &tamanho);

    int *numeros = (int *)malloc(tamanho * sizeof(int));

    if (numeros == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1;
    }

    int contPar = 0, contImpar = 0;

    printf("Digite %d números inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
        if (numeros[i] %2 == 0) {
            contPar++;
        } else {
            contImpar++;
        }
    }

    printf("O vetor lido foi: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("%d números são ímpares e %d números são pares.", contImpar, contPar);

    free(numeros);

    return 0;
}
