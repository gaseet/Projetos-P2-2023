#include <stdio.h>
#include <string.h>

int main() {
    
    char serie[30];
    int um = 0;
    int i = 0;

    printf("Informe uma série de números: ");
    fgets(serie, sizeof(serie), stdin);

    while (serie[i]) {
        if (serie[i] == '1') {
            um++;
        }
        i++;
    }
    
     
    printf("%d", um);

    return 0;
}