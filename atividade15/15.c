#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 5

struct Ingrediente {
    char nome[20];
    char quantidade[50];
};

struct Receita {
    char nome[25];
    int numIngredientes;
    struct Ingrediente ingredientes[10];
};

void imprimirIngredientes(struct Ingrediente ingredientes[], int numIngredientes) {
    printf("\n");
    printf("Ingredientes:\n");
    printf("\n");
    for (int i = 0; i < numIngredientes; ++i) {
        printf("%s, Quantidade: %s\n", ingredientes[i].nome, ingredientes[i].quantidade);
        printf("\n");
    }
}

int buscarReceita(struct Receita receitas[], int numReceitas, char nomeBusca[]) {
    for (int i = 0; i < numReceitas; ++i) {
        char nomeReceitaUpper[25];
        char nomeBuscaUpper[25];

        for (int j = 0; j < strlen(receitas[i].nome); ++j) {
            nomeReceitaUpper[j] = toupper(receitas[i].nome[j]);
        }
        nomeReceitaUpper[strlen(receitas[i].nome)] = '\0';

        for (int j = 0; j < strlen(nomeBusca); ++j) {
            nomeBuscaUpper[j] = toupper(nomeBusca[j]);
        }
        nomeBuscaUpper[strlen(nomeBusca)] = '\0';

        if (strstr(nomeReceitaUpper, nomeBuscaUpper)) {
            return i;
        }
    }
    return -1;
}


int main() {
    struct Receita receitas[TAMANHO];

    for (int i = 0; i < TAMANHO; ++i) {
        printf("Digite os dados da receita %d:\n", i + 1);
        printf("Nome da Receita (máximo 25 letras): ");
        fgets(receitas[i].nome, sizeof(receitas[i].nome), stdin);
        receitas[i].nome[strcspn(receitas[i].nome, "\n")] = '\0';

        printf("Quantidade de Ingredientes: ");
        scanf("%d", &receitas[i].numIngredientes);
        getchar();

        for (int j = 0; j < receitas[i].numIngredientes; ++j) {
            printf("Digite os dados do ingrediente %d:\n", j + 1);
            printf("Nome do Ingrediente (máximo 20 letras): ");
            fgets(receitas[i].ingredientes[j].nome, sizeof(receitas[i].ingredientes[j].nome), stdin);
            receitas[i].ingredientes[j].nome[strcspn(receitas[i].ingredientes[j].nome, "\n")] = '\0';

            printf("Quantidade: ");
            fgets(receitas[i].ingredientes[j].quantidade, sizeof(receitas[i].ingredientes[j].quantidade), stdin);
            receitas[i].ingredientes[j].quantidade[strcspn(receitas[i].ingredientes[j].quantidade, "\n")] = '\0';
        }

        printf("\n");
    }

    char nomeBusca[25];

    do {
        printf("Digite o nome da receita para buscar (ou string vazia para sair): ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        if (strlen(nomeBusca) == 0) {
            break;
        }

        int indiceReceita = buscarReceita(receitas, TAMANHO, nomeBusca);

        if (indiceReceita != -1) {
            printf("\n");
            printf("Receita encontrada:\n");
            printf("\n");
            printf("Nome: %s\n", receitas[indiceReceita].nome);
            imprimirIngredientes(receitas[indiceReceita].ingredientes, receitas[indiceReceita].numIngredientes);
        } else {
            printf("\n");
            printf("Erro: Receita não encontrada.\n");
            printf("\n");
        }

    } while (1);

    return 0;
}
