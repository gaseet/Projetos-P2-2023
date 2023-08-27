#include <stdio.h>

int main(){

    float salario;
    float aumento;
    
    printf("Informe o salário do funcionário: ");
    scanf("%f", &salario);
    if (salario > 1500) {
        aumento = salario / 10;
    } else {
        aumento = (salario / 100) * 15;
    }
    printf("O aumento é de : %.2f", aumento);
    return 0;
}