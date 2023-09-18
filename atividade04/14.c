#include <stdio.h>

int main(){

    int num;
    printf("Informe um número inteiro: ");
    scanf("%d", &num);
    if (num % 3 == 0 && num % 5 == 0) {
        printf("O número %d é divisível por 3 e por 5.", num);
    } else {
        printf("O número %d não é divisível por 3 e por 5.", num);
    }

    return 0;
}