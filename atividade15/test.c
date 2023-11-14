#include <stdio.h>
#include <string.h>

#define MAX_CARROS 5
#define MAX_MARCA 15

struct Carro {
    char marca[MAX_MARCA];
    int ano;
    float preco;
};

int main() {
    struct Carro carros[MAX_CARROS];
    float p;

    // Lê os dados dos carros
    for (int i = 0; i < MAX_CARROS; i++) {
        printf("Informe a marca do carro %d: ", i + 1);
        scanf("%s", carros[i].marca);

        printf("Informe o ano do carro %d: ", i + 1);
        scanf("%d", &carros[i].ano);

        printf("Informe o preço do carro %d: ", i + 1);
        scanf("%f", &carros[i].preco);
    }

    // Processo de busca
    do {
        // Lê o valor de p
        printf("\nInforme o valor de p (digite 0 para sair): ");
        scanf("%f", &p);

        if (p != 0) {
            // Mostra as informações dos carros com preço menor que p
            printf("\nCarros com preço menor que %.2f:\n", p);
            for (int i = 0; i < MAX_CARROS; i++) {
                if (carros[i].preco < p) {
                    printf("Marca: %s\nAno: %d\nPreço: %.2f\n\n", carros[i].marca, carros[i].ano, carros[i].preco);
                }
            }
        }
    } while (p != 0);

    return 0;
}
