/*
 ============================================================================
 Nome        : exercicio04.c
 Autor       : Yuri140
 Data        : 12/09/2025
 Descrição   : Desenvolver um programa que leia 10 números inteiros digitados 
               pelo usuário. Posteriormente, exiba a soma dos números positivos 
               e a soma dos números negativos. Caso não haja números positivos 
               ou negativos, deve ser exibida uma mensagem apropriada.
 ============================================================================
*/

#include <stdio.h>

int main() {

    int numero, positivo = 0, negativo = 0;

    printf("Insira 10 valores inteiros e será mostrado a soma dos positivos e dos negativos digitados.\n\n");

    for(int i = 1; i <= 10; i++){
        printf("Insira o %i° valor: " , i);
        scanf("%i", &numero);

        if(numero >= 0){
            positivo = positivo + numero;
        }else{
            negativo = negativo + numero;
        }

    }

    if(positivo != 0){
        printf("A soma dos valores positivos é: %i\n", positivo);
    }else{
        printf("Não há valores positivos.\n");
    }
    if(negativo != 0){
        printf("A soma dos valores negativos é: %i\n", negativo);
    }else{
        printf("Não há valores negativos.\n");
    }

    return 0;
}
