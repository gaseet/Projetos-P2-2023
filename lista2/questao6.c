#include <stdio.h>
int main(){
    int num;
    printf("Informe um número inteiro: ");
    scanf("%d", &num);
    if (num % 2 == 0) {
        printf("O número informado é par.");
    } else {
        printf("O número informado é ímpar.");
    }

    return 0;
}