#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[1][30];
    
    printf("Informe o nome: ");
    for(int i = 0; i < 1; i++) {
        fgets(nome[i], sizeof(nome[i]), stdin);
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%s", nome[i]);
    }

    return 0;
}