#include <stdio.h>
int encontrarMaior(int vetor[]){
    int maior = vetor[0];

    for (int i = 0; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int main () {

    int maior, vetor[10];

    for (int i = 0; i < 10; i++) {

        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", &vetor[i]);

    }

    maior = encontrarMaior(vetor);
    printf("O maior valor informado é: %d", maior);

    return 0;
}