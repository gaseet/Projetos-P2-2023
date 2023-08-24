#include <stdio.h>
#include <stdlib.h>
int main(){

    char ch;
    printf("Digite um sinal de pontuação: ");
    ch = getchar();
    switch(ch){
        case '.': printf("Ponto.\n"); break ;
        case ',': printf("Vírgula.\n"); break ;
        case ':': printf("Dois pontos.\n"); break ;
        case ';': printf("Ponto e vírgula.\n"); break ;
        default : printf("Sinal não reconhecido.\n");
    }

    return 0;
}