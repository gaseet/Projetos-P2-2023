#include <stdio.h>

struct Eletrodomestico {
    char nome[16];
    float potencia;
    float tempo_ativo;
    float consumo_individual;
};

#define TAMANHO 2

int main() {
    struct Eletrodomestico eletrodomesticos[TAMANHO];

    for (int i = 0; i < TAMANHO; ++i) {
        printf("Digite o nome do eletrodomestico %d: ", i + 1);
        scanf("%s", eletrodomesticos[i].nome);

        printf("Digite a potencia do eletrodomestico %d (em kW): ", i + 1);
        scanf("%f", &eletrodomesticos[i].potencia);

        printf("Digite o tempo ativo por dia do eletrodomestico %d (em horas): ", i + 1);
        scanf("%f", &eletrodomesticos[i].tempo_ativo);
    }

    float tempo_dias;
    printf("Digite o tempo em dias: ");
    scanf("%f", &tempo_dias);

    float consumo_total = 0;
    for (int i = 0; i < TAMANHO; ++i) {
        eletrodomesticos[i].consumo_individual = eletrodomesticos[i].potencia * eletrodomesticos[i].tempo_ativo * tempo_dias;
        consumo_total += eletrodomesticos[i].consumo_individual;
    }

    printf("\nConsumo total na casa: %.2f kW\n", consumo_total);
    printf("\n");

    for (int i = 0; i < TAMANHO; ++i) {
        printf("Consumo individual de \"%s\": %.2fkW\n", eletrodomesticos[i].nome, eletrodomesticos[i].consumo_individual);
        float consumo_relativo = (eletrodomesticos[i].potencia * eletrodomesticos[i].tempo_ativo * tempo_dias / consumo_total) * 100;
        printf("Consumo relativo de \"%s\": %.2f%%\n", eletrodomesticos[i].nome, consumo_relativo);
        printf("\n");
    }

    return 0;
}
