#include <stdio.h>
#include <string.h>
int main(){

    int idade;
    char estado[10];
    printf("Informe a sua idade: ");
    scanf("%d", &idade);
    if (idade >= 18) {
        strcpy(estado, "maior");
    } else {
        strcpy(estado, "menor");
    }
    printf("Você é %s de idade", estado);

    return 0;
}
