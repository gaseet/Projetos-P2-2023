#include <stdio.h>

void calcularSomaLinhas(int matriz[3][3], int somaLinhas[3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            somaLinhas[i] += matriz[i][j];
        }
    }
}

int main(){

    int linha = 3;
    int coluna = 3;
    int somaLinhas[3] = {0};

    //matriz[LINHA][COLUNA]
    int matriz[3][3] = 
    {
        {1,2,3},
        {0,2,3},
        {0,2,3}
    };

    calcularSomaLinhas(matriz, somaLinhas);

    printf("Soma das linhas:\n");
    for(int i = 0; i < 3; i++) {
        printf("Linha %d: %d\n", i+1, somaLinhas[i]);
    }

    return 0;
}
