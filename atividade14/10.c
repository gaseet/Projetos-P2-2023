#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int linha, coluna;

    printf("Informe a quantidade de linhas da matriz: ");
    scanf("%d", &linha);
    getchar();

    printf("Informe a quantidade de colunas da matriz: ");
    scanf("%d", &coluna);
    getchar();

    float *matriz = (float *)malloc(linha * coluna * sizeof(float));

    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < linha * coluna; i++) {
        printf("Informe o número [%d][%d]\n", i / coluna, i % coluna);
        scanf("%f", &matriz[i]);
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%.3f ", matriz[i * coluna + j]);
        }
        printf("\n");
    }


    free(matriz);
    matriz = NULL;
    
    return 0;
}
