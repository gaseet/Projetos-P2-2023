#include <stdio.h>

void printMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void notaFinal(int linha, int coluna, int matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++){
        int soma = 0;
        for(int j = 1; j < coluna - 1; j++) {
            soma += matriz[i][j];
        }
        matriz[i][coluna - 1] = soma;
    }
}

void maiorNotaFinal(int linha, int coluna, int matriz[linha][coluna]) {
    int maior = matriz[0][coluna-1];
    int matricula = 0;
    for (int i = 0; i < linha; i++){
        if (matriz[i][coluna-1] > maior) {
            maior = matriz[i][coluna-1];
            matricula = matriz[i][0];
        }
    }
    printf("A matrícula do aluno com a maior nota final é: %d\n", matricula);
}

void mediaNotasFinais(int linha, int coluna, int matriz[linha][coluna]) {
    float media = 0;
    for (int i = 0; i < linha; i++) {
            media += matriz[i][coluna-1];
        }
    media = media / linha;
    printf("A média entre as notas finais de todos os alunos é: %.2f\n", media);
    }

int main(){

    int linha = 5;
    int coluna = 4;
    int soma;

    //matriz[LINHA][COLUNA]
    int matriz[5][4];
    
    /*  
        Primeira coluna: número de matrícula;
        Segunda coluna: média das provas;
        Terceira coluna: média dos trabalhos;
        Quarta coluna: nota final.
    */

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                printf("Informe o número da matrícula do aluno %d: ", i+1);
            } else if (j == 1) {
                printf("Informe a média das provas do aluno %d: ", i+1);
            } else if (j == 2) {
                printf("Informe a média dos trabalhos do aluno %d: ", i+1);
            }
            scanf("%d", &matriz[i][j]);
        }
    }

    notaFinal(linha, coluna, matriz);
    maiorNotaFinal(linha, coluna, matriz);
    mediaNotasFinais(linha, coluna, matriz);

    return 0;
}