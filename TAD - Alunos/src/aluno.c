#include <stdio.h>
#include "../include/aluno.h"


static void cadastrar(){
    Aluno aluno;
    FILE* fb = fopen("aluno.bin", "ab");
    if (fb != NULL)
    {
        printf("\nCADASTRO:\n");
        printf("\nNome: ");
        setbuf(stdin, NULL);
        scanf("%49[^\n]s", aluno.nome);
        printf("Mátricula: ");
        scanf("%d", &aluno.matricula);
        printf("Nota: ");
        scanf("%lf", &aluno.nota);
        // grava a struc no arquivo
        fwrite(&aluno, sizeof(Aluno), 1, fb);
        printf("\nCadastro realizado com sucesso!\n");
    }else{
        printf("\nErro na abertura do arquivo!\n");
    }
    fclose(fb);
}

static void imprimir(){
    Aluno aluno;
    FILE* fb = fopen("aluno.bin", "rb");
    if (fb != NULL)
    {
        while (!feof(fb))
        {
            if(fread(&aluno, sizeof(Aluno), 1, fb)){
                printf("\nNome: %s\nMatricula: %d\nNota: %.2f\n", aluno.nome, aluno.matricula, aluno.nota);
            }
        }
    }else{
        printf("\nErro na abertura do arquivo!\n");
    }
    fclose(fb);
}

static void excluir(){
    FILE* arquivo = fopen("aluno.bin", "rb");
    FILE* arquivoNovo = fopen("alunoTemp.bin", "ab");
    Aluno aluno;
    int m;

    if (arquivo == NULL || arquivoNovo == NULL)
    {
        printf("\nErro na abertura do arquivo!\n");
    }else{
        printf("\nDigite a matrícula do aluno a ser excluído: ");
        setbuf(stdin, NULL);
        scanf("%d", &m);

        while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1)
        {   // compara nome digitado com dados no arquivo
            if(m != aluno.matricula) 
            {   // reescreve o arquivo original sem a matrícula digitada
                fwrite(&aluno, sizeof(Aluno), 1, arquivoNovo); 
            }
        }
    }
    fclose(arquivo);
    fclose(arquivoNovo);
    remove("aluno.bin"); // exclui arquivo original
    rename("alunoTemp.bin", "aluno.bin"); // renomeia arquivo modificado
    printf("\nExcluído com sucesso!\n");
}

void menu(){
    int op;
    do
    {
        printf("\n1 - Cadastrar\n");
        printf("2 - Imprimir\n");
        printf("3 - Excluir\n");
        printf("0 - Sair\n");
        printf("Resposta: ");
        setbuf(stdin, NULL);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            imprimir();
            break;    
        case 3:
            excluir();
            break;
        case 0:
            printf("\nFim do programa.\n");
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (op != 0);
}
    
