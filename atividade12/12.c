#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matrizTransposta(int linha, int coluna, int matriz1[linha][coluna], 
int matrizResultado[linha][coluna]) {

    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            matrizResultado[i][j] = matriz1[j][i];
        }
    }
}

int main(){

    int linha = 3;
    int coluna = 3;
    int soma;
    int matrizTranspo[3][3];

    //matriz[LINHA][COLUNA]
    int matriz[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}

    };

    matrizTransposta(linha, coluna, matriz, matrizTranspo);

    printMatriz(linha, coluna, matriz);
    printf("\n");
    printMatriz(linha, coluna, matrizTranspo);

    return 0;
}