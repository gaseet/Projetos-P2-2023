struct nota {
    float nota1;
    float nota2;
    float mediaFinal;
};

struct aluno {
    int matricula;
    char nome[100];
    int codigoDisciplina;
    struct nota nota;
};

#include <stdio.h>
#include <string.h>

#define TAMANHO 10

int main() {

    struct aluno alunos[TAMANHO];

    for(int i = 0; i < TAMANHO; i++) {
        printf("Informe o nome do aluno %d: ", i);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Informe a matrícula do aluno %d: ", i);
        scanf(" %d", &alunos[i].matricula);
        getchar();

        printf("Informe a nota 1 do aluno %d: ", i);
        scanf(" %f", &alunos[i].nota.nota1);
        getchar();

        printf("Informe a nota 2 do aluno %d: ", i);
        scanf(" %f", &alunos[i].nota.nota2);
        getchar();

        alunos[i].nota.mediaFinal = ((alunos[i].nota.nota1 * 1) + (alunos[i].nota.nota2 * 2)) / 3;
    }

    //REMOVE '\n' DOS NOMES
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < strlen(alunos[i].nome); j++) {
            if(alunos[i].nome[j] == '\n') {
                alunos[i].nome[j] = '\0';
            }
        }
    }

    printf("LISTAGEM: \n");

    for(int i = 0; i < TAMANHO; i++) {
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Matrícula: %.2f\n", alunos[i].nota.mediaFinal);
        printf("\n");
    }

    return 0;
}