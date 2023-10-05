/* 
19. Faça um programa que leia uma matriz 3 x 6 com valores reais.
c. Substitua os valores da sexta coluna pela soma dos valores das colunas 1 e 2.
d. Imprima a matriz modificada. 
*/
#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void somaColunasImpares(int linha, int coluna, int matriz[linha][coluna]) {
    for (int j = 0; j < coluna; j++) {
        int alvo1 = 1  - 1;
        int alvo2 = 2  - 1;
        int soma = 0;

        for (int i = 0; i < linha; i++) {  
            soma += matriz[i][j];
        }

        if (j % 2 == 0){    
            printf("Soma da coluna %d: %d\n", j+1, soma);
        }  
    }
}

void mediaAritmetica(int linha, int coluna, int matriz[linha][coluna]) {
    float media = 0;
    int alvo1 = 2   - 1;
    int alvo2 = 4   - 1;

   for (int j = 0; j < coluna; j++) {
        int soma = 0;
        int media = 0;
        for (int i = 0; i < linha; i++) {  
            soma += matriz[i][j];
        }
        if (j == alvo1 || j == alvo2){   
            media = soma / linha;
            printf("Media da coluna %d: %d\n", j+1, media);
            }  
    }
}

void substituirColuna(int linha, int coluna, int matriz[linha][coluna]) { 

    for (int i = 0; i < linha; i++) {
        matriz[i][5] = matriz[i][0] + matriz[i][1];
    }

}

int main() {

    int linha = 3;
    int coluna = 6;
    int matriz[3][6] = {

        {1, 2, 3, 4, 5, 0},
        {1, 2, 3, 4, 5, 0},
        {1, 2, 3, 4, 5, 0},

    };
    somaColunasImpares(linha, coluna, matriz);
    mediaAritmetica(linha, coluna, matriz);
    substituirColuna(linha, coluna, matriz);
    printMatriz(linha, coluna, matriz);

    return 0;
}