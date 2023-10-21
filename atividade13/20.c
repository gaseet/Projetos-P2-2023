#include <stdio.h>
#include <string.h>

int main() {

    char carros[5][20];
    int consumo[5];

    char economico[20];
    int consumoEcon;

    float litrosPra1000KM[5] = {0};

    for(int i = 0; i < 5; i++) {
        printf("Informe o %d carro: ", i + 1);
        scanf("%s", carros[i]);

        printf("Informe o consumo do carro %s (Km/L): ", carros[i]);
        scanf("%d", &consumo[i]);

        if (i == 0) {
            strcpy(economico, carros[i]);
            consumoEcon = consumo[i];
        }
    }

    printf("\n");

    for(int i = 0; i < 5; i++) {
        if (consumo[i] > consumoEcon) {
            strcpy(economico, carros[i]);
            consumoEcon = consumo[i];
        }
    }

    for(int i = 0; i < 5; i++) {
        litrosPra1000KM[i] = 1000.0 / consumo[i];
        printf("O carro %s precisa de %.2f litros para percorrer 1000 quilômetros.\n", carros[i], litrosPra1000KM[i]);
    }

    printf("\n");

    printf("Entre os carros informados, o mais econômico é: %s, com %d Km/L.\n", economico, consumoEcon);

    return 0;
}