#include <stdio.h>

int encontrarMenor(int vetor[]) {
    int menor = vetor[0];

    for (int i = 1; i < 10; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    return menor;
}

int main() {
    int menor, vetor[10];

    for (int i = 0; i < 10; i++) {
        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    menor = encontrarMenor(vetor);
    printf("O menor valor informado é: %d", menor);

    return 0;
}
