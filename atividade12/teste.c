#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[5][5];
    int usado[99] = {0};
    int seed = 0;

    while (1) {
        srand(seed);

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                int numero;
                do {
                    numero = rand() % 100 + 1;
                } while (usado[numero - 1]);
                usado[numero - 1] = 1;
                matriz[i][j] = numero;
            }
        }

        int found_10 = 0;
        int found_100 = 0;

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if (matriz[i][j] == 10)
                    found_10 = 1;
                if (matriz[i][j] == 100)
                    found_100 = 1;
            }
        }

        if (found_10 && found_100) {
            printf("Found seeds: %d\n", seed);
            break;
        }

        // Reset variables and arrays for next iteration
        seed++;
        for (int i = 0; i < 99; i++) {
            usado[i] = 0;
        }
        printf("Trying seed: %d\n", seed); // Print seed value
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
