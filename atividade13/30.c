#include <stdio.h>
#include <string.h>

int main() {
    char nomes[5][50];
    int quantidade_alunos = 0;
    char continuar;

    do {
        char nome[50];
        printf("Informe o nome do aluno (ou digite 'fim' para encerrar): ");
        scanf("%s", nome);

        if (strcmp(nome, "fim") == 0) {
            break;
        }

        if (quantidade_alunos < 5) {
            strcpy(nomes[quantidade_alunos], nome);
            quantidade_alunos++;
        } else {
            printf("A lista de alunos está cheia.\n");
            break;
        }

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    char nome_busca[50];
    printf("\nDigite um nome (ou parte do nome) para buscar na lista: ");
    scanf("%s", nome_busca);

    int encontrado = 0;
    for (int i = 0; i < quantidade_alunos; i++) {
        if (strstr(nomes[i], nome_busca) != NULL) {
            printf("\nNome encontrado na posição %d: %s\n", i, nomes[i]);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNome não encontrado na lista.\n");
    }

    return 0;
}
