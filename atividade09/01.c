#include <stdio.h>

float volCilindro(float raio, float altura){

    float vol = 3.141592 * raio * raio * altura;
    return vol;
}

int main() {

    float raio, altura, volume;

    printf("Informe a altura do cilindro: ");
    scanf("%f", &altura);

    printf("Informe o raio do cilindro: ");
    scanf("%f", &raio);

    volume = volCilindro(raio, altura);

    printf("O volume do cilindro é: %f", volume);

    return 0;
}
