#include <stdio.h>

void sequencia(int n){
    if (n >= 0){
        printf("%d\n", n);
        sequencia(n-1);
    }
}

int main() {

    int num;

    printf("Informe um número inteiro: ");
    scanf("%d", &num);

    sequencia(num);

    return 0;
}