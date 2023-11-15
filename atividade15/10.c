#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Carta {
    char naipe[10];
    int valor;
};

const char *get_nome_carta(int valor) {
    switch (valor) {
        case 1: return "Ás";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "10";
        case 11: return "Valete";
        case 12: return "Dama";
        case 13: return "Rei";
    }
}

void exibirCarta(struct Carta carta) {
    printf("%s de %s\n", get_nome_carta(carta.valor), carta.naipe);
}

int cartaJaDistribuida(struct Carta carta, struct Carta jogador[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        if (jogador[i].valor == carta.valor && strcmp(jogador[i].naipe, carta.naipe) == 0) {
            return 1;
        }
    }
    return 0;
}

void inicializarBaralho(struct Carta baralho[]) {
    char naipes[][10] = {"Copas", "Ouros", "Paus", "Espadas"};
    int valores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    int index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            strcpy(baralho[index].naipe, naipes[i]);
            baralho[index].valor = valores[j];
            ++index;
        }
    }
}

void embaralharBaralho(struct Carta baralho[], int tamanho) {
    srand(time(NULL));
    for (int i = tamanho - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        struct Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

int main() {
    struct Carta baralho[52];
    struct Carta jogador1[5];
    struct Carta jogador2[5];

    inicializarBaralho(baralho);
    embaralharBaralho(baralho, 52);

    for (int i = 0; i < 5; ++i) {
        do {
            jogador1[i] = baralho[i];
        } while (cartaJaDistribuida(jogador1[i], jogador1, i));

        do {
            jogador2[i] = baralho[i + 5];
        } while (cartaJaDistribuida(jogador2[i], jogador2, i));
    }

    printf("Cartas do Jogador 1:\n");
    for (int i = 0; i < 5; ++i) {
        exibirCarta(jogador1[i]);
    }

    printf("\nCartas do Jogador 2:\n");
    for (int i = 0; i < 5; ++i) {
        exibirCarta(jogador2[i]);
    }

    return 0;
}
