#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[30];
    
    printf("Informe o nome: ");
    fgets(nome, sizeof(nome), stdin);
    

    printf("\n");

    for (int i = 0; i < 4; i++) {
        printf("%c", nome[i]);
    }

    return 0;
}