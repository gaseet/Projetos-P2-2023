#include <stdio.h>

int main() {
    int num, revertido = 0, resto;
    
    printf("Informe um inteiro: ");
    scanf("%d", &num);
    
    while (num != 0) {
        resto = num % 10;
        revertido = revertido * 10 + resto;
        num /= 10;
    }
    
    printf("Número revertido: %d\n", revertido);
    
    return 0;
}
