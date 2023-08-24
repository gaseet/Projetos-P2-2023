#include <stdio.h>
#include <string.h>
int main(){

    int num;
    char tipo[50];
    printf("Informe um número inteiro: ");
    scanf("%d", &num);
    if (num > 0) {
        strcpy(tipo, "positivo");
    } else if(num < 0) {
        strcpy(tipo, "negativo");
    } else {
        strcpy(tipo, "igual a zero");
    }
    printf("O número informado é: %s", tipo);

    return 0;
}