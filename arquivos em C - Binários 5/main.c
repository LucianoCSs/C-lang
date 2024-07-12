#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

typedef struct{
    char nome[TAM];
    int idade;
    double salario;
}Pessoa;

void escrever(){
    Pessoa p;
    FILE *fb = fopen("pessoa.bin", "ab");
    if (fb != NULL)
    {
        printf("\nCADASTRO:\n");
        printf("\nNome: ");
        setbuf(stdin, NULL);
        scanf("%49[^\n]s", p.nome);
        printf("Idade: ");
        scanf("%d", &p.idade);
        printf("Salário: ");
        scanf("%lf", &p.salario);
        // grava a struc no arquivo
        fwrite(&p, sizeof(Pessoa), 1, fb);
        printf("\nCadastro realizado com sucesso!\n");
    }else
    {
        printf("\nErro na abertura do arquivo!\n");
        exit(1);
    }
    fclose(fb);
}

void leitura(){
    Pessoa p;
    FILE *fb = fopen("pessoa.bin", "rb");
    printf("\nLISTAR:\n");
    if (fb != NULL)
    {   
        while(!feof(fb))
        {   // enquanto não chegar oo fim do arquivo (EOF), faz a leitura
            if(fread(&p, sizeof(Pessoa), 1, fb)){
                printf("\nNome: %s\nIdade: %d\nSalário: R$ %.2f\n", p.nome, p.idade, p.salario);
            }
        }   
    }else{
        printf("\nErro na abertura do arquivo!\n");
        exit(1);
    }
    fclose(fb); 
}

void excluir(){
    FILE* arqOriginal = fopen("pessoa.bin", "rb");
    FILE* arqModificado = fopen("pessoaTemp.bin", "ab");
    Pessoa p;
    char n[TAM];

    if (arqOriginal == NULL || arqModificado == NULL)
    {
        printf("\nErro na abertura do arquivo!\n");
    }else{
        printf("\nEXCLUIR:\n");
        printf("\nDigite a pessoa a ser excluída: ");
        setbuf(stdin, NULL);
        scanf("%49[^\n]s", &n);

        while (fread(&p, sizeof(Pessoa), 1, arqOriginal) == 1)
        {   // compara nome digitado com dados no arquivo
            if(strcmp(n, p.nome) != 0) 
            {   // reescreve o arquivo original sem o nome digitado
                fwrite(&p, sizeof(Pessoa), 1, arqModificado); 
            }
        }
    }
    fclose(arqOriginal);
    fclose(arqModificado);
    remove("pessoa.bin"); // exclui arquivo original
    rename("pessoaTemp.bin", "pessoa.bin"); // renomeia arquivo modificado
    printf("\nExcluído com sucesso!\n");
}

void menu(){
    int op;
    do
    {
        printf("\n1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Excluir\n");
        printf("0 - Sair\n");
        printf("Resposta: ");
        setbuf(stdin, NULL);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            escrever();
            break;
        case 2:
            leitura();
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

int main(int argc, char const *argv[])
{
    
    menu();

    return 0;
}
