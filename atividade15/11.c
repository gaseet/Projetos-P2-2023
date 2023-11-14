struct carros {
    char marca[15];
    int ano;
    int preco;
};


#include <stdio.h>
#include <string.h>

#define TAMANHO 5

int main() {

    struct carros carros[TAMANHO];

    int valor, sair = 0;

    for(int i = 0; i < TAMANHO; i++) {
        printf("Informe a marca do carro %d: ", i + 1);
        fgets(carros[i].marca, sizeof(carros[i].marca), stdin);
        carros[i].marca[strcspn(carros[i].marca, "\n")] = '\0';

        printf("Informe o ano do carro %d: ", i + 1);
        scanf(" %d", &carros[i].ano);

        printf("Informe o preco do carro %d: ", i + 1);
        scanf(" %d", &carros[i].preco);
        getchar();
    }

    do{
        printf("\nInforme o valor de P para buscar carros com Preço < P (digite 0 para sair): ");
        scanf(" %d", &valor);
        printf("\n");

        if (valor != 0) {
            printf("---------------------------\n");
            printf("Carros com preço menor que %d:\n", valor);
            printf("---------------------------\n");
            for (int i = 0; i < TAMANHO; i++) {
                if (carros[i].preco < valor) {
                    printf("Marca: %s\n", carros[i].marca);
                    printf("Ano: %d\n", carros[i].ano);
                    printf("Preço: %d\n", carros[i].preco);
                    printf("---------------------------\n");
                } else {
                    printf("Nenhum carro encontrado.\n");
                    printf("---------------------------\n");
                }
            }
        }
    } while (valor != 0);

    return 0;
}