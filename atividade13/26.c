#include <stdio.h>
#include <ctype.h>

int main() {

    char frase[100];
    char cripto[100];

    printf("Informe a frase: ");
    fgets(frase, sizeof(frase), stdin);   

    for(int i = 0; i < sizeof(frase); i++) {
        if(frase[i] == '\0') {
            cripto[i] = '\0';
        } else if(frase[i] == ' ') {
            cripto[i] = ' ';
        } else {
            cripto[i] = frase[i] + 3;
        }   
    }

    printf("Frase informada: %s", frase);
    printf("Frase criptografada: %s", cripto);

    return 0;
}
