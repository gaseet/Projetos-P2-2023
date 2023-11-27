#include <stdio.h>

int main() {
    FILE *arquivo = fopen("info.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.");
        return 1;
    }

    printf("\nConteúdo do arquivo:\n");

    char line[100]; // Assuming each line has at most 100 characters
    while (fgets(line, sizeof(line), arquivo) != NULL) {
        printf("%s", line);
    }

    fclose(arquivo);

    printf("\nFinal do programa.");

    return 0;
}
