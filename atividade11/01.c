#include <stdio.h>

int buscaBinaria(int arr[], int tamanho, int alvo, int *iteracoes) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        (*iteracoes)++;
        meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == alvo)
            return meio;

        if (arr[meio] < alvo)
            inicio = meio + 1;
        else
            fim = meio - 1;

    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 6, 7, 9, 11, 12, 14, 15};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int alvo = 11;
    int iteracoes = 0;

    int resultado = buscaBinaria(arr, tamanho, alvo, &iteracoes);

    if (resultado != -1) {
        printf("Elemento encontrado na posição %d\n", resultado);
    } else {
        printf("Elemento não encontrado na lista\n");
    }

    printf("Total de iterações: %d\n", iteracoes);

    return 0;
}
