#include <stdio.h>

void scanMatriz(int alvo, int linha, int coluna, int matriz[linha][coluna]) {
    int encontrado = 0;
    int line = -1;
    int col = -1;
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            if (matriz[i][j] == alvo) {
                encontrado = 1;
                line = i;
                col = j;
            }
        }
        if (encontrado) {
            break;
        }
    }
    if (encontrado != 0) {
        printf("Número alvo encontrado na posição [%d][%d].\n", line, col);

    } else {
        printf("Número alvo não encontrado.");
    }
}
void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main(){

    int linha = 5;
    int coluna = 5;
    int alvo = 11;

    //matriz[LINHA][COLUNA]
    int matriz[5][5] = 
    {
        {1,2,3,11,14},
        {4,5,6,12,15},
        {7,8,9,13,16}
    };
    scanMatriz(alvo, linha, coluna, matriz);
    
    printMatriz(linha, coluna, matriz);
    return 0;

}