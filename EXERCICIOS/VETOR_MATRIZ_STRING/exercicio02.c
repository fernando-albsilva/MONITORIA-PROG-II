/*

2- Carregue um vetor de 50 elementos inteiros e não ordenados. Leia um determinado número e
pesquise se o mesmo existe no VETOR. Caso exista, imprimir seu valor e em que posição ele
está, caso contrário, exiba uma mensagem.

*/

#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int *);
void imprimeVetor(int *);
void pesquisa(int *);
void pesquisaElemento(int *, int);

#define TAMANHO 50

int main()
{
    int vet[TAMANHO];
    int *ptr = &vet[0];

    preencheVetor(ptr);
    imprimeVetor(ptr);
    pesquisa(ptr);

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

void pesquisa(int *vet)
{
    int elemento;

    printf("--------------------------------------------------------------\n");
    printf("Digite o elemento que deseja buscar no vetor : ");
    scanf("%d", &elemento);
    printf("\n--------------------------------------------------------------\n");
    printf("buscando elemento %d no vetor . \n", elemento);
    printf("--------------------------------------------------------------\n");
    pesquisaElemento(vet, elemento);
}

void pesquisaElemento(int *vet, int elemento)
{
    int i;
    int teste = 0;

    for (i = 0; i < TAMANHO; i++)
    {
        if (*vet == elemento)
        {
            printf(" Elemento de valor : %d , encontrado na posição %d do vetor.\n", elemento, i + 1);
            printf("--------------------------------------------------------------\n");
            teste = 1;
        }
        vet++;
    }
    if (teste == 0)
    {
        printf("Elemento não encontrado no vetor .\n\n\n");
    }
}
