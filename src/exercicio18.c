/*
 ============================================================================
 Nome        : exercicio18.c
 Autor       : Yuri140
 Data        : 23/10/2025
 Descrição   : Desenvolver um programa que leia um número inteiro digitado
               pelo usuário e conte quantos algarismos pares esse número possui.
 ============================================================================
*/

#include <stdio.h>

int contarPares(int numero);

int main(){

    int numero;
    printf("Digite um número: ");
    scanf("%i", &numero);

    printf("A quantidade de algarismos pares no número %i, é: %i \n", numero, contarPares(numero));

    return 0;
}

int contarPares(int numero){

    int contador = numero, resto, pares = 0;

    while (contador != 0)
    {
        resto = contador % 10;

        if(resto % 2 == 0){
            pares++;
        }

        contador = contador / 10;
    }

    return pares;
    
}