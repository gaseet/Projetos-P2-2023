#include <stdio.h>
int fibo (int n){
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibo(n-1) + fibo(n-2);
    }

}

int main(){

    int num, resultado;

    printf("Informe um número inteiro positivo: \n");
    scanf("%d", &num);

    resultado = fibo(num);
    printf("O número %d de Fibonacci é: %d", num, resultado);

    return 0;
}