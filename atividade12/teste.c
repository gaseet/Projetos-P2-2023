#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[5][5];
    int usado[25] = {0}; // Inicializa o vetor 'usado' com zeros
    srand(time(NULL));

    // Preenche a matriz
    for(int i = 0; i < 5; i++) {
        printf("i: %d\n", i);
        for(int j = 0; j < 5; j++) {
            printf("  j: %d\n", j);
            int numero;
            do {
                printf("    Inside do-while\n");
                numero = rand() % 20 + 1; // Gera um número aleatório de 1 a 20
            } while (usado[numero - 1]); // Verifica se o número já foi usado
            printf("    Got a valid number: %d\n", numero);
            usado[numero - 1] = 1; // Marca o número como usado
            matriz[i][j] = numero; // Atribui o número à matriz
        }
    }

    // Imprime a matriz
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
