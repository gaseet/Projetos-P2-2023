#include <stdio.h>

int pell (int n){
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return 2 * pell(n-1) + pell(n-2);
    }

}

int main(){

    int num, resultado;

    printf("Informe um número inteiro positivo: ");
    scanf("%d", &num);

    resultado = pell(num);
    printf("O número %d da sequência é: %d", num, resultado);

    return 0;
}
