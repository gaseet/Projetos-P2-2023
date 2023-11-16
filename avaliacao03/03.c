#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int dia;
    int mes;
    int ano;
};

struct competicao {
    char nome[50];
    char jogo[50];
    struct data data;
};

void adicionarCompeticao(struct competicao *competicoes, int *numCompeticoes, int *tamanhoCompeticoes) {
    if (*numCompeticoes == *tamanhoCompeticoes) {
        printf("Memória esgotada, por favor utilize a opção 4.");
        return;
    }

    printf("Nome da competição: ");
    fgets(competicoes[*numCompeticoes].nome, sizeof(competicoes[*numCompeticoes].nome), stdin);
    competicoes[*numCompeticoes].nome[strcspn(competicoes[*numCompeticoes].nome, "\n")] = '\0';

    printf("Jogo da competição: ");
    fgets(competicoes[*numCompeticoes].jogo, sizeof(competicoes[*numCompeticoes].jogo), stdin);
    competicoes[*numCompeticoes].jogo[strcspn(competicoes[*numCompeticoes].jogo, "\n")] = '\0';

    printf("Dia da competição: ");
    scanf("%d", &competicoes[*numCompeticoes].data.dia);
    printf("Mês da competição: ");
    scanf("%d", &competicoes[*numCompeticoes].data.mes);
    printf("Ano da competição: ");
    scanf("%d", &competicoes[*numCompeticoes].data.ano);
    getchar();

    (*numCompeticoes)++;
}

void removerCompeticao(struct competicao *competicoes, int *numCompeticoes) {
    char nomeRemover[50];
    printf("Digite o nome da competição a ser removida: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    int i, j;
    for (i = 0; i < *numCompeticoes; i++) {
        if (strcmp(competicoes[i].nome, nomeRemover) == 0) {
            for (j = i; j < *numCompeticoes - 1; j++) {
                competicoes[j] = competicoes[j + 1];
            }
            (*numCompeticoes)--;
            printf("Competição removida com sucesso.\n");
            return;
        }
    }

    printf("Competição não encontrada.\n");
}

void buscarCompeticoesPorJogo(struct competicao *competicoes, int numCompeticoes) {
    char jogoBusca[50];
    printf("Informe o jogo a buscar: ");
    fgets(jogoBusca, sizeof(jogoBusca), stdin);
    jogoBusca[strcspn(jogoBusca, "\n")] = '\0';

    printf("Competições relacionadas ao jogo %s:\n", jogoBusca);
    for (int i = 0; i < numCompeticoes; i++) {
        if (strcmp(competicoes[i].jogo, jogoBusca) == 0) {
            printf("Nome: %s, ", competicoes[i].nome);
            printf("Jogo: %s, ", competicoes[i].jogo);
            printf("Data: %d/%d/%d\n", competicoes[i].data.dia, competicoes[i].data.mes, competicoes[i].data.ano);
        }
    }
}

void alocarMemoria(struct competicao **competicoes, int *tamanhoCompeticoes) {
    *tamanhoCompeticoes += 3;
    *competicoes = realloc(*competicoes, (*tamanhoCompeticoes) * sizeof(struct competicao));
    if (*competicoes == NULL) {
        printf("Erro ao alocar mais memória.\n");
        return;
    }
    printf("Memória alocada com sucesso.\n");
}

void imprimirListaCompeticoes(struct competicao *competicoes, int numCompeticoes) {
    printf("\nLista de Competições:\n");
    for (int i = 0; i < numCompeticoes; i++) {
        printf("Nome: %s, ", competicoes[i].nome);
        printf("Jogo: %s, ", competicoes[i].jogo);
        printf("Data: %d/%d/%d\n", competicoes[i].data.dia, competicoes[i].data.mes, competicoes[i].data.ano);
    }
}

int main() {
    int tamanhoCompeticoes = 3;
    struct competicao *CompeticaoUnicap = (struct competicao *)malloc(tamanhoCompeticoes * sizeof(struct competicao));

    int numCompeticoes = 0;

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar nova competição\n");
        printf("2. Remover competição\n");
        printf("3. Buscar competições por jogo\n");
        printf("4. Alocar memória\n");
        printf("5. Imprimir lista de competições\n");
        printf("0. Sair do sistema\n");
        scanf(" %d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarCompeticao(CompeticaoUnicap, &numCompeticoes, &tamanhoCompeticoes);
                break;

            case 2:
                removerCompeticao(CompeticaoUnicap, &numCompeticoes);
                break;
            
            case 3:
                buscarCompeticoesPorJogo(CompeticaoUnicap, numCompeticoes);
                break;

            case 4:
                alocarMemoria(&CompeticaoUnicap, &tamanhoCompeticoes);
                break;

            case 5:
                imprimirListaCompeticoes(CompeticaoUnicap, numCompeticoes);
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    free(CompeticaoUnicap);
    CompeticaoUnicap = NULL;

    return 0;
}
