#include <stdio.h>
void alterarDados(float *ptrAlt, int *ptrIda) {
    *ptrAlt = 1.70;
    *ptrIda = 10;

}

int main() {
    float altura = 1.68;
    int idade = 12;

    int *ptr1;
    float *ptr2;

    ptr1 = &idade;
    ptr2 = &altura;

    printf("Idade = %d\n", idade);
    printf("Endereço da variável idade = %p\n", ptr1);

    printf("Altura = %f\n", altura);
    printf("Endereço da variável altura = %p\n", ptr2);

    alterarDados(&altura, &idade);

    //*ptr2 = 1.50;
    printf("Altura alterada = %f\n", altura);

    //*ptr1 = 10;
    printf("Idade alterada = %d", idade);

    //printf("%d || %f", *ptr1, *ptr2);

    return 0;
}
