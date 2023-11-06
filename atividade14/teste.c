#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alocarString(int tamanho) {
    char* string = (char*)malloc((tamanho + 1) * sizeof(char));
    return string;
}

void removerVogais(char* string) {
    char* resultado = string;
    char* p = string;

    while (*p != '\0') {
        if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u' &&
            *p != 'A' && *p != 'E' && *p != 'I' && *p != 'O' && *p != 'U') {
            *resultado = *p;
            resultado++;
        }
        p++;
    }
    *resultado = '\0';
}

int main() {
    int tamanho;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("O tamanho deve ser um número positivo.\n");
        return 1;
    }

    char* minhaString = (char*)malloc((tamanho + 1) * sizeof(char));

    if (minhaString == NULL) {
        printf("Erro ao alocar memória para a string.\n");
        return 1;
    }

    printf("Digite a string: ");
    getchar();
    fgets(minhaString, tamanho + 1, stdin);

    removerVogais(minhaString);

    printf("String sem vogais: %s\n", minhaString);

    free(minhaString);

    return 0;
}
