#include <stdio.h>
#include <stdlib.h>
#include "../include/ListaEncadeada.h"

// Nó
typedef struct _node
{
    int val;
    struct _node *next;
} Node;

// Lista
typedef struct _linked_list{
    Node *begin;
    int tam;
} LinkedList;

// cria a lista
LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList)); // por padrão calloc inicializa tudo em 0
    L->begin = NULL;
    L->tam = 0;
    return L;
}

// cria um nó
Node *Node_create(int val){
    Node *novo = (Node*) calloc(1, sizeof(Node));
    novo->val = val;
    novo->next = NULL;

    return novo;
}

void LinkedList_addFirst(LinkedList *L, int val){
    Node *p = Node_create(val);
    p->next = L->begin;
    L->begin = p;
    L->tam++;
    printf("\nAdicionado no início com sucesso!\n");
    printf("Tamanho da lista: %d\n", L->tam);
}

void LinkedList_addLast(LinkedList *L, int val){
    Node *q = Node_create(val);
    // caso a lista está vazia
    if (L->begin == NULL)
    {
        L->begin = q;
    }else{ // caso possua elementos
        Node *p = L->begin;
        // enquanot p não for o último nó
        while (p->next != NULL) 
        {
            p = p->next;
        }
        // neste momento, o p aponta para o nó final da lista

        // faz com que o próximo elemento do atual
        // ultimo nó aponte para o novo nó
        p->next = q;
    }
    L->tam++;
    printf("\nAdicionado no final com sucesso!\n");
    printf("Tamanho da lista: %d\n", L->tam);
}

void LinkedList_print(const LinkedList *L){
    Node *p = L->begin; // apenas referencia (não aloca dinamicamente)

    // enquanto p não chegar ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL)
    {
        printf("%d\n", p->val);
        p = p->next;
    }
    
}


