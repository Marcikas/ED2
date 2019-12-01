#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvoreLLRB.h"

#define N 15000

// Struct com base no csv
struct pessoa {
  int p;
  char nome[30];
  char idade[2];
  char empresa[30];
  char departamento[50];
  char salario[10];
};

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
    //printPessoa();

    // inserção na árvore rubro negra
    clock_t ini = clock();
    for(count = 1; count <= N; count++){
        insere_arvoreLLRB(raiz, p[count].p);
        //printf("\n%d", p[count].p);
    }
    printf("\nA insercao na arvore Rubro negra foi executada em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);

    printf("\nPre ordem\n");
    //preOrdem_arvLLRB(raiz);
    /*printf("\nEm ordem\n");
    emOrdem_arvLLRB(raiz);
    printf("\nPos ordem\n");
    posOrdem_arvLLRB(raiz);
*/
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


