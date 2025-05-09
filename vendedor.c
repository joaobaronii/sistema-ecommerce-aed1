#include "vendedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaVendedor *criarVendedor()
{
    ListaVendedor *l = (ListaVendedor *)malloc(sizeof(ListaVendedor));
    if (l != NULL)
        l->inicio = NULL;
    return l;
}

void limparVendedor(ListaVendedor *l)
{
    while (l->inicio != NULL)
        removerInicioVendedor(l);
    free(l);
}

int inserirVendedor(ListaVendedor *l, Vendedor it)
{
    if (l == NULL)
        return 0;
    NoVendedor *no = (NoVendedor *)malloc(sizeof(NoVendedor));
    if (no == NULL)
        return 0;
    no->valorVendedor = it;
    no->prox = NULL;
    if (l->inicio == NULL)
    {
        l->inicio = no;
    }
    else
    {
        NoVendedor *temp = l->inicio;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = no;
    }
    return 1;
}

int removerInicioVendedor(ListaVendedor *l)
{
    if (l == NULL)
        return 2;
    if (listaVaziaVendedor(l) == 0)
        return 1;
    NoVendedor *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

void mostrarVendedor(ListaVendedor *l)
{
    if (l->inicio != NULL)
    {
        printf("[");
        NoVendedor *no = l->inicio;
        while (no != NULL)
        {
            printf("{Nome: %s, Senha: %s, Loja: %s}", no->valorVendedor.usuario, no->valorVendedor.senha, no->valorVendedor.loja);
            if (no->prox != NULL)
                printf(", ");
            no = no->prox;
        }
        printf("]\n");
    }
    else
        printf("O carrinho esta vazio.\n");
}

int tamanhoVendedor(ListaVendedor *l)
{
    int tamanho = 0;
    NoVendedor *no = l->inicio;
    while (no != NULL)
    {
        tamanho++;
        no = no->prox;
    }
    return tamanho;
}

int listaVaziaVendedor(ListaVendedor *l)
{
    return l->inicio == NULL;
}

Vendedor *buscarVendedor(ListaVendedor *l, int chave)
{
    NoVendedor *no = l->inicio;
    while (no != NULL)
    {
        if (no->valorVendedor.id == chave)
            return &(no->valorVendedor); 
        no = no->prox;
    }
    return NULL; 
}

int removerVendedor(ListaVendedor *l, int chave)
{
    if (l == NULL)
        return 0;
    NoVendedor *noAuxiliar = NULL;
    NoVendedor *noLista = l->inicio;
    while (noLista != NULL)
    {
        if (noLista->valorVendedor.id == chave)
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