#include <stdio.h>
#include <stdlib.h> // Include this header file for rand()

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void somarMatrizes(int linha, int coluna, int matriz1[linha][coluna], int matriz2[linha][coluna],
 int matrizResultado[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            matrizResultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void subtrairMatrizes(int linha, int coluna, int matriz1[linha][coluna], int matriz2[linha][coluna],
 int matrizResultado[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            matrizResultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void addConstante(int constante, int linha, int coluna, int matriz1[linha][coluna], int matriz2[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            matriz1[i][j] += constante;
            matriz2[i][j] += constante;
        }
    }
}

int main(){

    int opcao = 0;
    int linha = 2;
    int coluna = 2;
    int matrizResultado[2][2] = {0};
    int matriz1[2][2] = 
    {
        {1,2},
        {3,4}
    };

    int matriz2[2][2] = 
    {
        {5,6},
        {7,8}
    };

    printf("Escolha uma opção:\n");
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Adicionar constante a matrizes\n");
    printf("4 - Imprimir matrizes\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        somarMatrizes(linha, coluna, matriz1, matriz2, matrizResultado);
        printMatriz(linha, coluna, matrizResultado);
    } else if (opcao == 2) {
        subtrairMatrizes(linha, coluna, matriz1, matriz2, matrizResultado);
        printMatriz(linha, coluna, matrizResultado);
    } else if (opcao == 3) {
        int constante;
        printf("Informe a constante a ser adicionada: ");
        scanf("%d", &constante);
        addConstante(constante, linha, coluna, matriz1, matriz2);
        printMatriz(linha, coluna, matriz1);
        printf("\n");
        printMatriz(linha, coluna, matriz2);
    } else if (opcao == 4) {
        printMatriz(linha, coluna, matriz1);
        printMatriz(linha, coluna, matriz2);
    } else {
        printf("Opção inválida");
    }

    return 0;
}
