#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void notaFinal(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        int soma = 0;
        for(int j = 1; j < coluna - 1; j++) {
            soma += matriz[i][j];
        }
        matriz[i][coluna - 1] = soma;
    }
}

void maiorNotaFinal(int linha, int coluna, int matriz[linha][coluna]) {
    int maior = matriz[0][coluna-1];
    int matricula = 0;
    for (int i = 0; i < linha; i++){
        if (matriz[i][coluna-1] > maior) {
            maior = matriz[i][coluna-1];
            matricula = matriz[i][0];
        }
    }
    printf("A matrícula do aluno com a maior nota final é: %d", matricula);
}

int main(){

    int linha = 5;
    int coluna = 4;
    int soma;

    //matriz[LINHA][COLUNA]
    int matriz[5][4] = 
    /*  
        Primeira coluna: número de matrícula;
        Segunda coluna: média das provas;
        Terceira coluna: média dos trabalhos;
        Quarta coluna: nota final.
    */
    {
        {1,  7, 9,  0},
        {2,  8, 9,  0},
        {3,  6, 20, 0},
        {4,  8, 7,  0},
        {5, 10, 10, 0}

    };

    notaFinal(linha, coluna, matriz);
    printMatriz(linha, coluna, matriz);
    maiorNotaFinal(linha, coluna, matriz);

    return 0;
}