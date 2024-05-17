#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_VETOR 100

// STRUCTS:
typedef struct
{
    char cpf[12]; 
    char nome[TAM_NOME];
    char tel[12]; 
    char email[40];
    char data_nasc[9]; 
} Aluno;

typedef struct
{
    char nome_prof[TAM_NOME];
    char email_prof[30];
    double sal_prof;
    char formacao_prof[30];
} Professor;

typedef struct
{
    char nome_resp[TAM_NOME];
    char parentesco[15];
    char endereco[50];
    char tel_resp[12];
} Responsavel;

typedef struct
{
    char nome[TAM_NOME];
    double carga_hora;
    char data_inicio[9]; 
    char data_final[9];
} Disciplina;

typedef struct{
    char serie[3]; 
    char periodo[8];
} Turma;

// FUNÇÕES:
void cadastrarAluno(Aluno alunos[], int *totalAlunos){
    if(*totalAlunos < TAM_VETOR){
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
        printf("Digite a data de nascimento [dia/mês/ano]: ");
        setbuf(stdin, NULL);
        scanf("%9[^\n]s", &novoAluno.data_nasc);
        
        alunos[*totalAlunos] = novoAluno;
        (*totalAlunos)++;

        printf("Cadastro realizado com sucesso.\n");
    } else{
        printf("Erro: Limite atingido.\n");
    }
}

void exibirAluno(Aluno alunos[], int totalAlunos){
    printf("\nLista de Alunos:\n");
    for(int i = 0; i < totalAlunos; i++){
        printf("\nCPF: %s\nNome: %s\nTel: %s\nE-mail: %s\nData de nascimento: %c%c/%c%c/%c%c%c%c\n", 
        alunos[i].cpf, alunos[i].nome, alunos[i].tel, alunos[i].email, 
        alunos[i].data_nasc[0], alunos[i].data_nasc[1], alunos[i].data_nasc[2], 
        alunos[i].data_nasc[3], alunos[i].data_nasc[4], alunos[i].data_nasc[5], 
        alunos[i].data_nasc[6], alunos[i].data_nasc[7], alunos[i].data_nasc[8]);
    }
}

void cadastrarProf(Professor profs[], int *totalProf){
    if(*totalProf < TAM_VETOR){
        Professor prof;
        printf("\nDigite o nome do professor: ");
        setbuf(stdin, NULL);
        scanf("%50[^\n]s", &prof.nome_prof);
        printf("Digite o e-mail: ");
        setbuf(stdin, NULL);
        scanf("%30[^\n]s", &prof.email_prof);
        printf("Digite o salário: ");
        setbuf(stdin, NULL);
        scanf("%lf", &prof.sal_prof);
        printf("Digite a formação: ");
        setbuf(stdin, NULL);
        scanf("%30[^\n]s", &prof.formacao_prof);

        profs[*totalProf] = prof;
        (*totalProf)++;

        printf("Cadastro realizado com sucesso.\n");
    }else{
        printf("Erro: Limite atingido.\n");
    }
}

void exibirProf(Professor profs[], int totalProf){
    printf("\nLista de Professores:\n");
    for(int i = 0; i < totalProf; i++){
        printf("\nNome: %s\nE-mail: %s\nSalário: R$ %.2lf\nFormação: %s\n", profs[i].nome_prof, profs[i].email_prof, profs[i].sal_prof, profs[i].formacao_prof);
    }
}

void cadastrarResp(Responsavel resps[], int *totalResp){
    if(*totalResp < TAM_VETOR){
        Responsavel resp;
        printf("\nDigite o nome do responsável: ");
        setbuf(stdin, NULL);
        scanf("%50[^\n]s", &resp.nome_resp);
        printf("Digite o parentesco: ");
        setbuf(stdin, NULL);
        scanf("%15[^\n]s", &resp.parentesco);
        printf("Digite o endereço: ");
        setbuf(stdin, NULL);
        scanf("%50[^\n]s", &resp.endereco);
        printf("Digite o telefone: ");
        setbuf(stdin, NULL);
        scanf("%12[^\n]s", &resp.tel_resp);

        resps[*totalResp] = resp;
        (*totalResp)++;

        printf("Cadastro realizado com sucesso.\n");
    }else{
        printf("Erro: Limite atingido.\n");
    }
}

void exibirResp(Responsavel resps[], int totalRes){
    printf("\nLista de Responsáveis:\n");
    for(int i = 0; i < totalRes; i++){
        printf("\nNome: %s\nParentesco: %s\nEndereço: %s\nTelefone: %s\n", resps[i].nome_resp, resps[i].parentesco, resps[i].endereco, resps[i].tel_resp);
    }
}

