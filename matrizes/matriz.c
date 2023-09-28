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

    int linha = 3;
    int coluna = 3;

    //matriz[LINHA][COLUNA]
    int matriz[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    printMatriz(linha, coluna, matriz);

    return 0;
}