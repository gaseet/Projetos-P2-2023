#include <stdio.h>
#include <string.h>

int main() {
    
    char frase[100];
    char l1, l2;
    int i = 0;

    printf("Informe um frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Informe L1: ");
    scanf(" %c", &l1);
    getchar();

    printf("Informe L2: ");
    scanf(" %c", &l2);
    getchar();

    while (frase[i] != '\0') {
        if (frase[i] == l1) {
            frase[i] = l2;
         }
        i++;
    }

    printf("%s", frase);

    return 0;
}