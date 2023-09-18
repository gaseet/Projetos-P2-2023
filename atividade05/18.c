#include <stdio.h>

int main() {


    int countPares = 0, countImpares = 0, count = 1;
    int num;

    while (1) {
        printf("Informe o %d número (0 para encerrar): \n", count);
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num % 2 == 0) {
            countPares++;
        } else {
            countImpares++;
        }

        count++;
    }

    printf("Foram digitados %d números pares e %d números ímpares.", countPares, countImpares);

    return 0;
}
