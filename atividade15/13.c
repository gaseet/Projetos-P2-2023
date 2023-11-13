#include <stdio.h>
#include <string.h>

struct consumo {
    float diario;
    float total;
    float relativo;
};

struct eletrodomestico {
    char nome[15];
    float potencia;
    float horasAtivo;
    struct consumo consumo;
};

#define TAMANHO 5

int main() {

    struct eletrodomestico ele[TAMANHO];
    int dias;

    for(int i = 0; i < TAMANHO; i++) {
        printf("Informe o nome do eletrodoméstico: ");
        fgets(ele[i].nome, sizeof(ele[i].nome), stdin);

        printf("Informe a potência em kWh: ");
        scanf("%f", &ele[i].potencia);

        printf("Informe quantas horas ele passa ativo diariamente: ");
        scanf("%f", &ele[i].horasAtivo);
    }

    //REMOVE '\n' DOS NOMES
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < strlen(ele[i].nome); j++) {
            if(ele[i].nome[j] == '\n') {
                ele[i].nome[j] = '\0';
            }
        }
    }

    printf("Informe o tempo em dias: ");
    scanf("%d", &dias);

    for(int i = 0; i < TAMANHO; i++) {
        ele[i].consumo.diario = ele[i].horasAtivo * ele[i].potencia;
    }

    for(int i = 0; i < TAMANHO; i++) {
        ele[i].consumo.total = dias * ele[i].consumo.diario;

        ele[i].consumo.relativo = (ele[i].consumo.diario / ele[i].consumo.total) * 100;
    }

    printf("\n");
    
    for(int i = 0; i < TAMANHO; i++) {
        printf("Consumo total de \"%s\": %.2f kW", ele[i].nome, ele[i].consumo.total);
        printf("\n");
        printf("Consumo relativo de \"%s\": %.2f%%", ele[i].nome, ele[i].consumo.relativo);
        printf("\n");
    }

    return 0;
}