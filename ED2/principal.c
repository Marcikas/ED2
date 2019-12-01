#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projetoArvore/pessoa.h"
#include "arvoreLLRB.h"

#define N 15000

// variavel global
struct pessoa p[N];

// protótipo das funções
void readPessoa();
void printPessoa();

int main(){
    arvoreLLRB *raiz;
    raiz = cria_arvoreLLRB();
    int x, count;

    readPessoa();

    // inserção na árvore rubro negra
    clock_t clockInsertLLRB = clock();
    for(count = 1; count <= N; count++){
        insere_arvoreLLRB(raiz, p[count]);
    }
    printf("\nA insercao na arvore Rubro negra foi executada em %f segundos\n", ((double)clock() - clockInsertLLRB) / CLOCKS_PER_SEC);

    printf("\nBusca elementos pesquisa\n");
    printf("\n-----------------------------------------------------------\n");

    clock_t iniBuscaRemoveLLRB = clock();
    buscaElementosPesquisa_arvLLRB(raiz);
    printf("\nA operacao de busca dos 10 elementos + remocao do filho desejado na arvore Rubro negra foi executada em %f segundos\n",
            ((double)clock() - iniBuscaRemoveLLRB) / CLOCKS_PER_SEC);
    printf("\nBusca elementos pos operacoes\n");
    printf("\n-----------------------------------------------------------\n");

    clock_t iniImprimeLLRB = clock();
    imprimeElementosPosExclusao_arvLLRB(raiz);
    printf("\nA operacao de impressao dos 10 elementos apos a remocao dos nos na arvore Rubro negra foi executada em %f segundos\n",
            ((double)clock() - iniImprimeLLRB) / CLOCKS_PER_SEC);

    return 0;
}

void readPessoa() {
    FILE *arquivo;
    clock_t ini = clock();

    char *buf = malloc(N);
    char *tmp;

    /* VERIFICA SE HÁ MEMÓRIA SUFICIENTE*/
    if (buf == NULL) {
        printf ("Memoria insuficiente\n");
        return 1;
    }

    // LÊ O ARQUIVO
    if ((arquivo = fopen("massaDados.csv", "r")) == NULL){
        printf( "Arquivo não pode ser aberto.\n" );
    }

    int i = 1;
    while (fgets(buf, N, arquivo) != NULL)
    {
        if ((strlen(buf)>0) && (buf[strlen (buf) - 1] == '\n'))
            buf[strlen (buf) - 1] = '\0';

        tmp = strtok(buf, ";");
        p[i].p = atoi(tmp);

        tmp = strtok(NULL, ";");
        //p[i].nome = tmp[];
        strcpy(p[i].nome, tmp);

        tmp = strtok(NULL, ";");
        strcpy(p[i].idade, tmp);

        tmp = strtok(NULL, ";");
        strcpy(p[i].empresa, tmp);

        tmp = strtok(NULL, ";");
        strcpy(p[i].departamento, tmp);

        tmp = strtok(NULL, ";");
        strcpy(p[i].salario, tmp);

        i++;
    }
    free(buf);
    fclose(arquivo);
    printf("\nTransferencia do CSV para Struct foi executada em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

void printPessoa(){
    int i;

    for (i = 0; i <= N; i++){
        if (p[i].p != 0)
            printf("index i= %i  ID: %i, Nome: %s, Idade: %s, Empresa: %s, Departamento: %s, Salario: %s \n",i, p[i].p , p[i].nome, p[i].idade , p[i].empresa, p[i].departamento, p[i].salario);
        else
          continue;
    }
}


