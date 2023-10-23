#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


int main(){

    int linha = 5;
    int coluna = 4;

    int matriz[5][4];

    for (int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            printf("Insira o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printMatriz(linha, coluna, matriz);

    return 0;
}