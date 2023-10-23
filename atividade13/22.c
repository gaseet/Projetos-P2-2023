#include <stdio.h>

int main() {

    char mercadoria[30];
    float valor;

    printf("Informe o nome da mercadoria: ");
    fgets(mercadoria, sizeof(mercadoria), stdin);

    printf("Informe o valor da mercadoria: ");
    scanf("%f", &valor);

    printf("Nome do produto: %s", mercadoria);
    printf("Valor do produto: %.1f R$\n", valor);
    printf("Valor do desconto: %.2f R$\n", (valor / 100.0) * 10);
    printf("Valor a ser pago à vista: %.2f R$\n", (valor / 100.0) * 90);


    return 0;
}