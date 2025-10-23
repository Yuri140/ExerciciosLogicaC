/*
 ============================================================================
 Nome        : exercicio17.c
 Autor       : Yuri140
 Data        : 23/10/2025
 Descrição   : Desenvolver um programa que leia um número inteiro digitado
               pelo usuário e verifique se o número é um palíndromo (lê-se 
               igual de trás para frente).
 ============================================================================
*/

#include <stdio.h>

int verificarPalindromo(int numero);

int main(){

    int numero;

    printf("Insira um valor para verificar se ele é um palindromo: ");
    scanf("%i", &numero);

    if(verificarPalindromo(numero)){
        printf("O valor inserido é um palindromo\n");
    }else{
        printf("O valor inserido não é um palindromo\n");
    }

    return 0;
}

int verificarPalindromo(int numero){

    int resto, invertido = 0, original = numero;

    while(numero != 0){
        resto = numero % 10;
        invertido = invertido * 10 + resto;
        numero = numero / 10;
    }

    if(original == invertido)
        return 1;
    else
        return 0;
}