#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Endereco {
    char pais[50];
    char estado[50];
    char cidade[50];
    char bairro[50];
    char rua[100];
    char numero[50];
    char complemento[100];
    char cep[20];
};

struct Telefone {
    int ddd;
    char numero[20];
};

struct Nascimento {
    int dia;
    int mes;
    int ano;
};

struct Agenda {
    char nome[100];
    char email[50];
    struct Endereco endereco;
    struct Telefone telefone;
    struct Nascimento nascimento;
    char observacao[200];
    int id;
};

void saveToFile(struct Agenda agenda[], int tamanho, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%s,%d,%d,%d,%s\n",
                agenda[i].id,
                agenda[i].nome,
                agenda[i].email,
                agenda[i].endereco.pais,
                agenda[i].endereco.estado,
                agenda[i].endereco.cidade,
                agenda[i].endereco.bairro,
                agenda[i].endereco.rua,
                agenda[i].endereco.numero,
                agenda[i].endereco.complemento,
                agenda[i].endereco.cep,
                agenda[i].telefone.ddd,
                agenda[i].telefone.numero,
                agenda[i].nascimento.dia,
                agenda[i].nascimento.mes,
                agenda[i].nascimento.ano,
                agenda[i].observacao);
    }

    fclose(file);
}

void loadFromFile(struct Agenda agenda[], int *tamanho, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    *tamanho = 0;

    char linha[1024];

    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (sscanf(linha, "%d,%99[^,],%99[^,],%99[^,],%99[^,],%99[^,],%99[^,],%99[^,],%99[^,],%99[^,],%99[^,],%d,%99[^,],%d,%d,%d,%99[^\n]",
                   &agenda[*tamanho].id,
                   agenda[*tamanho].nome,
                   agenda[*tamanho].email,
                   agenda[*tamanho].endereco.pais,
                   agenda[*tamanho].endereco.estado,
                   agenda[*tamanho].endereco.cidade,
                   agenda[*tamanho].endereco.bairro,
                   agenda[*tamanho].endereco.rua,
                   agenda[*tamanho].endereco.numero,
                   agenda[*tamanho].endereco.complemento,
                   agenda[*tamanho].endereco.cep,
                   &agenda[*tamanho].telefone.ddd,
                   agenda[*tamanho].telefone.numero,
                   &agenda[*tamanho].nascimento.dia,
                   &agenda[*tamanho].nascimento.mes,
                   &agenda[*tamanho].nascimento.ano,
                   agenda[*tamanho].observacao) == 17) {

            (*tamanho)++;
        }
    }

    fclose(file);
}

void buscaPorNome(struct Agenda agenda[], int tamanho, char nomeBusca[100]) {
    for (int i = 0; nomeBusca[i]; i++) {
        nomeBusca[i] = toupper(nomeBusca[i]);
    }

    printf("---------------------------\n");
    printf("Resultados da busca por \"%s\":\n", nomeBusca);
    printf("---------------------------\n");

    int encontrou = 0;

    
    for (int i = 0; i < tamanho; i++) {
        if (strstr(agenda[i].nome, nomeBusca) != NULL) {
            printf("ID: %d\n", agenda[i].id);
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Endereço: %s, %s - %s, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero,
                   agenda[i].endereco.complemento, agenda[i].endereco.bairro, agenda[i].endereco.cep,
                   agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
            printf("Telefone: (%d) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de Aniversário: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes,
                   agenda[i].nascimento.ano);
            printf("Observações: %s\n", agenda[i].observacao);
            printf("---------------------------\n");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma pessoa encontrada na agenda com o nome \"%s\".\n", nomeBusca);
    }
}

