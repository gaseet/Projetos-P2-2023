#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matrizMaiorElemento(int linha, int coluna, int matriz[linha][coluna]) {
    int maior = -1;
    int line = -1;
    int col = -1;
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                line = i;
                col = j;
            }
        }
    }
    printf("O maior valor foi encontrado na posição [%d][%d].\n", line, col);
}

int main(){

    int linha = 4;
    int coluna = 4;

    //matriz[LINHA][COLUNA]
    int matriz[4][4] = 
        {
            {1,2,3,11},
            {4,5,6,11},
            {7,8,9,11}
        };

    matrizMaiorElemento(linha, coluna, matriz);

    printMatriz(linha, coluna, matriz);

    return 0;
}