#include <stdio.h>

void sequencia(int n){
    if (n >= 0){
        sequencia(n-1);
        printf("%d\n", n);
    }
}

int main() {

    int num;

    printf("Informe um número inteiro: ");
    scanf("%d", &num);

    sequencia(num);

    return 0;
}