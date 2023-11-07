#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *erro_alloc = malloc(sizeof(erro_alloc));
    if (erro_alloc == NULL) {
        printf("Nâo foi possível alocar memória: %p", erro_alloc);
    }
    free(erro_alloc);
    erro_alloc = NULL;

    return 0;
}