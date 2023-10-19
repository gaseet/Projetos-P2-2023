#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    char palavra1[100], palavra2[100];

    printf("Informe a frase 1: ");
    scanf("%s", palavra1);

    for(int i = 0; palavra1[i] != '\0'; i++) {
        palavra1[i] = tolower(palavra1[i]);
    }

    printf("Informe a frase 2: ");
    scanf("%s", palavra2);

    for(int i = 0; palavra2[i] != '\0'; i++) {
        palavra2[i] = tolower(palavra2[i]);
    }

    int compare = strcmp(palavra1, palavra2);

    if (compare < 0) {
        printf("A palavra1 (%s) vem antes da palavra2 (%s) na ordem alfabética.\n", palavra1, palavra2);
    } else if (compare > 0) {
        printf("A palavra1 (%s) vem depois da palavra2 (%s) na ordem alfabética.\n", palavra1, palavra2);
    } else {
        printf("A palavra 1 (%s) e a palavra2 (%s) são iguais na ordem alfabética.\n", palavra1, palavra2);
    }

    return 0;
}
