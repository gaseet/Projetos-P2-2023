#include <stdio.h>

int main() {

    int notas[5];
    int count = 0;

    for(int i = 0; i <= 5; i++) {
        printf("Digite a nota do aluno %d:\n", i+1);
        scanf("%d", &notas[i]);

        if (notas[i] >= 7) {
            count++;
        }
    }    
    printf("%d alunos foram aprovados.", count);

    return 0;
}