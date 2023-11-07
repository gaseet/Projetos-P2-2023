#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros = (int *)calloc(1500, sizeof(int));

    if (numeros == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1;
    }

    int cont = 0;

    for(int i = 0; i < 1500; i++) {
        if (numeros[i] == 0) {
            cont++;
        }
        numeros[i] = i;
        if(i < 10 || i >= 1490) {
            printf("%d\n", numeros[i]);
        }
    }

    printf("Contagem: %d", cont);

    free(numeros);
    numeros = NULL;
    
    return 0;
}
