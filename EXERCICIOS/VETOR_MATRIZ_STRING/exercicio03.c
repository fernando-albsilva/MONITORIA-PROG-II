/*

Carregue dois vetores A e B de números inteiros com 40 e 50 elementos respectivamente.
Desenvolva um programa para gerar um terceiro VETOR C com os elementos diferentes
existentes nos vetores A e B.

*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_A 40
#define TAMANHO_B 50

void preencheVet(int *, int);
void imprimeVet(int *, int);
int tamanhoVetC(int *,int,int *,int);
void preencheVetC(int *,int, int *, int, int *,int );
int main()
{
    int vetA[TAMANHO_A];
    int vetB[TAMANHO_B];
    int vetC;
    int TAMANHO_C;
    int *ptrA = &vetA[0], *ptrB = &vetB[0],*ptrC;
   
    
    

    preencheVet(ptrA, TAMANHO_A);
    printf(" \n Imprimindo Vetor A: \n");
    imprimeVet(ptrA, TAMANHO_A);

    preencheVet(ptrB, TAMANHO_B);
    printf("\n Imprimindo vetor B: \n");
    imprimeVet(ptrB, TAMANHO_B);

   TAMANHO_C=tamanhoVetC(ptrA,TAMANHO_A,ptrB,TAMANHO_B);
   
    ptrC=malloc(TAMANHO_C*sizeof(int));
    

    preencheVetC(ptrA,TAMANHO_A, ptrB,TAMANHO_B,ptrC,TAMANHO_C);
    printf("\n Imprimindo vetor C: \n");
    imprimeVet(ptrC, TAMANHO_C);

    return 0;
}

void preencheVet(int *vet, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        *vet = rand() % 100;
        vet++;
    }
}

void imprimeVet(int *vet,int tamanho)
{
    int i;
    printf("--------------------------------------------------------------\n");
    printf("Imprimindo vetor \n");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < tamanho; i++)
    {
        printf(" vet[%d] = %d\n", i, *vet);
        vet++;
    }
    printf("--------------------------------------------------------------\n");
}

int tamanhoVetC(int *vetA,int tam_a, int *vetB, int tam_b)
{
    int i,j,tamanhoC=0,teste=0;
    int *auxptrA=vetA,*auxptrB=vetB;

    for ( i = 0; i < tam_a ; i++)
    {

        for( j = 0; j < tam_b ; j++)
        {
            if(*vetA == *vetB)
            {
                teste=1;
                break;
            }
            vetB++;
        }
        vetB=auxptrB;
        if (teste == 0)
        {
            tamanhoC++;
        }
        teste=0;
        vetA++;
    }

    vetA=auxptrA;

       for ( i = 0; i < tam_b ; i++)
    {

        for( j = 0; j < tam_a ; j++)
        {
            if(*vetB == *vetA)
            {
                teste=1;
                break;
            }
            vetA++;
        }
        vetA=auxptrA;
        if (teste == 0)
        {
            tamanhoC++;
        }
        teste=0;
        vetB++;
    }
    return tamanhoC;
}

void preencheVetC(int *vetA,int tam_a, int *vetB, int tam_b, int *vetC,int tamanho_c)

{
    int i,j,teste=0;
    int *auxptrA=vetA,*auxptrB=vetB;

    for ( i = 0; i < tam_a ; i++)
    {

        for( j = 0; j < tam_b ; j++)
        {
            if(*vetA == *vetB)
            {
                teste=1;
                break;
            }
            vetB++;
        }
        vetB=auxptrB;
        if (teste == 0)
        {
            *vetC=*vetA;
             vetC++;
        }
        teste=0;
        vetA++;
    }

    vetA=auxptrA;

       for ( i = 0; i < tam_b ; i++)
    {

        for( j = 0; j < tam_a ; j++)
        {
            if(*vetB == *vetA)
            {
                teste=1;
                break;
            }
            vetA++;
        }
        vetA=auxptrA;
        if (teste == 0)
        {
            *vetC=*vetB;
             vetC++;
        }
        teste=0;
        vetB++;
    }
  
}