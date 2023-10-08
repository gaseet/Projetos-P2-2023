#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[5][5];
    int usado[25] = {0};
    srand(time(NULL));

    for(int i = 0; i < 5; i++) {
        printf("i: %d\n", i);
        for(int j = 0; j < 5; j++) {
            printf("  j: %d\n", j);
            int numero;
            do {
                printf("    Inside do-while\n");
                numero = rand() % 99 + 1;
            } while (usado[numero - 1]);
            printf("    Got a valid number: %d\n", numero);
            usado[numero - 1] = 1;
            matriz[i][j] = numero;
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
