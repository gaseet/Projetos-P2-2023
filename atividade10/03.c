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

int main () {

    int pos, vetor[10];

    for (int i = 0; i < 10; i++) {

        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", &vetor[i]);

    }

    pos = encontrarPosMaior(vetor);
    printf("O a posição no array do maior valor informado é: %d", pos);

    return 0;
}