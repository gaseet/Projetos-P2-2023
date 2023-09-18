// 17. Elabore um programa que leia uma sequência de números inteiros do usuário e determine
// quantos números pares foram digitados antes do primeiro número ímpar. O programa deve parar
// de ler quando o usuário digitar o número 0 utilizando o while.

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

        if (num % 2 != 0) {
            countImpares++;
        }

        if (countImpares == 0) {
            if (num % 2 == 0) {
                countPares++;
            }
        }

        count++;
    }

    printf("Foram digitados %d números pares antes do primeiro número ímpar.", countPares);

    return 0;
}
