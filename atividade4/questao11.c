#include <stdio.h>
#include <string.h>

int main(){

    float peso, altura;
    char classificacao[50];
    printf("Informe o peso: ");
    scanf("%f", &peso);
    printf("Informe a altura: ");
    scanf("%f", &altura);
    float imc = peso / (altura * altura);
    if (imc < 18.5) {
        strcpy(classificacao, "Abaixo do peso");
    } else if (imc <= 24.9) {
        strcpy(classificacao, "Peso ideal");
    } else if (imc <= 29.9) {
        strcpy(classificacao, "Sobrepeso");
    } else if (imc <= 34.9) {
        strcpy(classificacao, "Obesidade");
    } else {
        strcpy(classificacao, "Obesidade severa");
    }
    printf("Sua classificação é: %s ", classificacao);

    return 0;
}