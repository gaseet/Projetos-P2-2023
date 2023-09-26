#include <stdio.h>
#include <string.h>
int main(){

    char nome1[100], nome2[100];
    printf("Informe o primeiro nome a ser verificado: ");
    scanf("%s", nome1);
    printf("Informe o segundo nome a ser verificado: ");
    scanf("%s", nome2);
    if (strlen(nome1) > strlen(nome2)){
        printf("O primeiro nome informado possui o maior número de caracteres.");
    } else if(strlen(nome1) == strlen(nome2)){
        printf("Os nomes informados possuem a mesma quantidade de caracteres.");
    } else {
        printf("O segundo nome informado possui o maior número de caracteres.");
    }

    return 0;
}
