#include <stdio.h>
#include <string.h>

int main() {
    
    char frase[100];
    char sub;
    int i = 0, cont = 0;

    printf("Informe um frase: ");
    fgets(frase, sizeof(frase), stdin);

    while (frase[i]) {
        if (frase[i] == ' ') {
            cont++;
         }
        i++;
    }

    printf("%d", cont);

    return 0;
}