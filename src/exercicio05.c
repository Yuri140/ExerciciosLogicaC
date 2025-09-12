/*
 ============================================================================
 Nome        : exercicio05.c
 Autor       : Yuri140
 Data        : 12/09/2025
 Descrição   : Desenvolver um programa que leia 20 números inteiros digitados 
               pelo usuário. Posteriormente, exiba quantos números estão dentro 
               do intervalo [10, 50] e quantos estão fora dele.
 ============================================================================
*/

#include <stdio.h>

int main(){

    int numero, dentro = 0, fora = 0;

    printf("Insira 20 valores inteiros e será mostrado quantos estão dentro do intervalo [10, 50] e quantos estão fora dele.\n\n");

    for(int i = 1; i <= 20; i++){
        printf("Insira o %i° valor: ", i);
        scanf("%i", &numero);

        if(numero >= 10 && numero <= 50){
            dentro++;
        }else{
            fora++;
        }
    }

    if(dentro != 0){
        printf("A quantidade de valores dentro do intervalo [10, 50] é: %i\n", dentro);
    }else{
        printf("Não há valores dentro do intervalo [10, 50].\n");
    }
    if(fora != 0){
        printf("A quantidade de valores fora do intervalo [10, 50] é: %i\n", fora);
    }else{
        printf("Não há valores fora do intervalo [10, 50].\n");
    }

    return 0;
}