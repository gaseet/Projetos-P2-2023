#include <stdio.h>

int main() {

    int inteiro = 10;
    float real = 9.99;
    char caractere = 'c';

    int *pInteiro = &inteiro;
    float *pReal = &real;
    char *pCaractere = &caractere;

    printf("Valores iniciais:\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n\n", caractere);

    *pInteiro = 20;
    *pReal = 5.99;
    *pCaractere = 'a';

    printf("Valores após a modificação:\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", caractere);

    return 0;
}
