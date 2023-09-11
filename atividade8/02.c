#include <stdio.h>
int fatorial (int n){
    if (n == 0) {
        return 1;
    }
    else {
        return n * fatorial(n-1);
    }

}
int main(){

    int num, resultado;

    printf("Informe um número inteiro positivo: \n");
    scanf("%d", &num);

    resultado = fatorial(num);
    printf("O fatorial de %d é: %d", num, resultado);

    return 0;
}