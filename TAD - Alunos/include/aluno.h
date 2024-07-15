#ifndef _ALUNO_
#define _ALUNO_

typedef struct{
    int matricula;
    char nome[50];
    double nota;
}Aluno;

void cadastrar();
void imprimir();
void excluir();
void menu();

#endif