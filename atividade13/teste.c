#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char data[11];
    int dia, mes, ano;
    
    printf("Informe a data no formato \"DDMMAAAA\": ");
    scanf("%s", data);

    int resultado = sscanf(data, "%2d%2d%4d", &dia, &mes, &ano);

    printf("Dia: %d, Mês: %d, Ano: %d\n", dia, mes, ano);

    return 0;
}
