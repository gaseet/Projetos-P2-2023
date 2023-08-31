#include <stdio.h>
#include <math.h>

int main() {
    int numero, digito;
    int soma = 0;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    while (numero != 0) {
        digito = numero % 10;
        soma += pow(digito, 3);
        numero /= 10;
    }

    printf("A soma dos dígitos elevados ao cubo é: %d\n", soma);

    return 0;
}
