#include <stdio.h>

int main() {

    int matriz [5][4] = {1};

    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            if (j == 0) {
                printf("Informe o código do produto: ");
                scanf("%d", &matriz[i][j]);
            } else if (j == 1) {
                printf("Informe a quantidade atual no estoque: ");
                scanf("%d", &matriz[i][j]);
            } else if (j == 2) {
                printf("Informe a quantidade mínima desejada em estoque: ");
                scanf("%d", &matriz[i][j]);
            } else {
                printf("Informe a quantidade máxima permitida em estoque: ");
                scanf("%d", &matriz[i][j]);
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for( int j = 0; i < 4; j++) {
            printf("%d", matriz[i][j]);
        }
    }

    
    return 0;
}