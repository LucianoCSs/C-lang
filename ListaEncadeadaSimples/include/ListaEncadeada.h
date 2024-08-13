#ifndef _LISTA_ENCADEADA_H
#define _LISTA_ENCADEADA_H

/* PROTOTIPOS: */

// Nó
typedef struct _node Node;

// Lista
typedef struct _linked_list LinkedList;

// Cria Lista
LinkedList *LinkedList_create();

// Cria um Nó
Node *Node_create(int val);

// Inserção no começo da Lista
void LinkedList_addFirst(LinkedList *L, int val);

// Insere no final da Lista
void LinkedList_addLast(LinkedList *L, int val);

// Imprime lista
void LinkedList_print(const LinkedList *L);

// Menu do programa
void menu();

#endif