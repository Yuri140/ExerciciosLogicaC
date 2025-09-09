/*
 ============================================================================
 Nome        : exercicio02.c
 Autor       : Yuri140
 Data        : 09/09/2025
 Descrição   : Desenvolver um programa que leia 15 números e exiba a média 
               dos números pares e a média dos números ímpares.
 ============================================================================
*/
 
#include <stdio.h>
 
int main()
{ 
    int num, countPar = 0, countImpar = 0;
    float par = 0, impar = 0;
     
    printf("Insira 15 numeros, e sera mostrado a media dos pares e a media dos impares digitados! \n\n");
     
    for(int i = 1; i <= 15; i++){
        printf("Insira o %i° valor: ", i);
        scanf("%i", &num);
         
        if(num % 2 == 0){ 
            par = par + num;
            countPar++;
        }else{ 
            impar = impar + num;
            countImpar++;
        }
         
    }
     
    if(countPar > 0){ 
        printf("A media dos valores pares e: %.2f\n", par / countPar);
    } else { 
        printf("Nao houve numeros pares.\n");
    }
     
    if(countImpar > 0){ 
        printf("A media dos valores impares e: %.2f\n", impar / countImpar);
    } else { 
        printf("Nao houve numeros impares.\n");
    }
     
    return 0; 
}