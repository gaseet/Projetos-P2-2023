#include <stdio.h>
#include <ctype.h>

int main() {

    char opcao;
    char s1[20], s2[20];

    printf("a. Ler uma string S1 (tamanho máximo 20 caracteres);\n");
    printf("b. Imprimir o tamanho da string S1;\n");
    printf("c. Comparar a string S1 com uma nova string S2 e imprimir o resultado da comparação;\n");
    printf("d. Concatenar a string S1 com uma nova string S2 e imprimir o resultado da concatenação;\n");
    printf("e. Imprimir a string S1 de forma reversa;\n");
    printf("f. Contar quantas vezes um dado caractere aparece na string S1.\n");
    printf("g. Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2.\n");
    printf("h. Verificar se uma string S2 e substring de S1.\n");
    printf("i. Retornar uma substring da string S1.\n");
    opcao = getchar();

    opcao = tolower(opcao);

    if (opcao == 'a') {
        printf("Informe a string 1: ");
        fgets(s1, sizeof(s1), stdin);

    } else if (opcao == 'b') {

    } else if (opcao == 'c') {

    } else if (opcao == 'd') {

    } else if (opcao == 'e') {

    } else if (opcao == 'f') {

    } else if (opcao == 'g') {

    } else if (opcao == 'h') {

    } else if (opcao == 'i') {

    } 

    
    




    return 0;
}