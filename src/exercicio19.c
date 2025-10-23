/*
 ============================================================================
 Nome        : exercicio19.c
 Autor       : Yuri140
 Data        : 23/10/2025
 Descrição   : Desenvolver um programa que leia um número inteiro positivo
               digitado pelo usuário e calcule a soma de todos os números
               ímpares entre 1 e o número digitado (não incluindo o próprio).
 ============================================================================
*/

#include <stdio.h>

int somaImpares(int numero);

int main(){

    int numero;
    printf("Digite um número: ");
    scanf("%i", &numero);

    printf("A soma dos números impares entre 1 e %i é: %i", numero, somaImpares(numero));

    return 0;
}

int somaImpares(int numero){

    int impar = 0;

    for (int i = 1; i < numero; i++)
    {
        if(i % 2 != 0){
            impar = impar + i;
        }
    }
    
    return impar;

}