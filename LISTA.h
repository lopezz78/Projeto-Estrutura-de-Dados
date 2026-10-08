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

No * auxRemoveSolicitacao(No*apag, int cod)
{
    No*aux = NULL;
    No*aux1 = apag;

     while((aux1!=NULL)&&(aux1->codigo < cod))
    {
        aux = aux1;
        aux1 = aux1->prox;
    }
    if(aux == NULL)
    {
        aux1 = apag;
        apag = apag->prox;
        free(aux1);
        return apag;
    }
    aux->prox = aux1->prox;
    free(aux1);
    return apag;

}

void RemoveSolicitacao(Lista*L, int cod)
{
    L->inicio = auxRemoveSolicitacao(L->inicio, cod);
}
void imprimeFila(Fila* f)
{
    No *aux;
    printf("\n\t\t");
    
    for (aux = f->ini; aux!=NULL; aux = aux->prox){
        printf("%d",aux->prioridade);
    }
    printf("\n");
}
/*int codigo;
    char codigo_equipamento[6];
    char nome[20];
    int prioridade;
    int periodo;
    
    Colocar as informações pra imprimir.
    */
void imprimeSolicitacao(Lista *L, int codigo)
{

    No *aux = L->inicio;

    aux = BuscaSolicitacao(aux, codigo);
        if(aux == NULL)
        {
            printf("Solicitacao nao encontrada.\n");
        }
        else
        {
            printf("Codigo: %i/n", aux->codigo);
            printf("Equipamento: %c/n", aux->codigo_equipamento);
            printf("Nome: %s/n", aux->nome);
            printf("Prioridade: %i/n", aux->prioridade);
            printf("Periodo: %i/n", aux->periodo);

        }

}

void alteraprioridade(Lista *L, int codigo)
{
    int prioridade;
    int perido;

    //Verificacao de prioridade e periodo

    aux = BuscaSolicitacao(aux, codigo);
        if(aux == NULL)
        {
            printf("Solicitacao nao encontrada.\n");
        }
        else
        {
            aux->prioridade=prioridade;
            aux->periodo=periodo;

        }
}


#endif
