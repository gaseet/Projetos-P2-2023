#include <stdio.h>

int encontrarRepetido(int vetor[]){
    int duplica = 0, maior = vetor[0];

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (vetor[i] == vetor[j]) {
                printf("O valor %d está repetido.\n", vetor[i]);
                duplica = 1;
            }
        }
    }
    return duplica;
}

int main () {

    int duplica, vetor[10];

    for (int i = 0; i < 10; i++) {

        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", &vetor[i]);

    }

    duplica = encontrarRepetido(vetor);
    if (duplica == 0) {
        printf("Nenhuma duplica foi encontrada.");
    }

    return 0;
}