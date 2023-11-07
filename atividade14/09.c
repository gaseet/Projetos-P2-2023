#include <stdio.h>
#include <stdlib.h>

int buscarNum(int *matriz, int linha, int coluna, int busca) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if(matriz[i * coluna + j] == busca) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    
    int linha, coluna;

    printf("Informe a quantidade de linhas da matriz: ");
    scanf("%d", &linha);
    getchar();

    printf("Informe a quantidade de colunas da matriz: ");
    scanf("%d", &coluna);
    getchar();

    int *matriz = (int *)malloc(linha * coluna * sizeof(int));

    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < linha * coluna; i++) {
        printf("Informe o número [%d][%d]\n", i / coluna, i % coluna);
        scanf("%d", &matriz[i]);
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i * coluna + j]);
        }
        printf("\n");
    }

    int numeroBusca, encontrado = 0;

    printf("Informe o número a ser buscado: \n");
    scanf("%d", &numeroBusca);

    encontrado = buscarNum(matriz, linha, coluna, numeroBusca);

    if (encontrado == 1) {
        printf("Número encontrado na matriz.");
    } else {
        printf("Número NÃO encontrado na matriz.");
    }

    free(matriz);
    matriz = NULL;
    
    return 0;
}
