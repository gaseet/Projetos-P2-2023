#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char diaSemana[20];
    printf("Digite o dia da semana (por extenso): ");
    scanf("%s", diaSemana);
    for (int i = 0; i < strlen(diaSemana); i++) {
        diaSemana[i] = tolower(diaSemana[i]);
    } 
    char diasUteis[][20] = {"segunda", "terça", "quarta", "quinta", "sexta"};
    char finsDeSemana[][20] = {"sábado", "domingo"};
    int diaUtil = 0;
    int fimDeSemana = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(diaSemana, diasUteis[i]) == 0) {
            diaUtil = 1;
            break;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(diaSemana, finsDeSemana[i]) == 0) {
            fimDeSemana = 1;
            break;
        }
    }
    if (diaUtil == 1) {
        printf("É um dia útil.\n");
    } else if (fimDeSemana == 1) {
        printf("É um fim de semana.\n");
    } else {
        printf("Dia da semana inválido.\n");
    }
    
    return 0;
}
