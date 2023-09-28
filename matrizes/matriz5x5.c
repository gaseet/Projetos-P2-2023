#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matrizDiagonal(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            if(i == j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

int main(){

    int linha = 5;
    int coluna = 5;

    //matriz[LINHA][COLUNA]
    int matriz[5][5];

    matrizDiagonal(linha, coluna, matriz);

    printMatriz(linha, coluna, matriz);

    return 0;
}