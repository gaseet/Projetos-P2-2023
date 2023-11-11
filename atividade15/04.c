#include <stdio.h>
#include <string.h>

#define TAMANHO 5

struct aluno {
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
    float media;
    int aprovado;
};

int main() {

    struct aluno a[TAMANHO];

    for(int i = 0; i < TAMANHO; i++) {

        printf("Informe a matrícula do aluno %d: ", i);
        scanf(" %d", &a[i].matricula);
        getchar();

        printf("Informe o nome do aluno %d: ", i);
        fgets(a[i].nome, sizeof(a[i].nome), stdin);

        printf("Informe a nota 1 do aluno %d: ", i);
        scanf(" %f", &a[i].nota1);
        getchar();

        printf("Informe a nota 2 do aluno %d: ", i);
        scanf(" %f", &a[i].nota2);
        getchar();

        printf("Informe a nota 3 do aluno %d: ", i + 1);
        scanf(" %f", &a[i].nota3);
        getchar();

        printf("\n");
    }

    //REMOVE '\n' DOS NOMES
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < strlen(a[i].nome); j++) {
            if(a[i].nome[j] == '\n') {
                a[i].nome[j] = '\0';
            }
        }
    }

    //CALCULA MEDIA E ATRIBUI APROVADO OU NAO
    for(int i = 0; i < TAMANHO; i++) {
        a[i].media = (a[i].nota1 + a[i].nota2 + a[i].nota3) / 3;
        if (a[i].media >= 6) {
            a[i].aprovado = 1;
        }
    }

    float  maiorP1 = 0,               menor_media = 0,               maior_media = 0;
    int    matricula_aluno_maiorP1,   matricula_aluno_menor_media,   matricula_aluno_maior_media;
    char   nome_aluno_maiorP1[100],   nome_aluno_menor_media[100],   nome_aluno_maior_media[100];
    int    id_maiorP1,                id_menor_media,                id_maior_media;

    //ATRIBUICAO DE: MAIOR P1, MAIOR MEDIA, MENOR MEDIA.
    for(int i = 0; i < TAMANHO; i++) {
        if (i == 0) {
            maiorP1 = a[i].nota1;
            matricula_aluno_maiorP1 = a[i].matricula;
            strcpy(nome_aluno_maiorP1, a[i].nome);
            id_maiorP1 = i;

            menor_media = a[i].media;
            matricula_aluno_menor_media = a[i].matricula;
            strcpy(nome_aluno_menor_media, a[i].nome);
            id_menor_media = i;

            maior_media = a[i].media;
            matricula_aluno_maior_media = a[i].matricula;
            strcpy(nome_aluno_maior_media, a[i].nome);
            id_maior_media = i;

        } else {
            if (a[i].nota1 > maiorP1) {
                maiorP1 = a[i].nota1;
                matricula_aluno_maiorP1 = a[i].matricula;
                strcpy(nome_aluno_maiorP1, a[i].nome);
            }
            if (a[i].media < menor_media) {
                menor_media = a[i].media;
                matricula_aluno_menor_media = a[i].matricula;
                strcpy(nome_aluno_menor_media, a[i].nome);
            }
            if (a[i].media > maior_media) {
                maior_media = a[i].media;
                matricula_aluno_maior_media = a[i].matricula;
                strcpy(nome_aluno_maior_media, a[i].nome);
            }
        }
    }

    printf("Aluno com maior nota da prova 1: %s, (Matrícula %d) com %f pontos.\n", nome_aluno_maiorP1, matricula_aluno_maiorP1, a[id_maiorP1].nota1);

    printf("Aluno com maior média geral: %s, (Matrícula %d) com %f pontos.\n", nome_aluno_maior_media, matricula_aluno_maior_media, maior_media);

    printf("Aluno com menor média geral: %s, (Matrícula %d) com %f pontos.\n", nome_aluno_menor_media, matricula_aluno_menor_media, menor_media);

    printf("\n");

    for(int i = 0; i < TAMANHO; i++) {

        printf("Matrícula do aluno %d: %d\n", i, a[i].matricula);

        printf("Nome do aluno %d: %s\n", i, a[i].nome);

        printf("Média geral do aluno: %f\n", a[i].media);

        printf("Status: \n");

        if(a[i].aprovado == 1) {
            printf("Aprovado.\n");
        } else {
            printf("Reprovado.\n");
        }

        printf("\n");
    }

    return 0;
}