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

void transformaTriangularInferior(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = i+1; j < coluna; j++) {
            matriz[i][j] = 0;
        }
    }
}

int main(){

    int linha = 4;
    int coluna = 4;
    int matriz[linha][coluna];

    // Gerar matriz 4x4 com valores entre 1 e 20
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            matriz[i][j] = rand() % 20 + 1;
        }
    }

    printf("Matriz Original:\n");
    printMatriz(linha, coluna, matriz);
    printf("\n");

    transformaTriangularInferior(linha, coluna, matriz);

    printf("Matriz Transformada (Triangular Inferior):\n");
    printMatriz(linha, coluna, matriz);

    return 0;
}
