#include <stdio.h>
#include <string.h>

int main() {

    char nome[30];
    char sexo[30];
    int idade;

    printf("Informe o nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Informe o sexo (feminino ou masculino): ");
    fgets(sexo, sizeof(sexo), stdin);

    printf("Informe a idade: ");
    scanf("%d", &idade);

    if (strcmp(sexo, "feminino") && idade < 25) {
        printf("ACEITA");
    } else {
        printf("NÃO ACEITO(A)");
    }

    return 0;
}