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

        if (idade < 0) {
            break;

        }

        printf("Informe o nome: ");
        scanf("%s", nome);

        if (i == 1) {
            idadeJovem = idade;
            idadeVelho = idade;
            i = 0;
            strcpy(nomeJovem, nome);
            strcpy(nomeVelho, nome);
        }

        if (idade < idadeJovem) {
            idadeJovem = idade;
            strcpy(nomeJovem, nome);

        } else if (idade > idadeVelho) {
            idadeVelho = idade;
            strcpy(nomeVelho, nome);
        }


    }

    printf("O nome e idade da pessoa mais velha são: %s / %d\n", nomeVelho, idadeVelho);
    printf("O nome e idade da pessoa mais jovem são: %s / %d\n", nomeJovem, idadeJovem);

    return 0;
}
