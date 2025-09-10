/*
 ============================================================================
 Nome        : exercicio03.c
 Autor       : Yuri140
 Data        : 09/09/2025
 Descrição   : Desenvolver um programa que leia um número inteiro positivo e exiba a soma dos seus algarismos.
 ============================================================================
*/


#include <stdio.h>

int main() {
    int numero, soma = 0;

    printf("Digite um numero: ");
    scanf("%i", &numero);

    
    while (numero != 0) {
        soma += numero % 10;
        numero /= 10;      
    }

    printf("A soma dos algarismos é: %i\n", soma);

    return 0;
}