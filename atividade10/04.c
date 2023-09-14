#include <stdio.h>

int encontrarPosMaior(int vetor[]){
    int maior = vetor[0];
    int pos = 0;

    for (int i = 0; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            pos = i;
        }
    }
    return pos;
}

int encontrarPosMenor(int vetor[]){
    int menor = vetor[0];
    int pos = 0;

    for (int i = 0; i < 10; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            pos = i;
        }
    }
    return pos;
}

int main () {

    int posMaior, posMenor, vetor[10];

    for (int i = 0; i < 10; i++) {

        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", &vetor[i]);

    }

    posMaior = encontrarPosMaior(vetor);
    posMenor = encontrarPosMenor(vetor);
    printf("O a posição no array do maior valor informado é: %d\n", posMaior);
    printf("O a posição no array do menor valor informado é: %d", posMenor);

    return 0;
}