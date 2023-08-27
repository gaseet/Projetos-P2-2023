#include <stdio.h>
#include <ctype.h>
int main(){

    char caractere;
    printf("Informe uma letra: ");
    scanf("%c", &caractere);
    if (tolower(caractere) == 'a' || tolower(caractere) == 'e' || tolower(caractere) == 'i'
     || tolower(caractere) == 'o' || tolower(caractere) == 'u') {
        printf("A letra informada é uma vogal.");
     } else {
        printf("A letra informada é uma consoante.");
     }
     
    return 0;
}
