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

    int contMult = 0, mult = 0;
    printf("Informe o número a verificar se existem múltiplos: ");
    scanf("%d", &mult);
    
    printf("Digite %d números inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
        if (numeros[i] %mult == 0) {
            contMult++;
        }
    }

    printf("O vetor lido foi: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("%d números são múltipos de %d.", contMult, mult);

    free(numeros);
    numeros = NULL;
    
    return 0;
}
