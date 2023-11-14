struct nascimento {
    int dia;
    int mes;
    int ano;
};

struct infoPessoal {
    char nome[100];
    int idade;
    char sexo[20];
    char cpf[50];
};

struct infoProfissional {
    int setor;
    char cargo[30];
    int salario;
};

struct registro {
    struct infoPessoal infoPessoal;
    struct nascimento nascimento;
    struct infoProfissional infoProfissional;
};

#include <stdio.h>
#include <string.h>

#define TAMANHO 1

int main() {
    int diasDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    struct registro registro[TAMANHO];

    for(int i = 0; i < TAMANHO; i++) {

        printf("Funcionário %d:\n", i);

        printf("Nome: ");
        fgets(registro[i].infoPessoal.nome, sizeof(registro[i].infoPessoal.nome), stdin);
        registro[i].infoPessoal.nome[strcspn(registro[i].infoPessoal.nome, "\n")] = '\0';

        printf("Idade: ");
        scanf(" %d", &registro[i].infoPessoal.idade);

        while (registro[i].infoPessoal.idade < 0) {
        printf("Idade inválida, informe uma idade > 0: ");
        scanf(" %d", &registro[i].infoPessoal.idade);
        }

        getchar();
        printf("Sexo (M/F): ");
        fgets(registro[i].infoPessoal.sexo, sizeof(registro[i].infoPessoal.sexo), stdin);
        registro[i].infoPessoal.sexo[strcspn(registro[i].infoPessoal.sexo, "\n")] = '\0';

        printf("Ano de nascimento: ");
        scanf(" %d", &registro[i].nascimento.ano);
        getchar();

        while (registro[i].nascimento.ano < 0) {
        printf("Ano inválido, informe um ano > 0: ");
        scanf(" %d", &registro[i].nascimento.ano);
        }

        printf("Mês de nascimento: ");
        scanf(" %d", &registro[i].nascimento.mes);

        while (registro[i].nascimento.mes < 1 || registro[i].nascimento.mes > 12) {
        printf("Mês inválido, valores aceitos (1-12): ");
        scanf(" %d", &registro[i].nascimento.mes);
        }

        printf("Dia de nascimento: ");
        scanf(" %d", &registro[i].nascimento.dia);

        while (registro[i].nascimento.dia < 1 ||
           registro[i].nascimento.dia > diasDoMes[registro[i].nascimento.mes]) {
        printf("Dia inválido para o mês especificado. Por favor, insira novamente: ");
        scanf(" %d", &registro[i].nascimento.dia); 
        }

        getchar();
        printf("CPF: ");
        fgets(registro[i].infoPessoal.cpf, sizeof(registro[i].infoPessoal.cpf), stdin);
        registro[i].infoPessoal.cpf[strcspn(registro[i].infoPessoal.cpf, "\n")] = '\0';

        printf("Setor (0-99): ");
        scanf(" %d", &registro[i].infoProfissional.setor);

        while (registro[i].infoProfissional.setor < 0 || registro[i].infoProfissional.setor > 99) {
        printf("Setor inválido, valores aceitos (0-99): ");
        scanf(" %d", &registro[i].infoProfissional.setor);
        }

        getchar();
        printf("Cargo: ");
        fgets(registro[i].infoProfissional.cargo, sizeof(registro[i].infoProfissional.cargo), stdin);
        registro[i].infoProfissional.cargo[strcspn(registro[i].infoProfissional.cargo, "\n")] = '\0';

        printf("Salário: ");
        scanf(" %d", &registro[i].infoProfissional.salario);
        getchar();

    }

    printf("---------------------------\n");
    printf("Lista de funcionários\n");
    printf("---------------------------\n");

    for(int i = 0; i < TAMANHO; i++) {
        printf("Funcionário %d:\n", i);

        printf("Nome: %s\n", registro[i].infoPessoal.nome);

        printf("Idade: %d\n", registro[i].infoPessoal.idade);

        printf("Sexo: %s\n", registro[i].infoPessoal.sexo);

        printf("Data de nascimento: %d/%d/%d\n", registro[i].nascimento.dia, registro[i].nascimento.mes, registro[i].nascimento.ano);

        printf("CPF: %s\n", registro[i].infoPessoal.cpf);

        printf("Setor(0-99): %d\n", registro[i].infoProfissional.setor);

        printf("Cargo: %s\n", registro[i].infoProfissional.cargo);

        printf("Salário: %d\n", registro[i].infoProfissional.salario);

        printf("---------------------------\n");

    }

    return 0;
}

