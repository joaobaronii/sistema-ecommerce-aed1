#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "produto.h"
#include "vendedor.h"

// struct para representar o cliente
typedef struct cliente
{
    char nome[20];
    int senha;
    int idCliente;
} Cliente;

// Protótipos das funções
Lista *inicializarProdutos();                                                                                                                                            // Inicializa a lista de produtos com alguns produtos predefinidos
ListaVendedor *inicializarVendedores();                                                                                                                                  // Inicializa a lista de vendedores com alguns vendedores predefinidos
void adicionarProduto(Lista *produtos, ListaVendedor *vendedores, int idVendedor);                                                                                       // Permite que um vendedor adicione um novo produto
void pesquisarProduto(Lista *produtos, Lista *carrinho);                                                                                                                 // Permite que o cliente pesquise produtos por nome ou categoria
void reduzirEstoque(Lista *produtos, Lista *carrinho);                                                                                                                   // Reduz a quantidade de produtos no estoque após a compra
void somaNVendas(Lista *carrinho, int *nVendas);                                                                                                                         // Soma o número total de vendas com base no carrinho
void somaReceitaTotal(Lista *carrinho, float *receitaTotal);                                                                                                             // Soma a receita total com base no carrinho
void mostrarProdutosAleatorios(Lista *produtos);                                                                                                                         // Mostra alguns produtos aleatórios como recomendação
void menuCliente(Lista *produtos, Pilha *historico, int *nVendas, float *receitaTotal);                                                                                  // Menu principal para clientes
void loginCliente(Lista *produtos, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal);                                          // Função para o cliente fazer login
void cadastrarVendedor(ListaVendedor *vendedores);                                                                                                                       // Permite cadastrar um novo vendedor
void menuVendedor(Lista *produtos, ListaVendedor *vendedor, int idVendedor, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal); // Menu para vendedores
void loginVendedor(Lista *produtos, ListaVendedor *vendedores, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal);              // Função para o vendedor fazer login
void relatorios(Lista *produtos, ListaVendedor *vendedores, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal);                 // Menu para ver relatórios
int menuInicial(Lista *produtos, ListaVendedor *vendedores, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal);                 // Menu inicial do programa
void avaliarProduto(Lista *produtos, Pilha *historico);                                                                                                                  // Permite o cliente avaliar um produto após a compra
void imprimirHistorico(Pilha *historico);                                                                                                                                // Imprime o histórico de compras do cliente                                                                                                                                     // Calcula a media da avaliação dos produtos