void buscaPorMesAniversario(struct Agenda agenda[], int tamanho, int mesBusca) {
    if (mesBusca < 1 || mesBusca > 12) {
        printf("Mês inválido. O mês deve estar entre 1 e 12.\n");
        return;
    }

    printf("---------------------------\n");
    printf("Pessoas que fazem aniversário no mês %d:\n", mesBusca);
    printf("---------------------------\n");

    int encontrou = 0;

    for (int i = 0; i < tamanho; i++) {
        if (agenda[i].nascimento.mes == mesBusca) {
            printf("ID: %d\n", agenda[i].id);
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Endereço: %s, %s - %s, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero,
                   agenda[i].endereco.complemento, agenda[i].endereco.bairro, agenda[i].endereco.cep,
                   agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
            printf("Telefone: (%d) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de Aniversário: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes,
                   agenda[i].nascimento.ano);
            printf("Observações: %s\n", agenda[i].observacao);
            printf("---------------------------\n");
            
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma pessoa faz aniversário no mês %d.\n", mesBusca);
        printf("---------------------------\n");
    }
}

void buscaPorDiaMesAniversario(struct Agenda agenda[], int tamanho, int diaBusca, int mesBusca) {
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("---------------------------\n");
    printf("Pessoas que fazem aniversário em %d/%d:\n", diaBusca, mesBusca);
    printf("---------------------------\n");
    
    int encontrou = 0;

    for (int i = 0; i < tamanho; i++) {
        if (agenda[i].nascimento.dia == diaBusca && agenda[i].nascimento.mes == mesBusca) {
            printf("ID: %d\n", agenda[i].id);
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Endereço: %s, %s - %s, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero,
                   agenda[i].endereco.complemento, agenda[i].endereco.bairro, agenda[i].endereco.cep,
                   agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
            printf("Telefone: (%d) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de Aniversário: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes,
                   agenda[i].nascimento.ano);
            printf("Observações: %s\n", agenda[i].observacao);
            printf("---------------------------\n");

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma pessoa faz aniversário em %d/%d.\n", diaBusca, mesBusca);
        printf("---------------------------\n");
    }
}

void inserePessoa(struct Agenda agenda[], int *tamanho, struct Agenda novaPessoa, int posicao, int idAtual) {
    int i;

    if (posicao == 1 || posicao == 2) {
        for (i = 0; novaPessoa.nome[i]; i++) {
            novaPessoa.nome[i] = toupper(novaPessoa.nome[i]);
        }

        if (posicao == 1) {
            for (i = *tamanho; i > 0; i--) {
                agenda[i] = agenda[i - 1];
            }
            i = 0;
        } else {
            
            i = *tamanho;
        }

        strcpy(agenda[i].nome, novaPessoa.nome);
        strcpy(agenda[i].email, novaPessoa.email);
        agenda[i].endereco = novaPessoa.endereco;
        agenda[i].telefone = novaPessoa.telefone;
        agenda[i].nascimento = novaPessoa.nascimento;
        strcpy(agenda[i].observacao, novaPessoa.observacao);
        agenda[i].id = idAtual;

        (*tamanho)++;

        printf("Pessoa inserida com sucesso!\n");
    } else {
        printf("Opção inválida para a posição de inserção.\n");
    }
}

void retiraPessoa(struct Agenda agenda[], int *tamanho, int idBusca) {
    int i, j;

    for (i = 0; i < *tamanho; i++) {
        if (agenda[i].id == idBusca) {
            for (j = i; j < *tamanho - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            
            (*tamanho)--;
            
            printf("Pessoa removida com sucesso!\n");
            return;
        }
    }

    printf("Pessoa não encontrada na agenda.\n");
}

void imprimeAgenda(struct Agenda agenda[], int tamanho, int opcao) {
    if (opcao == 1) {
        printf("---------------------------\n");
        printf("Lista de Contatos (Primeiros 5):\n");
        printf("---------------------------\n");
        for (int i = 0; i < 5; i++) {
            printf("ID: %d\n", agenda[i].id);
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Endereço: %s, %s - %s, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero,
                   agenda[i].endereco.complemento, agenda[i].endereco.bairro, agenda[i].endereco.cep,
                   agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
            printf("Telefone: (%d) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de Aniversário: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes,
                   agenda[i].nascimento.ano);
            printf("Observações: %s\n", agenda[i].observacao);
            printf("---------------------------\n");
        }
    } else if (opcao == 2) {
        printf("---------------------------\n");
        printf("Lista de Contatos (Últimos 5):\n");
        printf("---------------------------\n");
        int startIdx = tamanho < 5 ? 0 : tamanho - 5;
        for (int i = startIdx; i < tamanho; i++) {
            printf("ID: %d\n", agenda[i].id);
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Endereço: %s, %s - %s, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero,
                   agenda[i].endereco.complemento, agenda[i].endereco.bairro, agenda[i].endereco.cep,
                   agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
            printf("Telefone: (%d) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de Aniversário: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes,
                   agenda[i].nascimento.ano);
            printf("Observações: %s\n", agenda[i].observacao);
            printf("---------------------------\n");
        }
    } else if (opcao == 3) {
        printf("---------------------------\n");
        printf("Lista de Contatos (Todos):\n");
        printf("---------------------------\n");
        for (int i = 0; i < tamanho; i++) {
            printf("ID: %d\n", agenda[i].id);
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Endereço: %s, %s - %s, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero,
                   agenda[i].endereco.complemento, agenda[i].endereco.bairro, agenda[i].endereco.cep,
                   agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
            printf("Telefone: (%d) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de Aniversário: %d/%d/%d\n", agenda[i].nascimento.dia, agenda[i].nascimento.mes,
                   agenda[i].nascimento.ano);
            printf("Observações: %s\n", agenda[i].observacao);
            printf("---------------------------\n");
        }
    } else {
        printf("Opção inválida para imprimir a agenda.\n");
    }
}

void editarPessoa(struct Agenda agenda[], int tamanho, int idBusca) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if (agenda[i].id == idBusca) {
            printf("Editando informações para a pessoa com ID %d:\n", idBusca);

            printf("Escolha o que deseja editar:\n");
            printf("1. Nome\n");
            printf("2. E-mail\n");
            printf("3. País\n");
            printf("4. Estado\n");
            printf("5. Cidade\n");
            printf("6. Bairro\n");
            printf("7. Rua\n");
            printf("8. Número\n");
            printf("9. Complemento\n");
            printf("10. CEP\n");
            printf("11. DDD\n");
            printf("12. Número de telefone\n");
            printf("13. Dia de Nascimento\n");
            printf("14. Mês de Nascimento\n");
            printf("15. Ano de Nascimento\n");
            printf("16. Observações\n");
            printf("0. Sair\n");

            int opcaoEdicao;
            scanf("%d", &opcaoEdicao);
            getchar();

            switch (opcaoEdicao) {
                case 1:
                    printf("Digite o novo nome: ");
                    fgets(agenda[i].nome, sizeof(agenda[i].nome), stdin);
                    agenda[i].nome[strcspn(agenda[i].nome, "\n")] = '\0';

                    for(int j = 0; agenda[i].nome[j] != '\0'; j++) {
                        agenda[i].nome[j] = toupper(agenda[i].nome[j]);
                    }

                    break;

                case 2:
                    printf("Digite o novo e-mail: ");
                    fgets(agenda[i].email, sizeof(agenda[i].email), stdin);
                    agenda[i].email[strcspn(agenda[i].email, "\n")] = '\0';
                    break;

                case 3:
                    printf("Digite o novo país: ");
                    fgets(agenda[i].endereco.pais, sizeof(agenda[i].endereco.pais), stdin);
                    agenda[i].endereco.pais[strcspn(agenda[i].endereco.pais, "\n")] = '\0';
                    break;

                case 4:
                    printf("Digite o novo estado: ");
                    fgets(agenda[i].endereco.estado, sizeof(agenda[i].endereco.estado), stdin);
                    agenda[i].endereco.estado[strcspn(agenda[i].endereco.estado, "\n")] = '\0';
                    break;

                case 5:
                    printf("Digite a nova cidade: ");
                    fgets(agenda[i].endereco.cidade, sizeof(agenda[i].endereco.cidade), stdin);
                    agenda[i].endereco.cidade[strcspn(agenda[i].endereco.cidade, "\n")] = '\0';
                    break;

                case 6:
                    printf("Digite o novo bairro: ");
                    fgets(agenda[i].endereco.bairro, sizeof(agenda[i].endereco.bairro), stdin);
                    agenda[i].endereco.bairro[strcspn(agenda[i].endereco.bairro, "\n")] = '\0';
                    break;

                case 7:
                    printf("Digite a nova rua: ");
                    fgets(agenda[i].endereco.rua, sizeof(agenda[i].endereco.rua), stdin);
                    agenda[i].endereco.rua[strcspn(agenda[i].endereco.rua, "\n")] = '\0';
                    break;

                case 8:
                    printf("Digite o novo número: ");
                    fgets(agenda[i].endereco.numero, sizeof(agenda[i].endereco.numero), stdin);
                    agenda[i].endereco.numero[strcspn(agenda[i].endereco.numero, "\n")] = '\0';
                    break;

                case 9:
                    printf("Digite o novo complemento: ");
                    fgets(agenda[i].endereco.complemento, sizeof(agenda[i].endereco.complemento), stdin);
                    agenda[i].endereco.complemento[strcspn(agenda[i].endereco.complemento, "\n")] = '\0';
                    break;

                case 10:
                    printf("Digite o novo CEP: ");
                    fgets(agenda[i].endereco.cep, sizeof(agenda[i].endereco.cep), stdin);
                    agenda[i].endereco.cep[strcspn(agenda[i].endereco.cep, "\n")] = '\0';
                    break;

                case 11:
                    printf("Digite o novo DDD: ");
                    scanf("%d", &agenda[i].telefone.ddd);
                    getchar();
                    break;

                case 12:
                    printf("Digite o novo número de telefone: ");
                    fgets(agenda[i].telefone.numero, sizeof(agenda[i].telefone.numero), stdin);
                    agenda[i].telefone.numero[strcspn(agenda[i].telefone.numero, "\n")] = '\0';
                    break;

                case 13:
                    printf("Digite o novo dia de nascimento: ");
                    scanf("%d", &agenda[i].nascimento.dia);
                    getchar();
                    break;

                case 14:
                    printf("Digite o novo mês de nascimento: ");
                    scanf("%d", &agenda[i].nascimento.mes);
                    getchar();
                    break;

                case 15:
                    printf("Digite o novo ano de nascimento: ");
                    scanf("%d", &agenda[i].nascimento.ano);
                    getchar();
                    break;

                case 16:
                    printf("Digite as novas observações: ");
                    fgets(agenda[i].observacao, sizeof(agenda[i].observacao), stdin);
                    agenda[i].observacao[strcspn(agenda[i].observacao, "\n")] = '\0';
                    break;

                case 0:
                    printf("Saindo da edição.\n");
                    return;

                default:
                    printf("Opção inválida.\n");
                    return;
            }

            printf("Edição concluída com sucesso!\n");
            return;
        }
    }

    printf("Pessoa não encontrada na agenda.\n");
}

int main() {
    struct Agenda agenda[100];
    int tamanho = 0;
    int opcao, opcaoAgenda;
    int mesBusca, diaBusca;

    loadFromFile(agenda, &tamanho, "teste.txt");

    int idAtual = 0;

    if (tamanho == 0) {
        idAtual = 1;
    } else {
        for(int i = 0; i < tamanho; i++) {
            if (agenda[i].id >= idAtual) {
                idAtual = agenda[i].id + 1;
            }
        }
    }

    //printf("%d\n", idAtual);

    do {

        printf("1. Busca por primeiro nome\n");
        printf("2. Busca por mês de aniversário\n");
        printf("3. Busca por dia e mês de aniversário\n");
        printf("4. Insere pessoa\n");
        printf("5. Retira pessoa\n");
        printf("6. Imprime agenda (Primeiros 5 registros)\n");
        printf("7. Imprime agenda (Últimos 5 registros)\n");
        printf("8. Imprime agenda (Todos os registros)\n");
        printf("9. Editar pessoa\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                {
                    char nomeBusca[100];

                    printf("Digite o nome a ser buscado: ");
                    scanf("%s", nomeBusca);
                    getchar();

                    buscaPorNome(agenda, tamanho, nomeBusca);
                    break;
                }
            case 2:

                printf("Informe o mês do aniversário: ");
                scanf(" %d", &mesBusca);
                getchar();

                buscaPorMesAniversario(agenda, tamanho, mesBusca);
                break;

            case 3:

                printf("Informe o mês do aniversário: ");
                scanf(" %d", &mesBusca);
                getchar();

                printf("Informe o dia do aniversário: ");
                scanf(" %d", &diaBusca);
                getchar();
                buscaPorDiaMesAniversario(agenda, tamanho, diaBusca, mesBusca);
                break;

            case 4:
                {
                    struct Agenda novaPessoa;
                    int opcaoInsercao;

                    do {
                        printf("Deseja inserir no início (1) ou no final (2) da lista?\n");
                        scanf(" %d", &opcaoInsercao);

                        if(opcaoInsercao != 1 && opcaoInsercao != 2) {
                            printf("Opção inválida. Por favor, escolha 1 para inserir no início ou 2 para inserir no final.\n");
                        }

                    } while (opcaoInsercao != 1 && opcaoInsercao != 2);

                    getchar();
                    printf("Digite o nome: ");
                    fgets(novaPessoa.nome, sizeof(novaPessoa.nome), stdin);
                    novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';

                    printf("Digite o e-mail: ");
                    fgets(novaPessoa.email, sizeof(novaPessoa.email), stdin);
                    novaPessoa.email[strcspn(novaPessoa.email, "\n")] = '\0';

                    printf("Digite o país: ");
                    fgets(novaPessoa.endereco.pais, sizeof(novaPessoa.endereco.pais), stdin);
                    novaPessoa.endereco.pais[strcspn(novaPessoa.endereco.pais, "\n")] = '\0';

                    printf("Digite o estado: ");
                    fgets(novaPessoa.endereco.estado, sizeof(novaPessoa.endereco.estado), stdin);
                    novaPessoa.endereco.estado[strcspn(novaPessoa.endereco.estado, "\n")] = '\0';

                    printf("Digite a cidade: ");
                    fgets(novaPessoa.endereco.cidade, sizeof(novaPessoa.endereco.cidade), stdin);
                    novaPessoa.endereco.cidade[strcspn(novaPessoa.endereco.cidade, "\n")] = '\0';

                    printf("Digite o bairro: ");
                    fgets(novaPessoa.endereco.bairro, sizeof(novaPessoa.endereco.bairro), stdin);
                    novaPessoa.endereco.bairro[strcspn(novaPessoa.endereco.bairro, "\n")] = '\0';

                    printf("Digite a rua: ");
                    fgets(novaPessoa.endereco.rua, sizeof(novaPessoa.endereco.rua), stdin);
                    novaPessoa.endereco.rua[strcspn(novaPessoa.endereco.rua, "\n")] = '\0';

                    printf("Digite o número da residência (e apartamento): ");
                    fgets(novaPessoa.endereco.numero, sizeof(novaPessoa.endereco.numero), stdin);
                    novaPessoa.endereco.numero[strcspn(novaPessoa.endereco.numero, "\n")] = '\0';

                    printf("Digite o complemento: ");
                    fgets(novaPessoa.endereco.complemento, sizeof(novaPessoa.endereco.complemento), stdin);
                    novaPessoa.endereco.complemento[strcspn(novaPessoa.endereco.complemento, "\n")] = '\0';

                    printf("Digite o CEP: ");
                    fgets(novaPessoa.endereco.cep, sizeof(novaPessoa.endereco.cep), stdin);
                    novaPessoa.endereco.cep[strcspn(novaPessoa.endereco.cep, "\n")] = '\0';

                    printf("Digite o DDD: ");
                    scanf("%d", &novaPessoa.telefone.ddd);
                    getchar();

                    printf("Digite o número de telefone: ");
                    fgets(novaPessoa.telefone.numero, sizeof(novaPessoa.telefone.numero), stdin);
                    novaPessoa.telefone.numero[strcspn(novaPessoa.telefone.numero, "\n")] = '\0';

                    printf("Digite o dia de nascimento: ");
                    scanf("%d", &novaPessoa.nascimento.dia);
                    getchar();

                    printf("Digite o mês de nascimento: ");
                    scanf("%d", &novaPessoa.nascimento.mes);
                    getchar();

                    printf("Digite o ano de nascimento: ");
                    scanf("%d", &novaPessoa.nascimento.ano);
                    getchar();

                    printf("Digite observações: ");
                    fgets(novaPessoa.observacao, sizeof(novaPessoa.observacao), stdin);
                    novaPessoa.observacao[strcspn(novaPessoa.observacao, "\n")] = '\0';

                    inserePessoa(agenda, &tamanho, novaPessoa, opcaoInsercao, idAtual);

                    idAtual++;

                    break;
                }
            case 5:
                {
                    int idBusca;

                    printf("Digite o ID da pessoa a ser removida: ");
                    scanf("%d", &idBusca);
                    getchar();

                    retiraPessoa(agenda, &tamanho, idBusca);

                    break;
                }
            case 6:

                opcaoAgenda = 1;
                imprimeAgenda(agenda, tamanho, opcaoAgenda);
                break;

            case 7:

                opcaoAgenda = 2;
                imprimeAgenda(agenda, tamanho, opcaoAgenda);
                break;

            case 8:

                opcaoAgenda = 3;
                imprimeAgenda(agenda, tamanho, opcaoAgenda);
                break;

            case 9:

                int idEdicao;
                printf("Digite o ID da pessoa a ser editada: ");
                scanf("%d", &idEdicao);
                getchar();

                editarPessoa(agenda, tamanho, idEdicao);
                break;

            case 0:
            
                saveToFile(agenda, tamanho, "teste.txt");
                printf("Encerrando o programa. Obrigado!\n");
                break;

            default:

                printf("Opção inválida. Tente novamente.\n");
            
        }
    } while(opcao != 0);

    return 0;
}
