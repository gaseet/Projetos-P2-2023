#include <stdio.h>

int main() {

    char str[101];
    int esquerda, direita;

    printf("Informe uma frase: ");
    fgets(str, sizeof(str), stdin);

    printf("Informe o segmento a ser printado [I, J]: \n");

    printf("Informe I: ");
    scanf("%d", &esquerda);

    printf("Informe J: ");
    scanf("%d", &direita);

    for (int i = esquerda; i <= direita; i++) {
        printf("%c", str[i]);
    }

    return 0;
}