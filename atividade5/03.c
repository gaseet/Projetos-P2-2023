#include <stdio.h>

int main() {
    int num;
    printf("Informe um número inteiro: ");
    scanf("%d", &num);

    printf("Os divisores de %d são: ", num);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d", i);

            if (i != num) {
                printf(", ");
            }
        }
    }


    return 0;
}
