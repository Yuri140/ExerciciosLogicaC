/*
 ============================================================================
 Nome        : exercicio15.c
 Autor       : Yuri140
 Data        : 21/10/2025
 Descrição   : Programa que lê 5 valores inteiros, detecta valores duplicados
               exibindo-os na tela, e cria um novo vetor contendo apenas os
               valores únicos, removendo todas as duplicatas encontradas.
 ============================================================================
*/

#include <stdio.h>

void analisarVetor(int vetor[], int tamanho);
void exibirVetor(int vetor[], int tamanho);

int main(){

    int vetor[5];

    printf("Insira 5 valores inteiros no vetor:\n");
    for(int i = 0; i < 5; i++){
        printf("Valor %i: ", i + 1);
        scanf("%i", &vetor[i]);
    }

    analisarVetor(vetor, 5);

    return 0;
}

void analisarVetor(int vetor[], int tamanho){
    int vetorSemDuplicados[tamanho];
    int tamanhoNovo = 0;
    int jaExiste;

    for (int i = 0; i < tamanho; i++){
        jaExiste = 0;
        
        for (int j = 0; j < tamanhoNovo; j++){
            if (vetor[i] == vetorSemDuplicados[j]){
                jaExiste = 1;
                printf("Valor duplicado encontrado: %i\n", vetor[i]);
                break;
            }
        }
    
        if (!jaExiste){
            vetorSemDuplicados[tamanhoNovo] = vetor[i];
            tamanhoNovo++;
        }
    }

    printf("\nVetor sem duplicados:\n");
    exibirVetor(vetorSemDuplicados, tamanhoNovo);
}

void exibirVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%i ", vetor[i]);
    }
}