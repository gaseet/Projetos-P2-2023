#include <stdio.h>

int somaDobro(int *a, int *b) {
    *a = 2 * (*a);
    *b = 2 * (*b);
    return *a + *b;
}

int main() {
    int A, B;

    printf("Digite o valor de A: ");
    scanf("%d", &A);

    printf("Digite o valor de B: ");
    scanf("%d", &B);

    int resultado = somaDobro(&A, &B);

    printf("Dobro do valor de A: %d\n", A);
    printf("Dobro do valor de B: %d\n", B);
    printf("Soma do dobro de A e B: %d\n", resultado);

    return 0;
}
