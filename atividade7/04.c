#include <stdio.h>

void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    trocarValores(&a, &b);

    printf("Depois da troca:\n");
    printf("A: %d\n", a);
    printf("B: %d\n", b);

    return 0;
}
