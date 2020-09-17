/* 

Carregue um vetor de inteiros com 100 posições e desenvolva um programa para:
a) Exibir o maior elemento e sua posição; ok
b) Imprimir a soma dos elementos que estão nos índices pares; ok
c) Exiba a soma dos elementos impares.

*/

#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int *);
void imprimeVetor(int *);
void exibeMaiorElemento(int *);
void somaElementoIndicePar(int *);
void somaElementoImpar(int *);

#define TAMANHO 99
int main()
{
    int vet[TAMANHO];
    int *ptr = &vet[0];
    preencheVetor(ptr);
    imprimeVetor(ptr);
    exibeMaiorElemento(ptr);
    somaElementoIndicePar(ptr);
    somaElementoImpar(ptr);

    return 0;
}

void preencheVetor(int *vet)
{
    int i;
    for (i = 0; i < TAMANHO; i++)
    {
        *vet = rand() % 100;
        vet++;
    }
}

void imprimeVetor(int *vet)
{
    int i;
    printf("--------------------------------------------------------------\n");
    printf("Imprimindo vetor \n");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf(" vet[%d] = %d\n", i, *vet);
        vet++;
    }
    printf("--------------------------------------------------------------\n");
}

void exibeMaiorElemento(int *vet)

{

    // Obs : a função nao considera a possibilidade de ter dois valores iguais

    int posicao = 0, valor = *vet, i;
    vet++;

    for (i = 1; i < TAMANHO; i++)
    {
        if (*vet > valor)
        {
            valor = *vet;
            posicao = i;
        }
        vet++;
    }
    printf("--------------------------------------------------------------\n");
    printf("Maior elemento do vetor é vet[%d] = %d\n", posicao, valor);
    printf("--------------------------------------------------------------\n");
}

void somaElementoIndicePar(int *vet)
{
    int soma = 0, i;

    for (i = 0; i < TAMANHO; i++)
    {
        if (i % 2 == 0)
        {
            soma += *vet;
        }
        vet++;
    }
    printf("--------------------------------------------------------------\n");
    printf(" A Soma dos elementos de indice par do vetor é : %d\n", soma);
    printf("--------------------------------------------------------------\n");
}

void somaElementoImpar(int *vet)
{

    int soma = 0, i;
    printf("--------------------------------------------------------------\n");
    printf("Imprimindo todos valores impares do vetor : \n");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < TAMANHO; i++)
    {
        if (*vet % 2 != 0)
        {
            printf("valor impar no vetor = %d\n", *vet);
            soma += *vet;
        }
        vet++;
    }
    printf("--------------------------------------------------------------\n");
    printf(" A Soma dos elementos de valor impar é : %d\n", soma);
    printf("--------------------------------------------------------------\n");
}
