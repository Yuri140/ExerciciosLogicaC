/*
 ============================================================================
 Nome        : exercicio06.c
 Autor       : Yuri140
 Data        : 15/09/2025
 Descrição   : Desenvolver um programa que leia um número inteiro não negativo 
               e exiba o valor do seu fatorial. Caso o número digitado seja 
               negativo, exibir uma mensagem de erro.
 ============================================================================
*/

#include <stdio.h>
int main(){

    int numero, fatorial = 1;

    printf("Insira um valor inteiro e será mostrado o valor fatorial dele: \n");
    scanf("%i", &numero);

    if(numero >= 0){

        while(numero > 0){
            fatorial = fatorial * numero;
            numero--;
        }

        printf("O fatorial do número inserido é: %i\n", fatorial);

    }else{
        printf("Não existe fatorial de um numero negativo\n");
    }

    return 0;
}