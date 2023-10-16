#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[30] = "Teste";
    int tamanho = 0;

    for (int i = 0; i < 30; i++) {
        if (nome[i]) {
            tamanho++;
        }
    }

    printf("%d", tamanho);

    return 0;
}