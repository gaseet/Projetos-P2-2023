#include <stdio.h>

int main() {

    int n1, n2;

    printf("Digite o valor da primeira variável: ");
    scanf("%d", &n1);

    printf("Digite o valor da segunda variável: ");
    scanf("%d", &n2);

    printf("Endereço de memória da primeira variável: %p\n", &n1);
    printf("Endereço de memória da segunda variável: %p\n", &n2);

    return 0;
}
