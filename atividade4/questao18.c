#include <stdio.h>

int main(){

    int idade;
    printf("Informe sua idade: ");
    scanf("%d", &idade);

    if (idade < 0) {
        printf("Idade inválida.");
    } else if (idade <= 1) {
        printf("Você é um bebê.");
    } else if (idade <= 12) {
        printf("Você é uma criança.");
    } else if (idade <= 18) {
        printf("Você é um adolescente. ");
    } else{
        printf("Você é um adulto. ");
    }
    return 0;
}