/*
 ============================================================================
 Nome        : exercicio01.c
 Autor       : Yuri140
 Data        : 09/09/2025
 Descrição   : Desenvolver um programa que leia números até que o usuário
               digite um número negativo. Posteriormente, exiba o maior e o 
               menor digitado pelo usuário (não considerar o número negativo).
 ============================================================================
*/
 
#include <stdio.h>
 
int main()
{ 
    int num, maior, menor, iniciar = 1;
     
    do{ 
        printf("Insira um numero inteiro positivo, ou insira um valor inteiro negativo para encerrar: ");
        scanf("%i", &num);
         
        if(num >= 0){
            if(iniciar == 1){
                maior = num;
                menor = num;
                iniciar = 0;
            }else{
                if(num > maior){
                    maior = num;
                }
                if(num < menor){
                    menor = num;
                }
            }
        }
         
    }while(num >= 0);
     
    if(iniciar == 0){
        printf("\nO maior valor digitado foi: %i \n", maior);
        printf("O menor valor digitado foi: %i \n", menor);
    }else{
        printf("\nProcesso Encerrado. Nenhum número valido foi inserido\n.");
    }
     
    return 0;
}