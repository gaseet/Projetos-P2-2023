#include <stdio.h>
#include <string.h>

void inverterEsubstituir(char frase[]) {
    int tamanho = strlen(frase);

    for(int i = tamanho - 1; i >= 0; i--) {
        if(frase[i] == 'A' || frase[i] == 'a')
            printf("*");
        else
            printf("%c", frase[i]);
    }
    printf("\n");
}

int main() {
    char frase1[100], frase2[100];

    printf("Digite a primeira frase: ");
    fgets(frase1, sizeof(frase1), stdin);

    printf("Digite a segunda frase: ");
    fgets(frase2, sizeof(frase2), stdin);

    printf("Frase 1 invertida e com A trocados por *: ");
    inverterEsubstituir(frase1);

    printf("Frase 2 invertida e com A trocados por *: ");
    inverterEsubstituir(frase2);

    return 0;
}
