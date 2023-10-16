#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[30];

    printf("Informe um nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("%s", strrev(nome));

    return 0;
}