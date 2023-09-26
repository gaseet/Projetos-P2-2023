#include <stdio.h>
int somatorio (int n){
    if (n == 1) {
        return 1;
    }
    else {
        return n + somatorio(n-1);
    }

}
int main(){

    int num, resultado;

    printf("Informe um número inteiro positivo: \n");
    scanf("%d", &num);

    resultado = somatorio(num);
    printf("O somatório de 1 a %d é: %d", num, resultado);

    return 0;
}