#include <stdio.h>

int main(){

    char dias[][20] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

    int dia;

    printf("Digite o número do dia da semana (1 a 7): ");
    scanf("%d", &dia);

    while (dia < 1 || dia > 7) {
        printf("Digite um número válido (1 a 12): ");
        scanf("%d", &dia);        
    }

    printf("O dia correspondente ao número %d é: %s", dia, dias[dia-1]);

    return 0;
}