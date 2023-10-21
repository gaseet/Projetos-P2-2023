#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[30];
    int tamanho = 0;
    int i = 0;

    printf("Informe o nome: ");
    fgets(nome, sizeof(nome), stdin);

    while (nome[i]) {
        tamanho++;
        i++;
    }
    
    printf("%d", tamanho - 1);

    return 0;
}