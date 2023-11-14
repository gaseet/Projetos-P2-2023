#include <stdio.h>

struct Aluno {
    char nome[50];
    int matricula;
    float media_final;
};

#define TAMANHO 10

int main() {
    struct Aluno alunos[TAMANHO];

    for (int i = 0; i < TAMANHO; ++i) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Digite a media final do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].media_final);
    }

    struct Aluno aprovados[TAMANHO];
    struct Aluno reprovados[TAMANHO];

    int contador_aprovados = 0;
    int contador_reprovados = 0;

    for (int i = 0; i < TAMANHO; ++i) {
        if (alunos[i].media_final >= 5.0) {
            aprovados[contador_aprovados] = alunos[i];
            contador_aprovados++;
        } else {
            reprovados[contador_reprovados] = alunos[i];
            contador_reprovados++;
        }
    }

    printf("\nAlunos Aprovados:\n");
    for (int i = 0; i < contador_aprovados; ++i) {
        printf("Nome: %s\n", aprovados[i].nome);
        printf("Matricula: %d\n", aprovados[i].matricula);
        printf("Media Final: %.2f\n", aprovados[i].media_final);
        printf("\n");
    }

    printf("\nAlunos Reprovados:\n");
    for (int i = 0; i < contador_reprovados; ++i) {
        printf("Nome: %s\n", reprovados[i].nome);
        printf("Matricula: %d\n", reprovados[i].matricula);
        printf("Media Final: %.2f\n", reprovados[i].media_final);
        printf("\n");
    }

    return 0;
}
