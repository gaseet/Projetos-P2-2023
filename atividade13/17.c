#include <stdio.h>
#include <string.h>

int main() {
    
    char frase[100];
    int i = 0, j = 0;

    printf("Informe um frase: ");
    fgets(frase, sizeof(frase), stdin);

    while (frase[i]) {
        if (frase[i] != ' ' && frase[i] != '\t' && frase[i] != '\n') {
            frase[j] = frase[i];
            j++;
         }
        i++;
    }

    printf("%s", frase);

    return 0;
}