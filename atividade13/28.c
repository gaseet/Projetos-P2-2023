#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    char opcao;
    char s1[20], s2[20];
    char c1, c2;

    do {
        printf("\nMenu:\n");
        printf("A. Ler uma string S1\n");
        printf("B. Imprimir o tamanho da string S1\n");
        printf("C. Comparar a string S1 com uma nova string S2\n");
        printf("D. Concatenar a string S1 com uma nova string S2\n");
        printf("E. Imprimir a string S1 de forma reversa\n");
        printf("F. Contar quantas vezes um dado caractere aparece na string S1\n");
        printf("G. Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2\n");
        printf("H. Verificar se uma string S2 é substring de S1\n");
        printf("I. Retornar uma substring da string S1\n");
        printf("Z. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'a':
                getchar();
                printf("Opção A selecionada.\n");
                printf("Informe a string S1: ");

                fgets(s1, sizeof(s1), stdin);
                strtok(s1, "\n");

                break;
            case 'b':
                getchar();
                printf("Opção B selecionada.\n");

                printf("Tamanho da string S1: %d\n", strlen(s1));
                
                break;
            case 'c':
                getchar();
                printf("Opção C selecionada.\n");
                printf("Informe a nova string S2: ");
                fgets(s2, sizeof(s2), stdin);
                strtok(s2, "\n");

                if (strcmp(s1, s2) == 0) {
                    printf("As duas strings são iguais.\n");
                } else {
                    printf("As duas strings são diferentes.\n");
                }
                
                break;
            case 'd':
                getchar();
                printf("Opção D selecionada.\n");
                printf("Informe a nova string S2: ");
                fgets(s2, sizeof(s2), stdin);
                strtok(s2, "\n");

                printf("Resultado da concatenação: %s\n", strcat(s1, s2));
                break;
            case 'e':
                getchar();
                printf("Opção E selecionada.\n");
                printf("S1 de forma reversa: %s\n", strrev(s1));
                break;
            case 'f':
                int cont;
                getchar();
                printf("Opção F selecionada.\n");
                printf("Informe um caractere: ");
                scanf(" %c", &c1);
                for(int i = 0; i < strlen(s1); i++) {
                    if (s1[i] == c1) {
                        cont++;
                    }
                }
                printf("O caractere %c aparece %d vezes em S1.\n", c1, cont);
                
                break;
            case 'g':
                int ocorreu;
                getchar();
                printf("Opção G selecionada.\n");
                printf("Informe o caractere a ser substituído (C1): ");
                scanf(" %c", &c1);
                getchar();
                printf("Informe o novo caractere (C2): ");
                scanf(" %c", &c2);
                for(int i = 0; i < strlen(s1); i++) {
                    if (ocorreu == 0 && s1[i] == c1) {
                        s1[i] = c2;
                        ocorreu = 1;
                    }
                }
                printf("S1 após a substituição: %s\n", s1);
                
                break;
            case 'h':
                getchar();
                printf("Opção H selecionada.\n");
                printf("Informe a string S2: ");
                fgets(s2, sizeof(s2), stdin);
                strtok(s2, "\n");

                if(strstr(s1, s2) != NULL) {
                    printf("S2 é substring de S1.\n");
                } else {
                    printf("S2 NÃO é substring de S1.\n");
                }
                
                break;
            case 'i':
                getchar();
                printf("Opção I selecionada.\n");
                int pos, tam;
                printf("Informe a posição inicial: ");
                scanf("%d", &pos);
                printf("Informe o tamanho da substring: ");
                scanf("%d", &tam);

                if ((pos + tam) > strlen(s1)) {
                    printf("Dimensões excedem tamanho de S1 (Posição inicial + tamanho da sub deve ser MENOR ou IGUAL ao tamanho de S1.)");
                } else {
                    printf("Substring no intervalo [%d, %d]: ", pos, tam - 1);
                    for(int i = pos; i < tam; i++) {
                        printf("%c", s1[i]);
                    }
                }

                printf("\n");

                break;
            case 'z':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &opcao);

    } while (tolower(opcao) == 's' && tolower(opcao) != 'z');

    return 0;
}