Lista *inicializarProdutos()
{
    Lista *produtos = criarProduto();

    Produto prod1;
    prod1.id = 1;
    strcpy(prod1.nome, "ps5");
    strcpy(prod1.descricao, "Videogame com 2 controles e alguns jogos");
    strcpy(prod1.categoria, "eletronicos");
    prod1.preco = 3800;
    prod1.quantidade = 20;
    strcpy(prod1.lojaVendedor, "Vende-se");
    prod1.nAvaliacoes = 0;
    prod1.nota = 0;

    Produto prod2;
    prod2.id = 2;
    strcpy(prod2.nome, "televisao");
    strcpy(prod2.descricao, "Televisor 4k");
    strcpy(prod2.categoria, "eletronicos");
    prod2.preco = 2000;
    prod2.quantidade = 50;
    strcpy(prod2.lojaVendedor, "Vende-se");
    prod2.nAvaliacoes = 0;
    prod2.nota = 0;

    Produto prod3;
    prod3.id = 3;
    strcpy(prod3.nome, "box harry potter");
    strcpy(prod3.descricao, "7 livros da saga Harry Potter");
    strcpy(prod3.categoria, "livros");
    prod3.preco = 350;
    prod3.quantidade = 30;
    strcpy(prod3.lojaVendedor, "TOPA");
    prod3.nAvaliacoes = 0;
    prod3.nota = 0;

    Produto prod4;
    prod4.id = 4;
    strcpy(prod4.nome, "fones de ouvido");
    strcpy(prod4.descricao, " Fones de ouvido sem fio");
    strcpy(prod4.categoria, "eletronicos");
    prod4.preco = 100;
    prod4.quantidade = 70;
    strcpy(prod4.lojaVendedor, "Vende-se");
    prod4.nAvaliacoes = 0;
    prod4.nota = 0;

    Produto prod5;
    prod5.id = 5;
    strcpy(prod5.nome, "guitarra");
    strcpy(prod5.descricao, "Guitarra eletrica");
    strcpy(prod5.categoria, "instrumentos musicais");
    prod5.preco = 900;
    prod5.quantidade = 40;
    strcpy(prod5.lojaVendedor, "VendeTudo");
    prod5.nAvaliacoes = 0;
    prod5.nota = 0;

    Produto prod6;
    prod6.id = 6;
    strcpy(prod6.nome, "bateria");
    strcpy(prod6.descricao, "Bateria acustica compacta");
    strcpy(prod6.categoria, "instrumentos musicais");
    prod6.preco = 1400;
    prod6.quantidade = 20;
    strcpy(prod6.lojaVendedor, "VendeTudo");
    prod6.nAvaliacoes = 0;
    prod6.nota = 0;

    Produto prod7;
    prod7.id = 7;
    strcpy(prod7.nome, "calca masculina");
    strcpy(prod7.descricao, "Calca jeans masculina");
    strcpy(prod7.categoria, "roupas");
    prod7.preco = 120;
    prod7.quantidade = 80;
    strcpy(prod7.lojaVendedor, "TOPA");
    prod7.nAvaliacoes = 0;
    prod7.nota = 0;

    Produto prod8;
    prod8.id = 8;
    strcpy(prod8.nome, "tenis feminino");
    strcpy(prod8.descricao, "Tenis feminino tamanho 32-38");
    strcpy(prod8.categoria, "roupas");
    prod8.preco = 300;
    prod8.quantidade = 100;
    strcpy(prod8.lojaVendedor, "TOPA");
    prod8.nAvaliacoes = 0;
    prod8.nota = 0;

    Produto prod9;
    prod9.id = 9;
    strcpy(prod9.nome, "box maze runner");
    strcpy(prod9.descricao, "5 livros da saga Maze Runner");
    strcpy(prod9.categoria, "livros");
    prod9.preco = 230;
    prod9.quantidade = 100;
    strcpy(prod9.lojaVendedor, "TOPA");
    prod9.nAvaliacoes = 0;
    prod9.nota = 0;

    // Insere os produtos definidos na lista produtos.
    inserirProduto(produtos, prod1);
    inserirProduto(produtos, prod2);
    inserirProduto(produtos, prod3);
    inserirProduto(produtos, prod4);
    inserirProduto(produtos, prod5);
    inserirProduto(produtos, prod6);
    inserirProduto(produtos, prod7);
    inserirProduto(produtos, prod8);
    inserirProduto(produtos, prod9);

    return produtos;
}

ListaVendedor *inicializarVendedores()
{
    ListaVendedor *vendedores = criarVendedor();

    Vendedor vend1;
    vend1.id = 1;
    strcpy(vend1.usuario, "yuri");
    strcpy(vend1.senha, "999999");
    strcpy(vend1.loja, "vende-se");

    Vendedor vend2;
    vend2.id = 2;
    strcpy(vend2.usuario, "angel");
    strcpy(vend2.senha, "123456");
    strcpy(vend2.loja, "vendetudo");

    Vendedor vend3;
    vend3.id = 3;
    strcpy(vend3.usuario, "cassio");
    strcpy(vend3.senha, "121212");
    strcpy(vend3.loja, "topa");

    // Insere os produtos definidos na lista vendedores.
    inserirVendedor(vendedores, vend1);
    inserirVendedor(vendedores, vend2);
    inserirVendedor(vendedores, vend3);

    return vendedores;
}

