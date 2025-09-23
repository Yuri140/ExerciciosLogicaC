/*
 ============================================================================
 Nome        : exercicio10.c
 Autor       : Yuri140
 Data        : 23/09/2025
 Descrição   : Desenvolver funções para manipulação de vetores, incluindo
               carregar valores, exibir elementos, calcular soma, ordenar
               em ordem crescente e decrescente.
 ============================================================================
*/

#include <stdio.h>


void ordenarVetorCrescente(int vetor[], int tamanho);
void ordenarVetorDecrescente(int vetor[], int tamanho);
void carregarVet(int vetor[], int tamanho);
void exibirVet(int vetor[], int tamanho);
int somarVet(int vetor[], int tamanho);


int vet[10];

int main(){
    int resp;
    int tamanho = 10;

    printf("INSERINDO VALORES NO VETOR \n");
    carregarVet(vet, tamanho);

    printf("\nEXIBINDO VALORES DO VETOR \n");
	exibirVet(vet, tamanho);

    printf("\nSOMANDO VALORES DO VETOR \n");
	resp = somarVet(vet, tamanho);
	printf("A soma dos valores do vetor e: %i\n", resp);

    printf("\nORDENANDO VALORES DO VETOR EM ORDEM CRESCENTE\n");
	ordenarVetorCrescente(vet, tamanho);
	exibirVet(vet, tamanho);

    printf("\nORDENANDO VALORES DO VETOR EM ORDEM DECRESCENTE\n");
	ordenarVetorDecrescente(vet, tamanho);
	exibirVet(vet, tamanho);

    return 0;
}

 

void carregarVet(int vetor[], int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("Digite um número: ");
        scanf("%i", &vetor[i]);
    }
}

void exibirVet(int vetor[], int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("vetor[%i] = %i \n", i, vetor[i]);
    }
}

 

int somarVet(int vetor[], int tamanho){
    int soma = 0;
    for(int i=0; i<tamanho; i++){
        soma = soma + vetor[i];
    }
    return soma;
}

 

void ordenarVetorCrescente(int vetor[], int tamanho){
    int temp;
    for (int i=0; i < tamanho - 1; i++){
        for(int j=0; j < tamanho - i-1; j++){
            if(vetor[j] > vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void ordenarVetorDecrescente(int vetor[], int tamanho){
    int temp;
    for (int i=0; i < tamanho - 1; i++){
        for(int j=0; j < tamanho - i-1; j++){
            if(vetor[j] < vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}