#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(){
    int meuVetor[9] = {2,4,3,1,66,51,94,32,7}; // inser��o de valores no vetor
    int comeco = 0, fim = 9; // defini��o do par�metro de in�cio e fim
    int i;

    // impress�o do vetor desordenado
    printf("\n---------------------------------");
    printf("\nDESORDENADO");
    printf("\n---------------------------------");
    printf("\n%d \n", meuVetor[0]);
    printf("%d \n", meuVetor[1]);
    printf("%d \n", meuVetor[2]);
    printf("%d \n", meuVetor[3]);
    printf("%d \n", meuVetor[4]);
    printf("%d \n", meuVetor[5]);
    printf("%d \n", meuVetor[6]);
    printf("%d \n", meuVetor[7]);
    printf("%d \n", meuVetor[8]);

    mergeSort(meuVetor, comeco, fim); // chamada da fun��o de ordena��o com os par�metros definidos anteriormente

    // impress�o dos valores ordenados
    printf("\n---------------------------------");
    printf("\nORDENADO");
    printf("\n---------------------------------");
    printf("\n%d \n", meuVetor[0]);
    printf("%d \n", meuVetor[1]);
    printf("%d \n", meuVetor[2]);
    printf("%d \n", meuVetor[3]);
    printf("%d \n", meuVetor[4]);
    printf("%d \n", meuVetor[5]);
    printf("%d \n", meuVetor[6]);
    printf("%d \n", meuVetor[7]);
    printf("%d \n", meuVetor[8]);

    return 0;
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux; // cria um novo vetor que vai manter o resultado da ordena��o dos 2 sub-vetores
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) { // aqui � feita a compara��o dos valores
            vetAux[comAux] = vetor[com1]; // atribui ao vetor auxiliar o valor 1
            com1++;
        } else {
            vetAux[comAux] = vetor[com2]; // atribui ao vetor auxiliar o valor 2
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    free(vetAux); // libera memoria ocupada pelo vetor auxiliar
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) { // o par�metro de comeco tem que ser obrigatoriamente menor que o parametro fim
        int meio = (fim+comeco)/2; // defini��o da vari�vel do meio
        mergeSort(vetor, comeco, meio); // primeira divis�o, chama a fun��o recursivamente passando o meio como parametro no lugar do fim
        mergeSort(vetor, meio+1, fim); // segunda divis�o (meio + 1 caso o numero de elementos no vetor seja �mpar ele joga o numero que "sobrou" para a metade final)
        merge(vetor, comeco, meio, fim); // "conquista"
    }
}
