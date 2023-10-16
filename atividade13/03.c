#include <stdio.h>

int main() {
    
    char nome1[30] = "Teste";
    char nome2[30] = "Teste";

    int i = 0;
    int iguais = 1;

    while (nome1[i] || nome2[i]) {
        if (nome1[i] != nome2[i]) {
            iguais = 0;
            break;
        }
        i++;
    }

    if (iguais == 0) {
        printf("As strings são diferentes");
    } else if (iguais == 1) {
        printf("As strings são iguais");
    }

    return 0;
}