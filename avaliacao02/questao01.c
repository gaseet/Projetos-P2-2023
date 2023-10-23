#include <stdio.h>

int main() {

    int matriz[5][4];

    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            if (j == 0) {
                printf("Código do produto %d: ", i + 1);
            } else if (j == 1) {
                printf("Quantidade atual no estoque: ");
            } else if (j == 2) {
                printf("Quantidade mínima desejada no estoque: ");
            } else {
                printf("Quantidade máxima no estoque: ");
            }
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int maiorReabast;
    int idMaior;
    int somaReabast = 0;

    for (int i = 0; i < 5; i++) {
        int reabast;
        for (int j = 0; j < 4; j++) {
            reabast = matriz[i][3] - matriz[i][1];
            if (i == 0) {
                maiorReabast = reabast;
                idMaior = matriz[i][0];
            }
            if (reabast > maiorReabast) {
                maiorReabast = reabast;
                idMaior = matriz[i][0];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        int reabast;
        for (int j = 0; j < 1; j++) {
            reabast = matriz[i][3] - matriz[i][1];
            somaReabast += reabast;
        }
    }

    int mediaReabast = somaReabast / 5;

    printf("Média de reabastecimento de todos os produtos: %d\n", mediaReabast);

    printf("O produto de id %d é o que precisa de mais reabastecimento, precisando de %d.", idMaior, maiorReabast);

    return 0;
}