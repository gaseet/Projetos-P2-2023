#include <stdio.h>
#include <stdlib.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matrizAoQuadrado(int linha, int coluna, int matriz1[linha][coluna], int matrizResultado[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            matrizResultado[i][j] = 0;
            for (int k = 0; k < coluna; k++) {
                matrizResultado[i][j] += matriz1[i][k] * matriz1[k][j];
            }
        }
    }
}

int main(){
    int linha = 3;
    int coluna = 3;
    int matrizResultado[3][3] = {0};
    int matriz1[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}

    };

    matrizAoQuadrado(linha, coluna, matriz1, matrizResultado);
    printMatriz(linha, coluna, matrizResultado);



    return 0;
}
