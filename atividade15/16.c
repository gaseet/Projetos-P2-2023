#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 5

struct Filme {
    char nome[20];
    int ano;
    int duracao;
};

struct Diretor {
    char nome[20];
    int quantidadeFilmes;
    struct Filme filmes[10];
};

void imprimirFilmes(struct Filme filmes[], int quantidadeFilmes) {
    printf("\nFilmes:\n");
    printf("\n");
    for (int i = 0; i < quantidadeFilmes; ++i) {
        printf("Nome: %s, Ano: %d, Duração: %d minutos\n", filmes[i].nome, filmes[i].ano, filmes[i].duracao);
        printf("\n");
    }
}

int buscarDiretor(struct Diretor diretores[], int numDiretores, char nomeBusca[]) {
    for (int i = 0; i < numDiretores; ++i) {
        char nomeDiretorUpper[20];
        char nomeBuscaUpper[20];

        for (int j = 0; j < strlen(diretores[i].nome); ++j) {
            nomeDiretorUpper[j] = toupper(diretores[i].nome[j]);
        }
        nomeDiretorUpper[strlen(diretores[i].nome)] = '\0';

        for (int j = 0; j < strlen(nomeBusca); ++j) {
            nomeBuscaUpper[j] = toupper(nomeBusca[j]);
        }
        nomeBuscaUpper[strlen(nomeBusca)] = '\0';

        if (strstr(nomeDiretorUpper, nomeBuscaUpper) != NULL) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Diretor diretores[TAMANHO];

    for (int i = 0; i < TAMANHO; ++i) {
        printf("Digite os dados do diretor %d:\n", i + 1);
        printf("Nome do Diretor (máximo 20 letras): ");
        fgets(diretores[i].nome, sizeof(diretores[i].nome), stdin);
        diretores[i].nome[strcspn(diretores[i].nome, "\n")] = '\0';

        printf("Quantidade de Filmes: ");
        scanf("%d", &diretores[i].quantidadeFilmes);
        getchar();

        for (int j = 0; j < diretores[i].quantidadeFilmes; ++j) {
            printf("Digite os dados do filme %d:\n", j + 1);
            printf("Nome do Filme (máximo 20 letras): ");
            fgets(diretores[i].filmes[j].nome, sizeof(diretores[i].filmes[j].nome), stdin);
            diretores[i].filmes[j].nome[strcspn(diretores[i].filmes[j].nome, "\n")] = '\0';

            printf("Ano: ");
            scanf("%d", &diretores[i].filmes[j].ano);

            printf("Duração (em minutos): ");
            scanf("%d", &diretores[i].filmes[j].duracao);
            getchar();
        }

        printf("\n");
    }

    char nomeBusca[20];

    do {
        printf("Digite o nome do diretor para buscar (ou string vazia para sair): ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        if (strlen(nomeBusca) == 0) {
            break;
        }

        int indiceDiretor = buscarDiretor(diretores, TAMANHO, nomeBusca);

        if (indiceDiretor != -1) {
            printf("\n");
            printf("Diretor encontrado:\n");
            printf("Nome: %s\n", diretores[indiceDiretor].nome);
            imprimirFilmes(diretores[indiceDiretor].filmes, diretores[indiceDiretor].quantidadeFilmes);
        } else {
            printf("\n");
            printf("Erro: Diretor não encontrado.\n");
        }

    } while (1);

    return 0;
}
