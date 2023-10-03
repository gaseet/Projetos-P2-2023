#include <stdio.h>

int scanMatriz(int alvo, int linha, int coluna, int matriz[linha][coluna]) {
    int encontrados = 0;
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            if (matriz[i][j] > alvo) {
                encontrados++;
            }
        }
    }
    return encontrados;
}

int main(){

    int linha = 4;
    int coluna = 4;
    int alvo = 10;

    //matriz[LINHA][COLUNA]
    int matriz[4][4] = 
    {
        {1,2,3,11},
        {4,5,6,11},
        {7,8,9,11}
    };
    int maiorQue10 = scanMatriz(alvo, linha, coluna, matriz);

    printf("Foram encontrados %d elementos maiores que %d na matriz.", maiorQue10, alvo);
    return 0;

}