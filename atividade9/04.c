#include <stdio.h>

int sequencia (int n){
    if (n == 1 || n == 2) {
        return n;
    }
    else {
        return 2 * sequencia(n-1) + 3 * sequencia(n-2);
    }

}

int main(){

    int num, resultado;

    printf("Informe um número inteiro positivo: \n");
    scanf("%d", &num);

    resultado = sequencia(num);
    printf("O número %d da sequência é: %d", num, resultado);

    return 0;
}
