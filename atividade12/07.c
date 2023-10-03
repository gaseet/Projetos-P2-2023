#include <stdio.h>
#include <math.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void gerarMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            if (i < j) {
                matriz[i][j] = 2 * i + 7 * j;
            } else if (i == j){
                matriz[i][j] = 3 * pow(i,2);
            } else {
                matriz[i][j] = 5 * pow(j,2) + 1;
            }
        }
    }
}

int main(){

    int linha = 10;
    int coluna = 10;

    //matriz[LINHA][COLUNA]
    int matriz[10][10];

    gerarMatriz(linha, coluna, matriz);

    printMatriz(linha, coluna, matriz);

    return 0;
}