#include "../include/ListaSequencial.h"
#include <stdlib.h>

Lista* cria_lista(){
    Lista* li;
    li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
    {
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li){
    free(li);
}


int tamanho_lista(Lista* li){
    if (li == NULL)
    {
        return -1;
    }else{
        return li->qtd;
    }
}

// verifica se lista está cheia
int lista_cheia(Lista* li){
    if (li == NULL)
    {
        return -1;
    }else{
        return (li->qtd == MAX);
    }
}

// verifica se lista esta vazia
int lista_vazia(Lista* li){
    if (li == NULL)
    {
        return -1;
    }else{
        return (li->qtd == 0);
    }
}

int insere_lista_final(Lista* li, Aluno a1){
    if (li == NULL || lista_cheia(li))
    {
        return 0;
    }else{
        li->dados[li->qtd] = a1;
        li->qtd++;
        return 1;
    }
}

int insere_lista_inicio(Lista* li, Aluno a1){
    if (li == NULL || lista_cheia(li))
    {
        return 0;
    }
    for (int i = li->qtd-1; i >= 0; i--)
    {
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = a1;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, Aluno a1){
    if (li == NULL || lista_cheia(li))
    {
        return 0;
    }
    int k, i = 0;
    while (i <li->qtd && li->dados[i].matricula < a1.matricula)
    {
        i++;
    }

    for (k = li->qtd-1; k >= i; k--)
    {
        li->dados[k+1] = li->dados[k];
    }
    li->dados[i] = a1;
    li->qtd++;
    return 1;
}

int remove_lista_final(Lista* li){
    if (li == NULL || li->qtd == 0)
    {
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if (li == NULL)
    {
        return 0;
    }
    if (li->qtd == 0)
    {
        return 0;
    }
    int k = 0;
    for (k = 0; k < li->qtd-1; k++)
    {
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
}

int remove_lista(Lista* li, int mat){
    if (li == NULL)
    {
        return 0;
    }
    if (li->qtd == 0)
    {
        return 0;
    }
    int k, i = 0;
    while (i < li->qtd && li->dados[i].matricula != mat)
    {
        i++;
    }
    if (i == li->qtd)
    {
        return 0;
    }
    for (k = i; k < li->qtd-1; k++)
    {
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, Aluno* al){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, Aluno* al){
    if (li == NULL)
    {
        return 0;
    }
    int k, i = 0;
    while (i < li->qtd && li->dados[i].matricula != mat)
    {
        i++;
    }
    if (i == li->qtd)
    {
        return 0;
    }
    *al = li->dados[i];
    return 1;
}