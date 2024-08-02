#ifndef _LISTA_SEQUENCIAL_
#define _LISTA_SEQUENCIAL_
#define MAX 10

typedef struct{
    int matricula;
    char nome[30];
    float n1;
}Aluno;

typedef struct{
    int qtd;
    Aluno dados[MAX];
} Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_final(Lista* li, Aluno a1);
int insere_lista_inicio(Lista* li, Aluno a1);
int insere_lista_ordenada(Lista* li, Aluno a1);
int remove_lista_final(Lista* li);
int remove_lista_inicio(Lista* li);
int remove_lista(Lista* li, int mat);
int consulta_lista_pos(Lista* li, int pos, Aluno* al);
int consulta_lista_mat(Lista* li, int mat, Aluno* al);

#endif