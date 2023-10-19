/* 22. Ler o nome e o valor de uma determinada mercadoria de uma loja. Sabendo que o desconto para
pagamento à vista é de 10% sobre o valor total, calcular o valor a ser pago à vista. Escrever o nome
da mercadoria, o valor total, o valor do desconto e o valor a ser pago à vista.
 */

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