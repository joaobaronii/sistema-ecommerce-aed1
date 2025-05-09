#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista *criarProduto()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL)
        l->inicio = NULL;
    return l;
}

void limparProduto(Lista *l)
{
    No *atual = l->inicio;
    No *prox;

    while (atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    l->inicio = NULL;
}

int removerInicioProduto(Lista *l)
{
    if (l == NULL)
        return 2;
    if (produtoVazio(l) == 0)
        return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

int inserirProduto(Lista *l, Produto it)
{
    if (l == NULL)
        return 0;
    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return 0;
    no->valor = it;
    no->prox = NULL;
    if (l->inicio == NULL)
    {
        l->inicio = no;
    }
    else
    {
        No *temp = l->inicio;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = no;
    }
    return 1;
}

void mostrarProduto(Lista *l)
{
    if (l->inicio != NULL)
    {
        printf("[");
        No *no = l->inicio;
        while (no != NULL)
        {
            printf("{Nome: %s, Valor: %.2f, Quantidade: %d}", no->valor.nome, no->valor.preco, no->valor.quantidade);
            if (no->prox != NULL)
                printf(", ");
            no = no->prox;
        }
        printf("]\n");
    }
    else
        printf("O carrinho esta vazio.\n");
}

int tamanhoProduto(Lista *l)
{
    int tamanho = 0;
    No *no = l->inicio;
    while (no != NULL)
    {
        tamanho++;
        no = no->prox;
    }
    return tamanho;
}

int produtoVazio(Lista *l)
{
    return l->inicio == NULL;
}

Produto buscarProduto(Lista *l, int chave)
{
    No *no = l->inicio;
    while (no != NULL)
    {
        if (no->valor.id == chave)
            return no->valor;
        no = no->prox;
    }
    Produto produtoNulo;
    produtoNulo.id = '\0';
    return produtoNulo;
}

int removerProduto(Lista *l, int chave)
{
    if (l == NULL)
        return 0;
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    while (noLista != NULL)
    {
        if (noLista->valor.id == chave)
        {
            if (noAuxiliar == NULL)
                l->inicio = noLista->prox;
            else
                noAuxiliar->prox = noLista->prox;
            free(noLista);
            return 1;
        }
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    return 0;
}

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void limparPilha(Pilha *p)
{
    if (p == NULL)
        return;
    while (pilhaVazia(p) != 0)
        pop(p);
    free(p);
    p = NULL;
}

int push(Pilha *p, Produto it)
{
    if (p == NULL)
        return 2;
    NoPilha *no = (NoPilha *)malloc(sizeof(NoPilha));
    no->valor = it;
    no->prox = p->topo;
    p->topo = no;
    return 0;
}

int pop(Pilha *p)
{
    if (p == NULL)
        return 2;
    if (pilhaVazia(p) == 0)
        return 1;
    NoPilha *temp = p->topo;
    p->topo = temp->prox;
    free(temp);
    return 0;
}

int consultarPilha(Pilha *p, Produto *it)
{
    if (p == NULL)
        return 2;
    if (pilhaVazia(p) == 0)
        return 1;
    NoPilha *temp = p->topo;
    *it = temp->valor;
    return 0;
}

int tamanhoPilha(Pilha *p)
{
    if (p == NULL)
        return -1;
    int ct = 0;
    NoPilha *no = p->topo;
    while (no != NULL)
    {
        ct++;
        no = no->prox;
    }
    return ct;
}

int pilhaVazia(Pilha *p)
{
    if (p == NULL)
        return 2;
    if (p->topo == NULL)
        return 0;
    else
        return 1;
}

int pilhaCheia(Pilha *p)
{
    return 1;
}

void mostrarPilha(Pilha *p)
{
    if (p != NULL)
    {
        printf("[");
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            printf("{Nome: %s, Valor: %.2f, Quantidade: %d}", no->valor.nome, no->valor.preco, no->valor.quantidade);
            if (no->prox != NULL)
                printf(", ");
            no = no->prox;
        }
        printf("]\n");
    }
}

void copiarPilha(Pilha *origem, Pilha *destino)
{
    NoPilha *no = origem->topo;
    while (no != NULL)
    {
        push(destino, no->valor);
        no = no->prox;
    }
}

Produto *buscarProdutoPtr(Lista *l, int chave)
{
    No *no = l->inicio;
    while (no != NULL)
    {
        if (no->valor.id == chave)
            return &(no->valor); // Retorna um ponteiro para o produto encontrado
        no = no->prox;
    }
    return NULL; // Retorna NULL se o produto não for encontrado
}