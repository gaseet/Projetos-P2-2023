#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int matrizSomaAcimaDiagonal(int linha, int coluna, int matriz[linha][coluna]) {
    int soma = 0;
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            if(i < j) {
                soma += matriz[i][j];
            }
        }
    }
    return soma;
}

int main(){

    int linha = 3;
    int coluna = 3;
    int soma;

    //matriz[LINHA][COLUNA]
    int matriz[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}

    };

    soma = matrizSomaAcimaDiagonal(linha, coluna, matriz);
    printf("%d\n", soma);

    printMatriz(linha, coluna, matriz);

    return 0;
}