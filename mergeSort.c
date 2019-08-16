#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(){
    int meuVetor[9] = {2,4,3,1,66,51,94,32,7};
    int comeco = 0, fim = 8;
    int i;

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

    mergeSort(meuVetor, comeco, fim);

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
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));


    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
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
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;
        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
