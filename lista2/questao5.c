#include <stdio.h>
#include <string.h>
int main(){

    int num1, num2;
    printf("Informe o primeiro número inteiro: ");
    scanf("%d", &num1);
    printf("Informe o segundo número inteiro: ");
    scanf("%d", &num2);
    if (num1 == num2) {
        printf("Os números informados são iguais.");
    } else if(num1 > num2) {
        printf("O maior número informado é: %d", num1);
    } else {
        printf("O maior número informado é: %d", num2);
    }

    return 0;
}