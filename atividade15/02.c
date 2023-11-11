#include <stdio.h>

struct pessoa {
    char nome[100];
    int idade;
    char endereco[100];
};

int main() {

    struct pessoa p;

    printf("Informe o nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);

    printf("Informe a idade: ");
    scanf(" %d", &p.idade);

    getchar();

    printf("Informe o endereço: ");
    fgets(p.endereco, sizeof(p.endereco), stdin);

    printf("%s", p.nome);
    printf("%d \n", p.idade);
    printf("%s", p.endereco);

    return 0;
}