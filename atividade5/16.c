#include <stdio.h>

int main() {

    int count = 1;
    int aprovados = 0;
    float nota;

    while (count <= 5) {
        printf("Informe a nota do aluno %d: ", count);
        scanf("%f", &nota);
        if (nota >= 7) {
            aprovados++;
        }
        count++;
    }
    printf("Foram aprovados %d aluno(s).", aprovados);
    return 0;
}
