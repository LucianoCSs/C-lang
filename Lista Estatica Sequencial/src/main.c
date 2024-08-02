#include <stdio.h>
#include "../include/ListaSequencial.h"

int main(void)
{
    Lista* li;

    int op, x, mat;
    
    Aluno a;

    do
    {   
        printf("\n1 - Para criar lista\n");
        printf("2 - Inserir no final da lista\n");
        printf("3 - Consultar por matrícula\n");
        printf("4 - Remover um aluno\n");
        printf("5 - Verificar tamanho da lista\n");
        printf("0 - Sair\n");
        printf("Resposta: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            li = cria_lista();
            if (li == NULL)
            {
                printf("\nERRO na criação!\n");
            }else{
                printf("\nLista criada com sucesso!\n");
            }
            break;
        case 2:
            printf("\nNome do aluno: ");
            setbuf(stdin, NULL);
            scanf("%29[^\n]s", a.nome);
            printf("Matrícula do aluno: ");
            scanf("%d", &a.matricula);
            printf("Nota: ");
            scanf("%f", &a.n1);
            x = insere_lista_final(li, a);
            if (x == 1)
            {
                printf("\nAluno cadastrado com sucesso!\n");
            }else{
                printf("\nERRO: lista cheia ou inexistente!\n");
            }
            
            break;
        case 3:
            printf("\nDigite a matrícula: ");
            scanf("%d", &mat);
            x = consulta_lista_mat(li, mat, &a);
            if(x == 1){
                printf("\nNome: %s\nMatrícula: %d\nNota: %.1f\n", a.nome, a.matricula, a.n1);
            }else{
                printf("\nMatrícula não encontrada!\n");
            }
            break;
        case 4:
            printf("\nMatrícula do aluno a ser removido: ");
            scanf("%d", &mat);
            x = remove_lista(li, mat);
            if (x == 1)
            {
                printf("\nRemovido com sucesso!\n");
            }else{
                printf("\nMatrícula não encontrada!\n");
            }
            break;
        case 5:
            x = tamanho_lista(li);
            printf("\nTamanho da lista: %d\n", x);
            break;            
        case 0:
            libera_lista(li);
            printf("\nFim do programa.\n");
            break;    
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (op != 0);
    

    return 0;
}

