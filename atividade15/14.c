#include <stdio.h>
#include <string.h>

#define NUM_PRODUTOS 5

struct Produto {
    int codigo;
    char nome[15];
    float preco;
    int quantidade;
};


void imprimirProduto(struct Produto p) {
    printf("Código: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Preço: %.2f\n", p.preco);
    printf("Quantidade: %d\n", p.quantidade);
    printf("\n");
}


int buscarProduto(struct Produto produtos[], int numProdutos, int codigo) {
    for (int i = 0; i < numProdutos; ++i) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Produto produtos[NUM_PRODUTOS];

    for (int i = 0; i < NUM_PRODUTOS; ++i) {
        printf("Digite os dados do produto %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &produtos[i].codigo);

        printf("Nome (máximo 15 letras): ");
        scanf("%s", produtos[i].nome);

        printf("Preço: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);

        printf("\n");
    }

    int codigoPedido, quantidadePedido;
    float precoTotal = 0.0;

    do {
        printf("Digite o código do produto para o pedido (ou 0 para sair): ");
        scanf("%d", &codigoPedido);

        if (codigoPedido == 0) {
            break;
        }

        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidadePedido);

        int indiceProduto = buscarProduto(produtos, NUM_PRODUTOS, codigoPedido);

        if (indiceProduto != -1) {
            if (produtos[indiceProduto].quantidade >= quantidadePedido) {

                produtos[indiceProduto].quantidade -= quantidadePedido;

                float precoPedido = produtos[indiceProduto].preco * quantidadePedido;
                precoTotal += precoPedido;

                printf("\n");
                printf("Pedido atendido. Estoque atualizado:\n");
                printf("\n");
                imprimirProduto(produtos[indiceProduto]);
                printf("\n");
                printf("Preço do Pedido: %.2f\n", precoPedido);
                printf("Preço Total até agora: %.2f\n", precoTotal);
            } else {
                printf("\n");
                printf("Erro: Estoque insuficiente para atender ao pedido.\n");
                printf("\n");
            }
        } else {
            printf("\n");
            printf("Erro: Produto não encontrado.\n");
            printf("\n");
        }

    } while (1);
    
    printf("Preço Total do Pedido: %.2f\n", precoTotal);
    printf("\n");

    return 0;
}
