#include <stdio.h>
#include <string.h>

#define TAMANHO 2

struct Livro {
    char titulo[30];
    char autor[15];
    int ano;
};

void buscarLivroPorTitulo(struct Livro livros[], int numLivros, char tituloBusca[]) {
    int encontrados = 0;

    for (int i = 0; i < numLivros; ++i) {
        if (strstr(livros[i].titulo, tituloBusca) != NULL) {
            printf("Livro encontrado:\n");
            printf("Título: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano: %d\n", livros[i].ano);
            printf("\n");
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com o título \"%s\".\n", tituloBusca);
    }
}

int main() {
    struct Livro livros[TAMANHO];

    for (int i = 0; i < TAMANHO; ++i) {
        printf("Digite os dados do livro %d:\n", i + 1);
        printf("Título (máximo 30 letras): ");
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';

        printf("Autor (máximo 15 letras): ");
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';

        printf("Ano: ");
        scanf("%d", &livros[i].ano);
        getchar();
        printf("\n");
    }

    char tituloBusca[30];
    do {
        printf("Digite parte do título do livro que deseja buscar: ");
        fgets(tituloBusca, sizeof(tituloBusca), stdin);
        tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

        buscarLivroPorTitulo(livros, TAMANHO, tituloBusca);

        char resposta;
        printf("Deseja buscar outro livro? (s/n): ");
        scanf(" %c", &resposta);
        getchar();

        if (resposta != 's' && resposta != 'S') {
            break;
        }
    } while (1); 

    return 0;
}
