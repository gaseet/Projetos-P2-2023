#include <stdio.h>
#include <string.h>

int main() {
    char mensagem[21];
    
    int opcao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Escrever uma mensagem\n");
        printf("2. Concatenar mensagens\n");
        printf("3. Inverter a mensagem\n");
        printf("4. Substituir caracteres\n");
        printf("5. Verificar se é uma substring\n");
        printf("6. Retornar uma substring\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1: {
                printf("Digite uma mensagem (até 20 caracteres): ");
                fgets(mensagem, sizeof(mensagem), stdin);
                strtok(mensagem, "\n");
                break;
            }
            case 2: {
                char mensagem2[20];

                printf("Digite a nova mensagem para concatenar: ");
                fgets(mensagem2, sizeof(mensagem2), stdin);
                strtok(mensagem2, "\n");

                strcat(mensagem, mensagem2);
                printf("Mensagem concatenada: %s\n", mensagem);
                break;
            }
            case 3: {
                printf("Mensagem invertida: %s\n", strrev(mensagem));
                break;
            }
            case 4: {
                char c1, c2;

                printf("Digite o caractere a ser substituído: ");
                scanf(" %c", &c1);
                getchar();

                printf("Digite o caractere que vai substituir: ");
                scanf(" %c", &c2);
                getchar();

                for(int i = 0; i < strlen(mensagem); i++) {
                    if(mensagem[i] == c1) {
                        mensagem[i] = c2;
                    }
                }
                printf("Mensagem com substituição: %s\n", mensagem);
                break;
            }
            case 5: {
                char mensagem2[20];

                printf("Digite a nova mensagem para verificar se é uma substring: ");
                fgets(mensagem2, sizeof(mensagem2), stdin);
                strtok(mensagem2, "\n");

                if(strstr(mensagem, mensagem2) != NULL) {
                    printf("%s é uma substring da mensagem original.\n", mensagem2);
                } else {
                    printf("%s não é uma substring da mensagem original.\n", mensagem2);
                }
                break;
            }
            case 6: {
                int posicao, tamanho;

                printf("Digite a posição inicial: ");
                scanf("%d", &posicao);
                getchar();

                printf("Digite o tamanho desejado: ");
                scanf("%d", &tamanho);
                getchar();
                
                for (int i = posicao; i < tamanho; i++) {
                    printf("%c", mensagem[i]);
                }
                break;
            }
            case 0:
                printf("Encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
