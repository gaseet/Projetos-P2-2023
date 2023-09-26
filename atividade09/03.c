//3. Crie um programa que contenha uma função que permita passar por parâmetro dois números
//inteiros A e B. A função deverá calcular a soma entre estes dois números e armazenar o resultado
//na variável A. Esta função não deverá possuir retorno, mas deverá modificar o valor do primeiro
//parâmetro. Imprima os valores de A e B na função principal.

#include <stdio.h>
void soma(int *A, int *B) {

    *A = *A + *B;

}

int main() {

    int A, B;

    printf("Informe o valor de A: ");
    scanf("%d", &A);

    printf("Informe o valor de B: ");
    scanf("%d", &B);

    soma(&A, &B);

    printf("A soma dos valores informados é: %d", A);

    return 0;
}
