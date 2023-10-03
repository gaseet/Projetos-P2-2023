#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matrizElementoMaiorEntre(int linha, int coluna, int matriz1[linha][coluna], 
    int matriz2[linha][coluna], int matrizResultado[linha][coluna]) {

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (matriz1[i][j] > matriz2[i][j]) {
                matrizResultado[i][j] = matriz1[i][j];
            } else {
                matrizResultado[i][j] = matriz2[i][j];
            }
        }
    }
}

int main() {

    int linha = 4;
    int coluna = 4;

    int matriz1[4][4] = 
        {
            {1,2,3,11},
            {4,5,6,11},
            {7,8,9,11},
            {10,12,13,14}
        };

    int matriz2[4][4] = 
        {
            {1,2,3,11},
            {4,5,6,11},
            {7,8,9,11},
            {20,12,13,14}
        };

    int matrizResultado[4][4];

    matrizElementoMaiorEntre(linha, coluna, matriz1, matriz2, matrizResultado);
    printMatriz(linha, coluna, matrizResultado);
    
    return 0;
}