void adicionarProduto(Lista *produtos, ListaVendedor *vendedores, int idVendedor)
{
    Produto novoProduto;

    novoProduto.id = tamanhoProduto(produtos) + 1;

    setbuf(stdout, NULL);
    printf("\nDigite o nome do produto: ");
    fgets(novoProduto.nome, 20 * sizeof(char), stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;
    setbuf(stdout, NULL);

    printf("Digite a descricao do produto: ");
    fgets(novoProduto.descricao, 50 * sizeof(char), stdin);
    novoProduto.descricao[strcspn(novoProduto.descricao, "\n")] = 0;
    setbuf(stdout, NULL);

    printf("Digite a categoria do produto: ");
    fgets(novoProduto.categoria, 15 * sizeof(char), stdin);
    novoProduto.categoria[strcspn(novoProduto.categoria, "\n")] = 0;
    setbuf(stdout, NULL);

    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d", &novoProduto.quantidade);

    novoProduto.nota = 0;

    Vendedor *vendedor = buscarVendedor(vendedores, idVendedor);

    // Converter o nome do vendedor para minúsculas e atribui ao produto
    int i;
    for (i = 0; vendedor->usuario[i]; i++)
    {
        novoProduto.lojaVendedor[i] = (char)tolower(vendedor->usuario[i]);
    }
    novoProduto.lojaVendedor[i] = '\0'; // Adiciona o caractere nulo ao final da string

    // Converter o nome da loja do vendedor para minúsculas e atribui ao produto
    for (i = 0; vendedor->loja[i]; i++)
    {
        novoProduto.lojaVendedor[i] = (char)tolower(vendedor->usuario[i]);
    }
    novoProduto.lojaVendedor[i] = '\0'; // Adiciona o caractere nulo ao final da string

    inserirProduto(produtos, novoProduto);
}

void pesquisarProduto(Lista *produtos, Lista *carrinho)
{
    int op;
    char chave[50];

    printf("\nDigite 1 para buscar pelo nome do produto ou 2 para buscar pela categoria: ");
    scanf("%d", &op);

    printf("\nDigite a chave de pesquisa: ");
    scanf("%49s", chave); // Limitar a entrada para evitar estouro de buffer

    int encontrado = 0;
    No *no = produtos->inicio;

    while (no != NULL)
    {
        // Verifica se a chave de pesquisa corresponde ao nome ou à categoria do produto
        if ((op == 1 && strstr(no->valor.nome, chave) != NULL) || (op == 2 && strstr(no->valor.categoria, chave) != NULL))
        {
            // Se nenhum produto foi encontrado até agora, imprime "Produtos encontrados:"
            if (!encontrado)
            {
                printf("Produtos encontrados:\n");
            }
            printf("ID: %d\n", no->valor.id);
            printf("Nome: %s\n", no->valor.nome);
            printf("Descricao: %s\n", no->valor.descricao);
            printf("Categoria: %s\n", no->valor.categoria);
            printf("Preco: %.2f\n", no->valor.preco);
            printf("Quantidade: %d\n", no->valor.quantidade);
            printf("Loja do Vendedor: %s\n", no->valor.lojaVendedor);
            printf("Avaliacoes: %.2f\n", no->valor.nota);
            encontrado = 1; // Define encontrado como 1 para indicar que pelo menos um produto foi encontrado
        }
        no = no->prox;
    }
    // Se nenhum produto foi encontrado em toda a varredura, imprime "Nenhum produto encontrado."
    if (!encontrado)
    {
        printf("Nenhum produto encontrado.\n");
        return;
    }

    int idSelecionado;

    printf("Digite o ID do produto que deseja adicionar ao carrinho (ou 0 para cancelar): ");
    scanf("%d", &idSelecionado);

    if (idSelecionado != 0)
    {
        No *produtoSelecionado = produtos->inicio;

        while (produtoSelecionado != NULL)
        {
            if (produtoSelecionado->valor.id == idSelecionado)
            {
                int quantidade_desejada;

                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade_desejada);

                if (quantidade_desejada > 0 && quantidade_desejada <= produtoSelecionado->valor.quantidade)
                {
                    // Adiciona o produto ao carrinho
                    Produto produto_carrinho = produtoSelecionado->valor;
                    produto_carrinho.quantidade = quantidade_desejada;
                    inserirProduto(carrinho, produto_carrinho);
                    printf("Produto adicionado ao carrinho.\n");
                }
                else
                {
                    printf("Quantidade invalida ou insuficiente em estoque.\n");
                }
                break;
            }
            produtoSelecionado = produtoSelecionado->prox;
        }
        if (produtoSelecionado == NULL)
        {
            printf("Produto com ID selecionado nao encontrado.\n");
        }
    }
}

void salvarHistorico(Lista *carrinho, Pilha *historico)
{
    No *no = carrinho->inicio;
    while (no != NULL)
    {
        push(historico, no->valor); // Empilha o produto no histórico
        no = no->prox;
    }
}

void reduzirEstoque(Lista *produtos, Lista *carrinho)
{
    No *noCarrinho = carrinho->inicio;

    while (noCarrinho != NULL)
    {
        Produto *produto = buscarProdutoPtr(produtos, noCarrinho->valor.id);

        if (produto != NULL) // Verifica se o produto foi encontrado
        {
            produto->quantidade -= noCarrinho->valor.quantidade;
            if (produto->quantidade < 0)
            {
                produto->quantidade = 0; // Garante que o estoque não seja negativo
            }
        }
        else
        {
            printf("Produto com ID %d não encontrado.\n", noCarrinho->valor.id);
        }
        noCarrinho = noCarrinho->prox;
    }
}

