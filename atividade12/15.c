#include <stdio.h>

void printMatriz(int linha, int coluna, char matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int scanMatriz(int alvo, int linha, int coluna, int matriz[linha][coluna]) {
    int encontrados = 0;
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            if (matriz[i][j] > alvo) {
                encontrados++;
            }
        }
    }
    return encontrados;
}

void calcularPontuacao(int alunos, int questoes, char respostas[alunos][questoes], char gabarito[questoes], int resultado[alunos]) {
    for(int i = 0; i < alunos; i++) {
        int pontuacao = 0;
        for(int j = 0; j < questoes; j++) {
            if(respostas[i][j] == gabarito[j]) {
                pontuacao++;
            }
        }
        resultado[i] = pontuacao;
    }
}

int main() {

    char respostas[5][10];
    char gabarito[10];
    int notas[5];

    for(int i = 0; i < 5; i++) {
        printf("Digite as respostas do aluno %d (A, B, C, D ou E): ", i+1);
        for(int j = 0; j < 10; j++) {
            scanf(" %c", &respostas[i][j]);
        }
    }

    for(int i = 0; i < 10; i++) {
    printf("Digite o Gabarito %d (A, B, C, D ou E): ", i+1);
    scanf(" %c", &gabarito[i]);
}


    calcularPontuacao(5, 10, respostas, gabarito, notas);
    printf("\nPontuação dos Alunos:\n");
    for(int i = 0; i < 5; i++) {
        printf("Aluno %d: %d/%d pontos\n", i+1, notas[i], 10);
    }


    return 0;
}
