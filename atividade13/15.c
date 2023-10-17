#include <stdio.h>
#include <string.h>

int main() {
    
    char palavra[51];
    
    printf("Informe o palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    
    for (int i = 0; palavra[i] != '\0'; i++) {
        //printf("%d\n", palavra[i]);
        palavra[i] -= 32;
    }

    printf("%s", palavra);

    return 0;
}