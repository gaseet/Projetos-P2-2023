#include <stdio.h>
#include <string.h>

int main() {
    
    char serie[30];
    int i = 0;

    printf("Informe uma série de números: ");
    fgets(serie, sizeof(serie), stdin);

    while (serie[i]) {
        if (serie[i] == '0') {
            serie[i] = '1';
        }
        i++;
    }
    
    // - 1 para remover o caractere de quebra de linha contabilizado quando o usuário
    // aperta enter.
    
    printf("Zeros substituidos por um: %s", serie);

    return 0;
}