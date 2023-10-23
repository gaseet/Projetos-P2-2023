#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char data[11];
    int dia, mes, ano;

    printf("Informe a data no formato \"DD/MM/AAAA\": ");
    scanf(" %s", data);

    for(int i = 0; i < strlen(data); i++) {
        if (i == 2 || i == 5) {
            if (data[i] != '/') {
                printf("Por favor insira as / no lugar certo.");
            }
        } else {
            if(!isdigit(data[i])) {
                printf("Caractere não numérico inserido.");
            }
        }
    }
    
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    printf("Dia: %d, Mês: %d, Ano: %d\n", dia, mes, ano);

    return 0;
}