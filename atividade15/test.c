#include <stdio.h>

typedef enum {
  copas,
  espadas,
  paus,
  ouros
} naipe;

typedef enum {
  A,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  J,
  Q,
  K
} valor;

struct carta {
  naipe naipe;
  valor valor;
};

char *get_naipe_descricao(naipe naipe) {
  switch (naipe) {
    case copas:
      return "copas";
    case espadas:
      return "espadas";
    case paus:
      return "paus";
    case ouros:
      return "ouros";
  }
  return NULL;
}

void distribuir_cartas(struct carta *baralho, int *jogador1, int *jogador2) {
  int i, j;
  int marcadas[52];

  for (i = 0; i < 52; i++) {
    marcadas[i] = 0;
  }

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 52; j++) {
      if (!marcadas[j]) {
        marcadas[j] = 1;
        jogador1[i] = baralho[j];
        break;
      }
    }
  }

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 52; j++) {
      if (!marcadas[j]) {
        marcadas[j] = 1;
        jogador2[i] = baralho[j];
        break;
      }
    }
  }
}

int main() {
  struct carta baralho[52];
  int jogador1[5], jogador2[5];

  // Inicializar o baralho
  for (int i = 0; i < 52; i++) {
    baralho[i].naipe = (naipe)rand() % 4;
    baralho[i].valor = (valor)rand() % 13;
  }

  // Distribuir as cartas
  distribuir_cartas(baralho, jogador1, jogador2);

  // Exibir as cartas
  printf("Jogador 1:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s %d\n", get_naipe_descricao(jogador1[i].naipe), jogador1[i].valor);
  }

  printf("\nJogador 2:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s %d\n", get_naipe_descricao(jogador2[i].naipe), jogador2[i].valor);
  }

  return 0;
}
