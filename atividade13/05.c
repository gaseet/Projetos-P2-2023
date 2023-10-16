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
    
    // - 1 para remover o caractere de quebra de linha contabilizado quando o usuário
    // aperta enter.
    
    printf("%d", tamanho - 1);

    return 0;
}