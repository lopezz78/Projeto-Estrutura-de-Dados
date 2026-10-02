#ifndef LISTA_H
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct no
{
    int codigo;
    char codigo_equipamento[6];
    char nome[20];
    int prioridade;
    int periodo;
    struct no *prox;
}No;

typedef struct lista
{
    No *inicio;
}Lista;

Lista* InicializaLista()
{
    return NULL;
}

Lista* CriaLista()
{
    Lista*aux;
    aux = (Lista*)malloc(sizeof(Lista));
    aux->inicio=NULL;
    return aux;
}

int VerificaLista(Lista*L)
{
    if(L->inicio==NULL)
    {
        return 1;
    }
    return 0;
}

No* BuscaSolicitacao(Lista*L, int cod)
{
    No*aux = L->inicio;
    while(aux!=NULL)
    {
        if(aux->codigo == cod)
        {
            return aux;
        }
    }
    return NULL;
}

No* auxInsereSolicitacao(No*antigo, int cod, char codequip[], char name[], int prior, int per)
{
    No *novo = (No*)malloc(sizeof(No));
    No *aux = NULL, *aux1 = antigo;

    novo->codigo = cod;
    strcpy(novo->codigo_equipamento, codequip);
    strcpy(novo->nome, name);
    novo->prioridade = prior;
    novo->periodo = per;
    novo->prox = NULL;

    while((aux1!=NULL)&&(aux1->codigo < cod))
    {
        aux = aux1;
        aux1 = aux1->prox;
    }
    if(aux == NULL)
    {
        novo->prox = antigo;
        return novo;
    }
    novo->prox = aux1;
    aux->prox=novo;
    return antigo;
}

void InsereSolicitacao(Lista*L, int cod, char codequip[], char name[], int prior, int per)
{
    L->inicio = auxInsereSolicitacao(L->inicio, cod, codequip, name, prior, per);
}

#endif