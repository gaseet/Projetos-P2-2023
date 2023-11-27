#include <stdio.h>
#include <string.h>
struct pessoa {
    
};

int main() {
    char nome[50], email[50];
    int idade;

    printf("Informe o nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Informe a idade: ");
    scanf(" %d", &idade);
    getchar();

    printf("Informe o email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    FILE *arquivo = fopen("info.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    fprintf(arquivo, "Nome: %s, Idade: %d, Email: %s\n", nome, idade, email);

    fclose(arquivo);

    printf("Final do programa.");

    return 0;
}