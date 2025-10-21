/*
 ============================================================================
 Nome        : exercicio14.c
 Autor       : Yuri140
 Data        : 21/10/2025
 Descrição   : Desenvolver um programa que inverte
               a ordem dos elementos de um vetor.
 ============================================================================
*/

#include <stdio.h>

void atribuirValores(int vetor[], int tamanho);
void exibirVetor(int vetor[], int tamanho);
void inverterVetor(int vetor[], int tamanho);

int main(){

    int vetor[4];

    atribuirValores(vetor, 4);

    printf("Vetor original: \n");
    exibirVetor(vetor, 4);

    inverterVetor(vetor, 4);

    printf("\nVetor invertido: \n");
    exibirVetor(vetor, 4);
    
    return 0;
}

void inverterVetor(int vetor[], int tamanho){
    int temp = 0;
    for (int i = 0; i < tamanho / 2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[tamanho - 1 - i];
        vetor[tamanho - 1 - i] = temp;
    }
}

void exibirVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%i ", vetor[i]);
    }
}

void atribuirValores(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        vetor[i] = i + 1;
    }
}