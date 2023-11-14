#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Agenda {
    char nome[100];
    char endereco[300];
    char telefone[50];
};

void inserePessoa(struct Agenda agenda[], int *tamanho, struct Agenda novaPessoa) {
    int i, j;

    for (i = 0; novaPessoa.nome[i]; i++) {
        novaPessoa.nome[i] = toupper(novaPessoa.nome[i]);
    }

    for (i = 0; i < *tamanho && strcmp(agenda[i].nome, novaPessoa.nome) < 0; i++);

    for (j = *tamanho; j > i; j--) {
        agenda[j] = agenda[j - 1];
    }

    strcpy(agenda[i].nome, novaPessoa.nome);
    strcpy(agenda[i].endereco, novaPessoa.endereco);
    strcpy(agenda[i].telefone, novaPessoa.telefone);

    (*tamanho)++;

    printf("Pessoa inserida com sucesso!\n");
}

#define TAMANHO 5

int main() {
    struct Agenda agenda[100];
    int tamanho = 0;
    char choice;

    do {
        struct Agenda novaPessoa;

        printf("Digite o nome: ");
        fgets(novaPessoa.nome, sizeof(novaPessoa.nome), stdin);
        novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';

        printf("Digite o endereco: ");
        fgets(novaPessoa.endereco, sizeof(novaPessoa.endereco), stdin);
        novaPessoa.endereco[strcspn(novaPessoa.endereco, "\n")] = '\0';

        printf("Digite o telefone: ");
        fgets(novaPessoa.telefone, sizeof(novaPessoa.telefone), stdin);
        novaPessoa.telefone[strcspn(novaPessoa.telefone, "\n")] = '\0';

        inserePessoa(agenda, &tamanho, novaPessoa);

        printf("Deseja adicionar outra pessoa? (s/n): ");
        scanf(" %c", &choice);
        getchar();

    } while (choice == 's' || choice == 'S');

    printf("---------------------------\n");
    printf("\nAgenda:\n");
    printf("---------------------------\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", agenda[i].nome);
        printf("%s\n", agenda[i].endereco);
        printf("%s\n", agenda[i].telefone);
        printf("---------------------------\n");
    }

    return 0;
}
