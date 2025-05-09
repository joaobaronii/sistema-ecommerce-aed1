typedef struct vendedor Vendedor;

typedef struct noVendedor NoVendedor;

typedef struct listaVendedor ListaVendedor;

struct vendedor
{
    int id;
    char usuario[20];
    char loja[20];
    char senha[6];
};

struct noVendedor
{
    Vendedor valorVendedor; 
    NoVendedor *prox;
};

struct listaVendedor
{
    NoVendedor *inicio;
};

ListaVendedor *criarVendedor();

void limparVendedor(ListaVendedor *lista);

int inserirVendedor(ListaVendedor *l, Vendedor it);

int removerInicioVendedor(ListaVendedor *l);

int removerFim(ListaVendedor *l);

Vendedor *buscarVendedor(ListaVendedor *l, int chave);

int listaVaziaVendedor(ListaVendedor *l);

int tamanhoVendedor(ListaVendedor *l);

void mostrarVendedor(ListaVendedor *l);

int removerVendedor(ListaVendedor *l, int chave);