void cadastrarDisc(Disciplina discs[], int *totalDisc){
    if(*totalDisc < TAM_VETOR){
        Disciplina disc;
        printf("\nDigite o nome da disciplina: ");
        setbuf(stdin, NULL);
        scanf("%50[^\n]s", &disc.nome);
        printf("Digite a carga horária: ");
        setbuf(stdin, NULL);
        scanf("%lf", &disc.carga_hora);
        printf("Digite a data de início [dia/mês/ano]: ");
        setbuf(stdin, NULL);
        scanf("%9[^\n]s", &disc.data_inicio);
        printf("Digite a data de encerramento [dia/mês/ano]: ");
        setbuf(stdin, NULL);
        scanf("%9[^\n]s", &disc.data_final);

        discs[*totalDisc] = disc;
        (*totalDisc)++;

        printf("Cadastro realizado com sucesso.\n");
    }else{
        printf("Erro: Limite atingido.\n");
    }
}

void exibirDisc(Disciplina discs[], int totalDisc){
    printf("\nLista de Disciplinas:\n");
    for(int i = 0; i < totalDisc; i++){
        printf("\nDisciplina: %s\nCarga Horária: %.0lf hs\nData de Início: %c%c/%c%c/%c%c%c%c\n", 
        discs[i].nome, discs[i].carga_hora, discs[i].data_inicio[0], discs[i].data_inicio[1], discs[i].data_inicio[2], discs[i].data_inicio[3], 
        discs[i].data_inicio[4], discs[i].data_inicio[5], discs[i].data_inicio[6], discs[i].data_inicio[7], discs[i].data_inicio[8]);
        printf("Data Final: %c%c/%c%c/%c%c%c%c\n", discs[i].data_final[0], discs[i].data_final[1], discs[i].data_final[2], discs[i].data_final[3], 
        discs[i].data_final[4], discs[i].data_final[5], discs[i].data_final[6], discs[i].data_final[7], discs[i].data_final[8]);
    }
}

void cadastrarTurma(Turma turmas[], int *totalTurma){
    if(*totalTurma < TAM_VETOR){
        Turma turma;
        printf("\nDigite a série: ");
        setbuf(stdin, NULL);
        scanf("%3[^\n]s", &turma.serie);
        printf("Digite o período: ");
        setbuf(stdin, NULL);
        scanf("%8[^\n]s", &turma.periodo);

        turmas[*totalTurma] = turma;
        (*totalTurma)++;

        printf("Cadastro realizaod com sucesso.\n");
    }else{
        printf("Erro: Limite atingido.\n");
    }
}

void exibirTurma(Turma turmas[], int totalTurma){
    printf("\nLista de Turmas: \n");
    for(int i = 0; i < totalTurma; i++){
        printf("\nSérie: %s\nPeríodo: %s\n", turmas[i].serie, turmas[i].periodo);
    }
}

int main()
{
    Aluno alunos[TAM_VETOR];
    int totalAlunos = 0;

    Professor profs[TAM_VETOR];
    int totalProf = 0;

    Responsavel resps[TAM_VETOR];
    int totalRes = 0;

    Disciplina discs[TAM_VETOR];
    int totalDisc = 0;

    int op;

    printf("\n***Bem vindo(a) ao CadEdu***\n");
    do{
        printf("\nMENU\n");
        printf("\n 1. Cadastrar Aluno");
        printf("\n 2. Listar alunos");
        printf("\n 3. Cadastrar Professor");
        printf("\n 4. Listar professores");
        printf("\n 5. Cadastrar Responsável");
        printf("\n 6. Listar responsáveis");
        printf("\n 7. Cadastrar Disciplina");
        printf("\n 8. Listar disciplina");
        printf("\n 9. Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                cadastrarAluno(alunos, &totalAlunos);
                break;
            case 2:
                exibirAluno(alunos, totalAlunos);
                break;
            case 3:
                cadastrarProf(profs, &totalProf);
                break;
            case 4:
                exibirProf(profs, totalProf);
                break;
            case 5:
                cadastrarResp(resps, &totalRes);
                break;
            case 6:
                exibirResp(resps, totalRes);
                break;
            case 7:
                cadastrarDisc(discs, &totalDisc);
                break;
            case 8:
                exibirDisc(discs, totalDisc);
                break;                        
            case 9:
                printf("\nEncerrando...\n");
                break;      
            default:
                printf("\nOpção inválida.\n");
                break;
        }

    }while(op!=9);



    return 0;
}
