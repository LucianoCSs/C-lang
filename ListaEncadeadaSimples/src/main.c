#include <stdio.h>
#include <stdlib.h>
#include "../include/ListaEncadeada.h"


int main(int argc, char const *argv[])
{
    
    int op, valor;
    LinkedList *L = LinkedList_create();

    do
    {
        printf("\n1 - Inserir no início da lista\n2 - Imprimir lista\n3 - Inserir no final da lista\n0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            LinkedList_addFirst(L, valor);
            break;
        case 2:
            printf("\nImprimindo lista...\n");
            LinkedList_print(L);
            break;
        case 3:
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            LinkedList_addLast(L, valor);
            break;    
        case 0:
            printf("\nFim do programa!\n");
            break;        
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (op!=0);
    
    return 0;
}
