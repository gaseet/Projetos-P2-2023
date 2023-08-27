#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

    char estado[20];
    printf("Informe seu estado civil:\n(Solteiro(a), Casado(a), Divorciado(a) ou Viúvo(a).)\n");
    scanf("%s", estado);

    for (int i = 0; estado[i]; i++) {
        estado[i] = tolower(estado[i]);
    }

    switch (estado[0]) {
        case 's':
            printf("Você é solteiro(a).\n");
            break;
        case 'c':
            printf("Você é casado(a).\n");
            break;
        case 'd':
            printf("Você é divorciado(a).\n");
            break;
        case 'v':
            printf("Você é víuvo(a).\n");
            break;
        default: 
            printf("Estado civil não reconhecido.\n");
    }

    return 0;
}