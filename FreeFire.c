#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

int main() {
    menu();
    return 0;
}
// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int quantidade;
    float peso;
    char tipo[30]; // Ex: arma, munição, kit médico, ferramenta
} Item;

#define MAX_ITENS 100

Item mochila[MAX_ITENS];
int total_itens = 0;

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

void menu() {
    int opcao;

    do {
        printf("\n Menu da Mochila \n");
        printf("1. Adicionar item\n");
        printf("2. Listar itens\n");
        printf("3. Buscar item\n");
        printf("4. Remover item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarItem(); break;
            case 2: listarItens(); break;
            case 3: buscarItem(); break;
            case 4: removerItem(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}



// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
void adicionarItem() {
    if (total_itens >= MAX_ITENS) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    printf("Peso (kg): ");
    scanf("%f", &novo.peso);

    printf("Tipo (arma, municao, kit medico, ferramenta): ");
    scanf(" %[^\n]", novo.tipo);

    mochila[total_itens++] = novo;
    printf("Item adicionado com sucesso!\n");
}

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void removerItem() {
    char nomeRemover[MAX_NOME];
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeRemover);

    for (int i = 0; i < total_itens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            for (int j = i; j < total_itens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            total_itens--;
            printf("Item removido com sucesso.\n");
            return;
        }
    }

    printf("Item não encontrado.\n");
}

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.
void listarItens() {
    if (total_itens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("Itens na mochila:\n");
    for (int i = 0; i < total_itens; i++) {
        printf("%d. Nome: %s | Quantidade: %d | Peso: %.2f kg | Tipo: %s\n",
               i + 1,
               mochila[i].nome,
               mochila[i].quantidade,
               mochila[i].peso,
               mochila[i].tipo);
    }
}

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).


// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
void buscarItem() {
    char nomeBusca[MAX_NOME];
    printf("Digite o nome do item para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < total_itens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado:\n");
            printf("Nome: %s | Quantidade: %d | Peso: %.2f kg | Tipo: %s\n",
                   mochila[i].nome,
                   mochila[i].quantidade,
                   mochila[i].peso,
                   mochila[i].tipo);
            return;
        }
    }

    printf("Item não encontrado.\n");
}
