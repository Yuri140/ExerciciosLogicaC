/*
 ============================================================================
 Nome        : exercicio16.c
 Autor       : Yuri140
 Data        : 23/10/2025
 Descrição   : Desenvolver um programa que leia uma palavra ou número
               digitado pelo usuário e verifique se o valor lido é 
               um palíndromo (lê-se igual de trás para frente).
 ============================================================================
*/

#include <stdio.h>
#include <string.h>

int verificarPalindromo(char texto[]);

int main(){

    char texto[] = "";

    printf("Insira um valor para verificar se ele é um palindromo: ");
    scanf("%s", texto);

    if(verificarPalindromo(texto)){
        printf("O valor inserido é um palindromo\n");
    }else{
        printf("O valor inserido não é um palindromo\n");
    }

    return 0;
}

int verificarPalindromo(char texto[]){
    int tamanho = strlen(texto);

    for(int i = 0; i < tamanho / 2; i++){
        if (texto[i] != texto[tamanho - 1 - i]){
            return 0;
        }
    }
    return 1;
}
