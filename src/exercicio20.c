/*
 ============================================================================
 Nome        : exercicio20.c
 Autor       : Yuri140
 Data        : 24/10/2025
 Descrição   : Desenvolver um programa que leia um número inteiro positivo
               digitado pelo usuário e converta esse número para sua
               representação em binário, exibindo o resultado na tela.
 ============================================================================
*/

#include <stdio.h>

int converterBinario(int numero);

int main(){

    int numero;
    printf("Digite um número: ");
    scanf("%i", &numero);

    printf("O número %i em binario é: ", numero);
    converterBinario(numero);

    return 0;
}

int converterBinario(int numero){

    int tamanho = 200;
    char binario[tamanho];
    int resto = 0;
    int temp;

    for(int i = 0; numero != 0; i++){
        resto = numero % 2;
        numero = numero / 2;
        binario[i] = resto;
        tamanho = i + 1;
    }

    for(int i = 0; i < tamanho / 2; i++){
        temp = binario[i];
        binario[i] = binario[tamanho - 1 - i];
        binario[tamanho - 1- i] = temp;
    }

    for(int i = 0; i < tamanho; i++){
        printf("%i", binario[i]);
    }

}