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
};

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

    if (mesBusca < 1 || mesBusca > 12) {
        printf("Mês inválido. O mês deve estar entre 1 e 12.\n");
        return;
    }

    if (diaBusca < 1 || diaBusca > diasPorMes[mesBusca]) {
        printf("Dia inválido para o mês %d. O dia deve estar entre 1 e %d.\n", mesBusca, diasPorMes[mesBusca]);
        return;
    }
    printf("---------------------------\n");
    printf("Pessoas que fazem aniversário em %d/%d:\n", diaBusca, mesBusca);
    printf("---------------------------\n");
    
    int encontrou = 0;

    for (int i = 0; i < tamanho; i++) {
        if (agenda[i].nascimento.dia == diaBusca && agenda[i].nascimento.mes == mesBusca) {
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
    }

    if (!encontrou) {
        printf("Nenhuma pessoa faz aniversário em %d/%d.\n", diaBusca, mesBusca);
        printf("---------------------------\n");
    }
}

void inserePessoa(struct Agenda agenda[], int *tamanho, struct Agenda novaPessoa) {
    int i, j;

    for (i = 0; novaPessoa.nome[i]; i++) {
        novaPessoa.nome[i] = toupper(novaPessoa.nome[i]);
    }

    for (i = 0; i < *tamanho && strcmp(agenda[i].nome, novaPessoa.nome) < 0; i++);

    for (j = *tamanho; j > i; j--) {
        agenda[j] = agenda[j - 1];
    }

    strcpy(agenda[i].nome, novaPessoa.nome);
    strcpy(agenda[i].email, novaPessoa.email);
    agenda[i].endereco = novaPessoa.endereco;
    agenda[i].telefone = novaPessoa.telefone;
    agenda[i].nascimento = novaPessoa.nascimento;
    strcpy(agenda[i].observacao, novaPessoa.observacao);

    (*tamanho)++;

    printf("Pessoa inserida com sucesso!\n");
}

void retiraPessoa(struct Agenda agenda[], int *tamanho, char nomeBusca[100]) {
    int i, j;

    for (i = 0; nomeBusca[i]; i++) {
        nomeBusca[i] = toupper(nomeBusca[i]);
    }

    for (i = 0; i < *tamanho && strstr(agenda[i].nome, nomeBusca) == NULL; i++);

    if (i == *tamanho) {
        printf("Pessoa não encontrada na agenda.\n");
        return;
    }

    for (j = i; j < *tamanho - 1; j++) {
        agenda[j] = agenda[j + 1];
    }

    (*tamanho)--;

    printf("Pessoa removida com sucesso!\n");
}

void imprimeAgenda(struct Agenda agenda[], int tamanho, int opcao) {
    if (opcao == 1) {
        printf("---------------------------\n");
        printf("Lista de Contatos:\n");
        printf("---------------------------\n");
        for (int i = 0; i < tamanho; i++) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: (%d) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("E-mail: %s\n", agenda[i].email);
            printf("---------------------------\n");
        }
    } else if (opcao == 2) {
        printf("---------------------------\n");
        printf("Lista de Contatos:\n");
        printf("---------------------------\n");
        for (int i = 0; i < tamanho; i++) {
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

int main() {
    struct Agenda agenda[100];
    int tamanho = 0;
    int opcao, opcaoAgenda;
    int mesBusca, diaBusca;

    do {

        printf("1. Busca por primeiro nome\n");
        printf("2. Busca por mês de aniversário\n");
        printf("3. Busca por dia e mês de aniversário\n");
        printf("4. Insere pessoa\n");
        printf("5. Retira pessoa\n");
        printf("6. Imprime agenda (nome, telefone e e-mail)\n");
        printf("7. Imprime agenda (todos os dados)\n");
        printf("8. Sair\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                {
                    char nomeBusca[100];

                    printf("Digite o nome a ser buscado: ");
                    scanf("%s", nomeBusca);

                    buscaPorNome(agenda, tamanho, nomeBusca);
                    break;
                }
            case 2:

                printf("Informe o mês do aniversário: ");
                scanf(" %d", &mesBusca);

                buscaPorMesAniversario(agenda, tamanho, mesBusca);
                break;

            case 3:

                printf("Informe o mês do aniversário: ");
                scanf(" %d", &mesBusca);

                printf("Informe o dia do aniversário: ");
                scanf(" %d", &diaBusca);
                buscaPorDiaMesAniversario(agenda, tamanho, diaBusca, mesBusca);
                break;

            case 4:
                {
                    struct Agenda novaPessoa;

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

                    inserePessoa(agenda, &tamanho, novaPessoa);

                    break;
                }
            case 5:
                {
                    char nomeRemover[100];

                    getchar();
                    printf("Digite o nome da pessoa a ser removida: ");
                    fgets(nomeRemover, sizeof(nomeRemover), stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                    retiraPessoa(agenda, &tamanho, nomeRemover);
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

                printf("Encerrando o programa. Obrigado!\n");
                break;

            default:

                printf("Opção inválida. Tente novamente.\n");
                
        }
    } while(opcao != 8);

    return 0;
}
