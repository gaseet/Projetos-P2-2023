#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanho;

  printf("Digite o tamanho da string: ");
  scanf("%d", &tamanho);

  if (tamanho <= 0) {
    printf("O tamanho deve ser um número positivo.\n");
    return 1;
  }

  char* string = (char*)malloc((tamanho + 1) * sizeof(char));

  if (string == NULL) {
    printf("Erro ao alocar memória para a string.\n");
    return 1;
  }

  printf("Digite a string: ");
  getchar();
  fgets(string, tamanho + 1, stdin);

  int i, j;
  for (i = 0, j = 0; i < tamanho; i++) {
    if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u' &&
        string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U') {

            string[j++] = string[i];
            
    }
  }
  string[j] = '\0';

  printf("String sem vogais: %s\n", string);

  free(string);

  return 0;
}
