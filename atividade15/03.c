#include <stdio.h>

struct aluno {
    char nome[100];
    int matricula;
    char curso[100];
};

int main() {

    struct aluno a[5];

    for(int i = 0; i < 5; i++) {
        printf("Informe o nome do aluno %d: ", i + 1);
        fgets(a[i].nome, sizeof(a[i].nome), stdin);

        printf("Informe a matrícula do aluno %d: ", i + 1);
        scanf(" %d", &a[i].matricula);

        getchar();

        printf("Informe o curso do aluno %d: ", i + 1);
        fgets(a[i].curso, sizeof(a[i].curso), stdin);
    }

    for(int i = 0; i < 5; i++) {
        printf("Nome do aluno %d: %s", i + 1, a[i].nome);

        printf("Matrícula do aluno %d: %d\n", i + 1, a[i].matricula);

        printf("Curso do aluno %d: %s", i + 1, a[i].curso);

        printf("\n");
    }

    return 0;
}