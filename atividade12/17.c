#include <stdio.h>

void calcularSomaLinhas(int matriz[3][3], int somaColunas[3]) {
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 3; i++) {
            somaColunas[j] += matriz[i][j];
        }
    }
}

int main(){

    int linha = 3;
    int coluna = 3;
    int somaColunas[3] = {0};

    //matriz[LINHA][COLUNA]
    int matriz[3][3] = 
    {
        {1,2,3},
        {0,2,3},
        {0,2,3}

    };

    calcularSomaLinhas(matriz, somaColunas);

    printf("Soma das colunas:\n");
    for(int i = 0; i < 3; i++) {
        printf("Coluna %d: %d\n", i+1, somaColunas[i]);
    }

    return 0;
}