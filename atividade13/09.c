#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[30];

    printf("Informe um nome: ");
    fgets(nome, sizeof(nome), stdin);

    if (nome[0] == 'A' || nome[0] == 'a') {
        printf("%s", nome);
    }
    
    return 0;
}