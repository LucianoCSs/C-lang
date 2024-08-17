#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    Node *end;
    int tam;
} LinkedList;

// cria a lista
LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1, sizeof(LinkedList)); // por padrão calloc inicializa tudo em 0
    L->begin = NULL;
    L->end = NULL;
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

bool LinkedList_isEmpty(const LinkedList *L){
    return (L->begin == NULL && L->end == NULL);
}

void LinkedList_addFirst(LinkedList *L, int val){
    Node *p = Node_create(val);
    p->next = L->begin;
    L->begin = p;
    L->tam++;
    printf("\nAdicionado no início com sucesso!\n");
    printf("Tamanho da lista: %d\n", L->tam);
}

void LinkedList_addFirst2(LinkedList *L, int val){
    Node *p = Node_create(val);
    p->next = L->begin;

    if (LinkedList_isEmpty(L))
    {
        L->end = p;
    }
    L->begin = p;
    L->tam++;
    printf("\nAdicionado no início com sucesso!\n");
    printf("Tamanho da lista: %d\n", L->tam);
}

void LinkedList_addLast(LinkedList *L, int val){
    Node *q = Node_create(val);
    // caso a lista estiver vazia
    if (LinkedList_isEmpty(L))
    {
        L->begin = q;
    }else{ // caso possua elementos
        Node *p = L->begin;
        // enquanto p não for o último nó
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

// Inserção no final MELHORADA
void LinkedList_addLast2(LinkedList *L, int val){
    Node *q = Node_create(val);

    // se a lista estiver vazia
    if (LinkedList_isEmpty(L))
    {
        L->begin = q;
        L->end = q;
    }else{ // caso já haja elementos
        L->end->next = q; // ponteiro de end aponta para o próximo do último elemento
        L->end = L->end->next;
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

void menu(){
    int op, valor;
    LinkedList *L = LinkedList_create();

    do
    {
        printf("\n1 - Inserir no início da lista\n2 - Imprimir lista\n3 - Inserir no final da lista\n0 - Sair\n");
        printf("Opção: ");
        setbuf(stdin, NULL);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nDigite um valor: ");
            setbuf(stdin, NULL);
            scanf("%d", &valor);
            LinkedList_addFirst2(L, valor);
            break;
        case 2:
            printf("\nImprimindo lista...\n");
            LinkedList_print(L);
            break;
        case 3:
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            LinkedList_addLast2(L, valor);
            break; 
        case 0:
            printf("\nFim do programa!\n");
            break;        
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (op!=0);
}


