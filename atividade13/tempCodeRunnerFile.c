/* 19. Escreva um programa que leia a idade e o primeiro nome de várias pessoas. Seu programa deve
terminar quando uma idade negativa for digitada. Ao terminar, seu programa deve escrever o nome
e a idade das pessoas mais jovens e mais velhas.
 */

#include <stdio.h>
#include <string.h>

int main() {

    char nome[30];
    int idade, i = 1;

    char nomeJovem[30], nomeVelho[30];
    int idadeJovem = 200, idadeVelho = 0;


    while(1) {
        printf("Informe a idade: ");
        scanf("%d", &idade);

        if (i == 1) {
            idadeJovem = idade;
            idadeVelho = idade;
            i = 0;
        }

        if (idade < 0) {
            break;

        } else if (idade < idadeJovem) {
            idadeJovem = idade;
            strcpy(nomeJovem, nome);

        } else if (idade > idadeVelho) {
            idadeVelho = idade;
            strcpy(nomeVelho, nome);
        }
    }

    printf("O nome e idade da pessoa mais velha são: %s / %d", nomeVelho, idadeVelho);
    printf("O nome e idade da pessoa mais jovem são: %s / %d", nomeJovem, idadeJovem);

    return 0;
}