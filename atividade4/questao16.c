#include <stdio.h>

int main(){

    int num;
    printf("Informe um número inteiro de 1 a 5: ");
    scanf("%d", &num);
    switch (num) {
        case 1:
            printf("Muito insuficiente.");
            break;
        case 2:
            printf("Insuficiente.");
            break;
        case 3:
            printf("Regular.");
            break;
        case 4:
            printf("Bom.");
            break;
        case 5:
            printf("Muito bom.");
            break;
        default:
            printf("Número inválido.");
    }

    return 0;
}