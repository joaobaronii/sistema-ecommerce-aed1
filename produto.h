typedef struct produto Produto;

typedef struct lista Lista;

typedef struct no No;

struct produto
{
    int id;
    char nome[20];
    char descricao[50];
    char categoria[25];
    float preco;
    int quantidade;
    float nota;
    int nAvaliacoes;
    char lojaVendedor[20];
};

struct no
{
    Produto valor;
    struct no *prox;
};

struct lista
{
    No *inicio;
};

typedef struct pilha Pilha;

typedef struct noPilha NoPilha;

struct noPilha
{
    Produto valor;
    struct noPilha *prox;
};

struct pilha
{
    NoPilha *topo;
};

Lista *criarProduto();

void limparProduto(Lista *lista);

int inserirProduto(Lista *l, Produto it);

Produto buscarProduto(Lista *l, int chave);

int removerInicioProduto(Lista *l);

int produtoVazio(Lista *l);

int tamanhoProduto(Lista *l);

void mostrarProduto(Lista *l);

int removerProduto(Lista *l, int chave);

Pilha *criarPilha();

void limparPilha(Pilha *p);

int push(Pilha *p, Produto it);

int pop(Pilha *p);

int consultarPilha(Pilha *p, Produto *it);

void mostrarPilha(Pilha *p);

int tamanhoPilha(Pilha *p);

int pilhaVazia(Pilha *p);

int pilhaCheia(Pilha *p);

void copiarPilha(Pilha *origem, Pilha *destino);

Produto *buscarProdutoPtr(Lista *l, int chave);