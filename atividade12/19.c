/* 
19. Faça um programa que leia uma matriz 3 x 6 com valores reais.
a. Imprima a soma de todos os elementos das colunas ímpares. (SEPARADAMENTE)
b. Imprima a média aritmética dos elementos da segunda e quarta colunas.
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
        int soma = 0;
        for (int i = 0; i < linha; i++) {
            if (j % 2 == 0){    
                soma += matriz[i][j];
            }
        }
        if (j % 2 == 0){    
                printf("Soma da coluna %d: %d\n", j+1, soma);
            }  
    }
}

int main() {
    int soma = 0;
    int linha = 3;
    int coluna = 6;
    int matriz[3][6] = {

        {1, 2, 3, 4, 5, 0},
        {1, 2, 3, 4, 5, 0},
        {1, 2, 3, 4, 5, 0},

    };
    somaColunasImpares(linha, coluna, matriz);
    printf("%d", soma);

    return 1;
}