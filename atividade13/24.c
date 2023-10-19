/* 24. Escreva um programa que recebe do usuário uma string S, um caractere C, e uma posição I e
devolve o índice da primeira posição da string onde foi encontrado o caractere C. A procura deve
começar a partir da posição I. */

#include <stdio.h>
#include <string.h>

int main() {

    char S[101];
    char C;

    int I, encontrado = -1;

    printf("Informe uma string: ");
    fgets(S, sizeof(S), stdin);

    printf("Informe o caractere a ser buscado: ");
    scanf(" %c", &C);

    printf("Informe a partir de qual posição deve começar a busca: ");
    scanf("%d", &I);

    for (int i = I; i < strlen(S); i++) {
        if (S[i] == C) {
            encontrado = i - I;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Caractere não encontrado.");
    } else {
        printf("O caractere foi encontrado no índice %d", encontrado);
    }
    

    return 0;
}