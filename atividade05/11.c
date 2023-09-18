#include <stdio.h>

int main(){
    int i = 1;
    int num, menor, maior;
    while(1) {
        printf("Informe o %d número inteiro (0 para encerrar): ", i);
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (i == 1) {
            menor = num;
            maior = num;
        }
        if (num > maior) {
            maior = num;
        } else if (num < menor) {
            menor = num;
        }
        i++;
    }
    printf("O maior valor digitado é: %d\n", maior);
    printf("O menor valor digitado é: %d\n", menor);

    return 0;
}