#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[30];
    int i = 0;

    printf("Informe um nome: ");
    fgets(nome, sizeof(nome), stdin);

    while (nome[i]) {
        if (nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i'
         || nome[i] == 'o' || nome[i] == 'u') {
            nome[i] = '0';
         }
        i++;
    }

    printf("%s", nome);

    return 0
}