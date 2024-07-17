#ifndef _ALUNO_
#define _ALUNO_

typedef struct{
    int matricula;
    char nome[50];
    double nota;
}Aluno;

static void cadastrar();
static void imprimir();
static void excluir();
void menu();

#endif
