#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_ALUNOS 50

typedef struct
{
    char cpf[12]; 
    char nome[TAM_NOME];
    char tel[12]; 
    char email[40];
    char data_nasc[9]; 
} Aluno;


void cadastrar(Aluno alunos[], int *totalAlunos){
    if(*totalAlunos < TAM_ALUNOS){
        Aluno novoAluno;
        printf("\nDigite o CPF: ");
        setbuf(stdin, NULL);
        scanf("%12[^\n]s", &novoAluno.cpf);
        printf("Digite o nome: ");
        setbuf(stdin, NULL);
        scanf("%100[^\n]s", &novoAluno.nome);
        printf("Digite o telefone: ");
        setbuf(stdin, NULL);
        scanf("%12[^\n]s", &novoAluno.tel);
        printf("Digite o e-mail: ");
        setbuf(stdin, NULL);
        scanf("%40[^\n]s", &novoAluno.email);
        printf("Digite a data de nascimento [dd/mm/aaaa]: ");
        setbuf(stdin, NULL);
        scanf("%9[^\n]s", &novoAluno.data_nasc);
        
        alunos[*totalAlunos] = novoAluno;
        (*totalAlunos)++;

        printf("Cadastro realizado com sucesso.\n");
    } else{
        printf("Erro: Limite de alunos atingido.\n");
    }
}

void exibir(Aluno alunos[], int totalAlunos){
    printf("\nLista de Alunos:\n");
    for(int i = 0; i < totalAlunos; i++){
        printf("\nCPF: %s\nNome: %s\nTel: %s\nE-mail: %s\nData de nascimento: %s\n", alunos[i].cpf, alunos[i].nome, alunos[i].tel, alunos[i].email, alunos[i].data_nasc);
    }
}

int main()
{
    Aluno alunos[TAM_ALUNOS];
    int totalAlunos = 0;
    int op;

    do{
        printf("\nMENU\n");
        printf("\n 1. Cadastrar Aluno");
        printf("\n 2. Listar alunos");
        printf("\n 3. Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                cadastrar(alunos, &totalAlunos);
                break;
            case 2:
                exibir(alunos, totalAlunos);
                break;
            case 3:
                printf("\nEncerrando...\n");
                break;      
            default:
                printf("\nOpção inválida.\n");
                break;
        }

    }while(op!=3);



    return 0;
}
