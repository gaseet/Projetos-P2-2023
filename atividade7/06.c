#include <stdio.h>

void calcularSoma(int *a, int b) {
    *a = *a + b;
}

int main() {
    int A, B;

    printf("Digite o valor de A: ");
    scanf("%d", &A);

    printf("Digite o valor de B: ");
    scanf("%d", &B);

    calcularSoma(&A, B);

    printf("Soma de A e B, armazenado em A: %d\n", A);
    printf("Valor de B: %d\n", B);

    return 0;
}
