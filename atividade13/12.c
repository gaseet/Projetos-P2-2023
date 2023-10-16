#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[30];
    char sub;
    int i = 0, vogais = 0;

    printf("Informe um nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Informe uma letra para substituir as vogais: ");
    sub = getchar();

    while (nome[i]) {
        if (nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i'
         || nome[i] == 'o' || nome[i] == 'u') {
            nome[i] = sub;
            vogais++;
         }
        i++;
    }

    printf("%s", nome);

    return 0;
}