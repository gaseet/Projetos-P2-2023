#include <stdio.h>
#include <string.h>

int main() {
    
    char nome[3][30];
    char junto[100];
    
    for(int i = 0; i < 3; i++) {
        fgets(nome[i], sizeof(nome[i]), stdin);
        /* nome[i][strcspn(nome[i], "\n")] = 0; //remover \n */
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%s", nome[i]);
    }

    return 0;
}