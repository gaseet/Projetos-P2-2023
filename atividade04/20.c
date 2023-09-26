#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    int num1, num2, operacao;
    float resultado;

    printf("Informe o primeiro número: ");
    scanf("%d", &num1);

    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    printf("Escolha qual operação deseja realizar:\n 1 - Soma\n 2 - Subtração\n 3 - Multiplicação\n 4 - Divisão\n");
    scanf("%d", &operacao);

    switch (operacao) {
        case 1:
            resultado = num1 + num2;
            printf("O resultado da soma é: %.2f\n", resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("O resultado da subtração é: %.2f\n", resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("O resultado da multiplicação é: %.2f\n", resultado);
            break;
        case 4:
            resultado = (float)num1 / (float)num2;
            printf("O resultado da divisão é: %.2f\n", resultado);
            break;
        default:
            printf("Opção não reconhecida.\n");
    }

    return 0;
}
