#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    char continuar = 's';
    printf("Informe o tamanho do vetor a ser criado: \n");
    scanf("%d", &tamanho);

    int *numeros = (int *)calloc(tamanho, sizeof(int));

    if (numeros == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1;
    }

    while (continuar == 's') {
        
        char opcao;
        
        printf("Opções: \n");
        printf("a. Inserir um valor em uma determinada posição\n");
        printf("b. Consultar o valor contido em uma determinada posição\n");
        getchar();
        opcao = getchar();

        if (opcao == 'a' || opcao == 'A') {
            int posicao, num;

            printf("Informe a posição que deseja inserir o número (0 a %d): \n", tamanho - 1);
            scanf("%d", &posicao);

            printf("Informe o número a inserir na posição: \n");
            scanf("%d", &num);

            numeros[posicao] = num;

        } else if (opcao == 'b' || opcao == 'B') {
            int posicao;

            printf("Informe a posição que deseja consultar (0 a %d): \n", tamanho - 1);
            scanf("%d", &posicao);

            printf("O número guardado na posição informada é: %d\n", numeros[posicao]);
            
        } else {
            printf("Opção inválida.\n");
        }
        printf("Deseja continuar? (s/n)\n");
        getchar();
        scanf("%c", &continuar);
    }

    free(numeros);
    numeros = NULL;

    return 0;
}
