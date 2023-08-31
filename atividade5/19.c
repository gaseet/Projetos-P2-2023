#include <stdio.h>

int main() {

    int count = 1;
    int div2 = 0, div3 = 0, div5= 0;
    int num;

    while (1) {
        printf("Informe o %d número (0 para encerrar): \n", count);
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num % 2 == 0) {
            div2++;
        }
        if (num % 3 == 0) {
            div3++;
        }
        if (num % 5 == 0) {
            div5++;
        }
        count++;
    }

    printf("%d números são divisíveis por 2, %d números são divisíveis por 3 e %d números são divisíveis por 5.", div2, div3, div5);

    return 0;
}
