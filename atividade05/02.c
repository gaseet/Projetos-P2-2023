#include <stdio.h>

int main() {
    int num, soma = 0;

    printf("Digite um num inteiro: ");
    scanf("%d", &num);

    while (num != 0) {
        int digito = num % 10;
        soma += digito;
        num /= 10;
    }

    printf("A soma dos digitos é: %d\n", soma);

    return 0;
}
