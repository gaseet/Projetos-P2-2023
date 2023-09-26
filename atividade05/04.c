#include <stdio.h>

int main() {
    float altura;
    float alturaTotal = 0;
    for (int i = 1; i <= 5; i++) {
        printf("Informe a altura da pessoa %d: ", i);
        scanf("%f", &altura);
        alturaTotal += altura;
    }
    printf("A média das alturas informadas é: %.2f", alturaTotal);

    return 0;
}