void somaNVendas(Lista *carrinho, int *nVendas)
{
    int totalVendido = 0;
    No *no = carrinho->inicio;
    while (no != NULL)
    {
        totalVendido += no->valor.quantidade;
        no = no->prox;
    }
    *nVendas += totalVendido;
}

void somaReceitaTotal(Lista *carrinho, float *receitaTotal)
{
    float totalVendido = 0;
    No *no = carrinho->inicio;
    while (no != NULL)
    {
        totalVendido += no->valor.quantidade * no->valor.preco;
        no = no->prox;
    }
    *receitaTotal += totalVendido;
}

void pagamento(Lista *produtos, Lista *carrinho, Pilha *historico, int *nVendas, float *receitaTotal)
{
    int opcao;
    char confirmacao;

    printf("\nSelecione a forma de pagamento:\n");
    printf("1 - Pix\n");
    printf("2 - Cartao\n");
    printf("3 - Boleto\n");
    printf("4 - Voltar\n");

    while (1)
    {
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Pagamento via Pix selecionado.\n");
            printf("Confirmar pagamento via Pix? (S/N): ");
            scanf(" %c", &confirmacao);
            if (confirmacao == 'S' || confirmacao == 's')
            {
                printf("Pagamento via Pix confirmado.\n");
                printf("\n");
                printf("\n");
                printf("Pagamento realizado com sucesso!\n");
                reduzirEstoque(produtos, carrinho);
                salvarHistorico(carrinho, historico);
                somaReceitaTotal(carrinho, receitaTotal);
                somaNVendas(carrinho, nVendas);
                limparProduto(carrinho);
                return; // Retorna após o pagamento ser confirmado
            }
            else
            {
                printf("Pagamento via PIX cancelado.\n");
            }
            break;
        case 2:
            printf("Pagamento via cartao selecionado.\n");
            printf("Confirmar pagamento via cartao? (S/N): ");
            scanf(" %c", &confirmacao);
            if (confirmacao == 'S' || confirmacao == 's')
            {
                printf("Pagamento via cartao confirmado.\n");
                salvarHistorico(carrinho, historico);
                reduzirEstoque(produtos, carrinho);
                somaReceitaTotal(carrinho, receitaTotal);
                somaNVendas(carrinho, nVendas);
                limparProduto(carrinho);
                printf("\n");
                printf("\n");
                menuCliente(produtos, historico, nVendas, receitaTotal);
            }
            else
            {
                printf("Pagamento via cartao cancelado.\n");
            }
            break;
        case 3:
            printf("Pagamento via boleto selecionado.\n");
            printf("Confirmar pagamento via boleto? (S/N): ");
            scanf(" %c", &confirmacao);
            if (confirmacao == 'S' || confirmacao == 's')
            {
                printf("Pagamento via boleto confirmado.\n");
                salvarHistorico(carrinho, historico);
                reduzirEstoque(produtos, carrinho);
                somaReceitaTotal(carrinho, receitaTotal);
                somaNVendas(carrinho, nVendas);
                limparProduto(carrinho);
                printf("\n");
                printf("\n");
                menuCliente(produtos, historico, nVendas, receitaTotal);
            }
            else
            {
                printf("Pagamento via boleto cancelado.\n");
            }
            break;
        case 4:
            printf("Voltando ao menu anterior.\n");
            menuCliente(produtos, historico, nVendas, receitaTotal);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
}

void mostrarProdutosAleatorios(Lista *produtos)
{
    printf("Produtos recomendados:\n");
    srand(time(NULL)); // Gera números aleatórios

    // Cria uma cópia da lista de produtos para não modificar a original
    Lista listaCopia = *produtos;

    // Mostra 5 produtos aleatórios da lista de produtos
    for (int i = 0; i < 5; i++)
    {
        int tamanho = tamanhoProduto(&listaCopia);
        int indiceAleatorio = rand() % tamanho;

        No *atual = listaCopia.inicio;
        for (int j = 0; j < indiceAleatorio; j++)
        {
            atual = atual->prox;
        }

        Produto *produtoAleatorio = &atual->valor;
        printf("Nome: %s, Descricao: %s, Categoria: %s, Preco: %.2f\n",
               produtoAleatorio->nome, produtoAleatorio->descricao, produtoAleatorio->categoria, produtoAleatorio->preco);

        // Remove o produto selecionado da lista copiada, para que não apareça duplicados
        removerProduto(&listaCopia, produtoAleatorio->id);
    }
}

void menuCliente(Lista *produtos, Pilha *historico, int *nVendas, float *receitaTotal)
{
    int op = 0;
    Lista *carrinho = criarProduto();

    if (pilhaVazia(historico) == 0) // Verifica se o histórico do cliente está vazio.
    {
        printf("\n");
        mostrarProdutosAleatorios(produtos); // Se estiver, imprime 5 produtos aleatórios.
    }
    else
    {
        printf("\n");
        imprimirHistorico(historico); // Se não, mostra as últimas compras.
    }

    while (op != 5)
    {
        printf("\nDigite para:\n1 - Pesquisar pelo nome do produto ou categoria\n2 - Mostrar carrinho\n3 - Finalizar compra\n4 - Confimar recebimento\n5 - Sair\n");

        if (scanf("%d", &op) != 1)
        {
            printf("\nOpcao invalida.\n");
            while (getchar() != '\n')
                ; // Limpa o buffer de entrada
            continue;
        }

        switch (op)
        {
        case 1:
            printf("\nPesquisa:\n");
            pesquisarProduto(produtos, carrinho);
            break;
        case 2: // mostra o carrinho
            printf("\nCarrinho:\n");
            mostrarProduto(carrinho);
            break;
        case 3:
            if (tamanhoProduto(carrinho) == 0)
            {
                printf("Nao ha itens no carrinho. \n");
            }
            else
            {
                printf("Finalizando compra...");
                printf("Ha %d itens no carrinho.", tamanhoProduto(carrinho));
                pagamento(produtos, carrinho, historico, nVendas, receitaTotal);
            }
            break;
        case 4:
            printf("\nConfirmando recebimento...\n");
            avaliarProduto(produtos, historico);
            break;
        case 5:
            printf("\nVoltando ao menu inicial...\n");
            break;
        default:
            printf("\nOpcao invalida.\n");
            break;
        }
    }
}

void loginCliente(Lista *produtos, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal)
{
    Cliente *clientes = malloc(3 * sizeof(Cliente)); // Alocação dos clientes.

    if (clientes == NULL)
    {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }

    // Dados dos clientes (previamente cadastrados)
    strcpy(clientes[0].nome, "gabriel");
    clientes[0].senha = 3444;
    clientes[0].idCliente = 1;

    strcpy(clientes[1].nome, "joao");
    clientes[1].senha = 788899;
    clientes[1].idCliente = 2;

    strcpy(clientes[2].nome, "igor");
    clientes[2].senha = 1234;
    clientes[2].idCliente = 3;

    char usuario_nome[20];
    int senha;
    int ver = 0;

    while (ver != 1 && ver != 2 && ver != 3)
    {
        setbuf(stdin, NULL);
        printf("Digite seu nome de usuario: ");
        fgets(usuario_nome, sizeof(usuario_nome), stdin);
        usuario_nome[strcspn(usuario_nome, "\n")] = 0; // Remove \n

        printf("Digite sua senha: ");
        scanf("%d", &senha);

        while (getchar() != '\n')
            ; // Limpa o buffer de entrada

        for (int i = 1; i <= 3; i++)
        {
            if (strcmp(usuario_nome, clientes[i].nome) == 0 && senha == clientes[i].senha)
            {
                printf("Login bem-sucedido!\n");
                // Seleciona o histórico correto com base no cliente.
                if (clientes[i].idCliente == 1)
                    menuCliente(produtos, historico1, nVendas, receitaTotal);
                else if (clientes[i].idCliente == 2)
                    menuCliente(produtos, historico2, nVendas, receitaTotal);
                else if (clientes[i].idCliente == 3)
                    menuCliente(produtos, historico3, nVendas, receitaTotal);
                else
                {
                    printf("Erro: Cliente não encontrado.\n");
                    free(clientes);
                    return;
                }
                ver = clientes[i].idCliente;
                break;
            }
        }

        if (ver != 1 && ver != 2 && ver != 3)
        {
            printf("Usuario ou senha incorretos. Tente novamente.\n");
            break;
        }
    }
    free(clientes); // Libera a memória alocada
}

void cadastrarVendedor(ListaVendedor *vendedores)
{
    Vendedor novoVendedor;

    printf("\nDigite o nome do vendedor: ");
    fgets(novoVendedor.usuario, sizeof(novoVendedor.usuario), stdin);
    novoVendedor.usuario[strcspn(novoVendedor.usuario, "\n")] = 0; // Remove \n

    // Verifica se o nome de usuario já está em uso, varrendo a lista de vendedores
    NoVendedor *atual = vendedores->inicio;
    while (atual != NULL)
    {
        if (strcmp(novoVendedor.usuario, atual->valorVendedor.usuario) == 0)
        {
            printf("Nome de vendedor ja cadastrado. Por favor, escolha outro nome.\n");
            return; // Sai da função sem adicionar o vendedor
        }
        atual = atual->prox;
    }

    printf("Digite a senha do vendedor: ");
    fgets(novoVendedor.senha, sizeof(novoVendedor.senha), stdin);
    novoVendedor.senha[strcspn(novoVendedor.senha, "\n")] = 0; // Remove \n

    printf("Digite a loja do vendedor: ");
    fgets(novoVendedor.loja, sizeof(novoVendedor.loja), stdin);
    novoVendedor.loja[strcspn(novoVendedor.loja, "\n")] = 0; // Remove \n

    inserirVendedor(vendedores, novoVendedor);
}

void menuVendedor(Lista *produtos, ListaVendedor *vendedor, int idVendedor, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal)
{
    int op;

    while (op != 1)
    {
        printf("\nMenu do vendedor - Digite para:\n0 - Adicionar novo produto\n1 - Voltar\n");
        scanf("%d", &op);

        while (getchar() != '\n')
            ; // Limpa o buffer

        switch (op)
        {
        case 0:
            printf("Adicionando novo produto...\n");
            adicionarProduto(produtos, vendedor, idVendedor);
            break;
        case 1:
            printf("\nVoltando ao menu inicial...\n");
            break;
        default:
            printf("\nOpcao invalida\n");
        }
    }
    menuInicial(produtos, vendedor, historico1, historico2, historico3, nVendas, receitaTotal); // chama o menu inicial quando sai do while, voltando
}

void loginVendedor(Lista *produtos, ListaVendedor *vendedores, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal)
{
    char usuario[50];
    char senha[50];

    setbuf(stdout, NULL);

    printf("\nDigite o nome de usuario: ");
    fgets(usuario, 50, stdin);
    usuario[strcspn(usuario, "\n")] = '\0'; // Remover \n

    setbuf(stdout, NULL);

    printf("Digite a senha: ");
    fgets(senha, 50, stdin);
    senha[strcspn(senha, "\n")] = '\0'; // Remover \n

    NoVendedor *atual = vendedores->inicio;
    while (atual != NULL)
    {
        if (strcmp(usuario, atual->valorVendedor.usuario) == 0 && strcmp(senha, atual->valorVendedor.senha) == 0)
        {
            printf("Login bem sucedido!\n");
            menuVendedor(produtos, vendedores, atual->valorVendedor.id, historico1, historico2, historico3, nVendas, receitaTotal);
            return; // encerra a função depois de fazer o login bem-sucedido
        }
        atual = atual->prox;
    }

    printf("Nome de usuario ou senha incorretos.\n");
}

void relatorios(Lista *produtos, ListaVendedor *vendedores, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal)
{
    int op = 0;

    while (op != 4)
    {
        printf("\nDigite para ver o relatorio de:\n1 - Numero total de vendas\n2 - Receita total\n3 - Voltar\n");
        scanf("%d", &op);

        while (getchar() != '\n')
            ;

        switch (op)
        {
        case 1:
            printf("\n Total de produtos vendidos: %d\n", *nVendas);
            break;
        case 2:
            printf("\nA receita total gerada foi de R$%.2f\n", *receitaTotal);
            break;
        case 3:
            printf("\nVoltando ao menu inicial...\n");
            break;
        default:
            printf("\nOpcao invalida\n");
        }
    }
    menuInicial(produtos, vendedores, historico1, historico2, historico3, nVendas, receitaTotal); // retorna ao menu inicial ao sair do while
}

int menuInicial(Lista *produtos, ListaVendedor *vendedores, Pilha *historico1, Pilha *historico2, Pilha *historico3, int *nVendas, float *receitaTotal)
{
    {
        int a = 0;
        printf("---------------------------------\n");
        while (a != 6)
        {
            printf("\nMenu inicial - Digite para:\n1 - Ver relatorios\n2 - Cadastrar como vendedor\n3 - Entrar como vendedor\n4 - Entrar como cliente\n5 - Sair do programa\n");
            printf("\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &a);

            while (getchar() != '\n')
                ;

            switch (a)
            {
            case 1:
                printf("\nAcessando relatorios...\n");
                relatorios(produtos, vendedores, historico1, historico2, historico3, nVendas, receitaTotal);
                break;
            case 2:
                printf("\nCadastrando novo vendedor...\n");
                cadastrarVendedor(vendedores);
                break;
            case 3:
                printf("\nEntrando como vendedor...\n");
                loginVendedor(produtos, vendedores, historico1, historico2, historico3, nVendas, receitaTotal);
                break;
            case 4:
                printf("\nEntrando como Cliente...\n");
                loginCliente(produtos, historico1, historico2, historico3, nVendas, receitaTotal);
                break;
            case 5:
                printf("\nSaindo do programa...\n");
                return 0;

            default:
                printf("\nOpcao invalida:\n");
            }
        }

        printf("Fim do programa");
    }
    return 0;
}

void avaliarProduto(Lista *produtos, Pilha *historico)
{
    if (pilhaVazia(historico) == 0)
    {
        printf("Nenhuma compra realizada.\n");
        return;
    }

    imprimirHistorico(historico); // mostra o historico para que o cliente saiva o id do produto

    int id, novaNota;
    printf("Digite o ID do produto que deseja avaliar: ");
    scanf("%d", &id);

    // Busca o produto pelo ID
    No *no = produtos->inicio;
    while (no != NULL)
    {
        if (no->valor.id == id)
        {
            printf("Digite a nova nota para o produto (de 1 a 5): ");
            scanf("%d", &novaNota);

            if (novaNota < 1 || novaNota > 5)
            {
                printf("Valor invalido, a nota deve estar entre 1 e 5.\n");
                return;
            }

            // Calcula a nova nota e atualiza o número de avaliações
            no->valor.nota = (no->valor.nota * no->valor.nAvaliacoes + novaNota) / (no->valor.nAvaliacoes + 1);
            no->valor.nAvaliacoes++;

            printf("'%s' avaliado com %d estrelas.\n", no->valor.nome, novaNota);
            return;
        }
        no = no->prox;
    }
    printf("Produto com ID %d nao encontrado.\n", id);
}

// Imprime o conteúdo de uma pilha (histórico de compras)
void imprimirHistorico(Pilha *historico)
{
    printf("\nHistorico de Compras:\n");

    // Verifica se a pilha está vazia
    if (pilhaVazia(historico) == 0)
    {
        printf("O historico de compras esta vazio.\n");
        return;
    }

    // Itera sobre a pilha sem removê-la
    NoPilha *no = historico->topo;
    int contador = 0;
    while (no != NULL)
    {
        Produto produto = no->valor;
        printf("ID: %d\n", produto.id);
        printf("Nome: %s\n", produto.nome);
        printf("Descricao: %s\n", produto.descricao);
        printf("Categoria: %s\n", produto.categoria);
        printf("Preco: %.2f\n", produto.preco);
        printf("Quantidade: %d\n", produto.quantidade);
        printf("Loja do Vendedor: %s\n", produto.lojaVendedor);
        printf("Avaliacoes: %.2f\n", no->valor.nota);
        printf("\n");
        no = no->prox;
        contador++;
        if (contador >= 5)
        {
            break; // Se exibimos 5 produtos, saímos do loop
        }
    }
}

int main()
{
    Lista *produtos = inicializarProdutos();             // atribui os produtos predefinidos a lista produtos
    ListaVendedor *vendedores = inicializarVendedores(); // atribui os produtos predefinidos a lista vendedores
    // cria as pilhas que serão o historico de cada cliente
    Pilha *historico1 = criarPilha();
    Pilha *historico2 = criarPilha();
    Pilha *historico3 = criarPilha();
    // cria uma variavel para armazenar o total de vendas e outra para receita total.
    int nVendas = 0;
    float receitaTotal = 0;

    menuInicial(produtos, vendedores, historico1, historico2, historico3, &nVendas, &receitaTotal);

    return 0;
}
