#include <stdio.h>

int main(){

    char meses[][20] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
     "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    int mes;

    printf("Digite o número de um mês (1 a 12): ");
    scanf("%d", &mes);

    while (mes < 1 || mes > 12) {
        printf("Digite um número válido (1 a 12): ");
        scanf("%d", &mes);        
    }

    printf("O mês correspondente ao número %d é: %s", mes, meses[mes-1]);

    return 0;
}