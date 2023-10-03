#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarCartela(int cartela[5][5]) {
    int numeros[25];
    for (int i = 0; i < 25; i++) {
        numeros[i] = i;
    }

    srand(time(NULL));
    for (int i = 24; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cartela[i][j] = numeros[i * 5 + j];
        }
    }
}

void exibirCartela(int cartela[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", cartela[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int cartela[5][5];
    gerarCartela(cartela);
    exibirCartela(cartela);

    return 0;
}