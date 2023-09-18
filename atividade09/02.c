#include <stdio.h>

float kmPorLitro(float km, float litro){

    float kmL = km / litro;
    return kmL;

}

int main() {

    float km, litro, kmL;

    printf("Informe quantos Km foram percorridos: ");
    scanf("%f", &km);

    printf("Informe quantos litros foram consumidos: ");
    scanf("%f", &litro);

    kmL = kmPorLitro(km, litro);

    if (kmL < 8) {
        printf("Venda o carro!");
        
    } else if (kmL >= 8 && kmL <= 14) {
        printf("Econômico!");

    } else {
        printf("Super econômico!");
    }

    return 0;
}
