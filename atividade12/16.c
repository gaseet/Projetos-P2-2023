#include <stdio.h>

void alunosPiorNota(int matriz[10][3]) {
    int piorP1 = 0, piorP2 = 0, piorP3 = 0;
    for(int i = 0; i < 10; i++) {
        if(matriz[i][1] < matriz[i][0] && matriz[i][1] < matriz[i][2]) {
            piorP2++;
        } else if(matriz[i][2] < matriz[i][0] && matriz[i][2] < matriz[i][1]) {
            piorP3++;
        } else if(matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
            piorP1++;
        } else {
            piorP1++;
        }

    }
    printf("Piores notas na prova 1: %d alunos\n", piorP1);
    printf("Piores notas na prova 2: %d alunos\n", piorP2);
    printf("Piores notas na prova 3: %d alunos\n", piorP3);
}

int main() {

    int notas[10][3];

    for(int i = 0; i < 10; i++) {
        printf("Digite as notas do aluno %d na ordem Prova1, Prova2 e Prova3: ", i+1);
        for(int j = 0; j < 3; j++) {
            scanf("%d", &notas[i][j]);
        }
    }

    alunosPiorNota(notas);

    return 0;
}
