#include <stdio.h>
#include <string.h>

int main() {
    
    char serie[30];
    int i = 0;

    printf("Informe uma string: ");
    fgets(serie, sizeof(serie), stdin);

    while (serie[i]) {
        if (serie[i] == '0') {
            serie[i] = '1';
        }
        i++;
    }
    
    printf("Zeros substituidos por um: %s", serie);

    return 0;
}