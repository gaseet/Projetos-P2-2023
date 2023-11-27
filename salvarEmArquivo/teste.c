void saveToFile(struct Agenda agenda[], int tamanho, const char *filename) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(&tamanho, sizeof(int), 1, file);
    fwrite(agenda, sizeof(struct Agenda), tamanho, file);

    fclose(file);
}

void loadFromFile(struct Agenda agenda[], int *tamanho, const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Arquivo de agenda não encontrado. Criando um novo.\n");
        return;
    }

    fread(tamanho, sizeof(int), 1, file);
    fread(agenda, sizeof(struct Agenda), *tamanho, file);

    fclose(file);
}