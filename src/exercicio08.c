/*
 ============================================================================
 Nome        : exercicio08.c
 Autor       : Yuri140
 Data        : 16/09/2025
 Descrição   : Desenvolver um programa que lê dois números inteiros digitados 
               pelo usuário e utiliza uma função para calcular a soma 
               desses números.
 ============================================================================
*/

#include <stdio.h>

int SomarDoisNumeros(int numero1, int numero2);

int main() {

 int numero1, numero2;

   printf("Digite o primeiro número: ");
   scanf("%i", &numero1);
   printf("Digite o segundo número: ");
   scanf("%i", &numero2);
   printf("Soma = %i", SomarDoisNumeros(numero1,numero2));

   return 0;
}

int SomarDoisNumeros(int numero1, int numero2){
    return (numero1 + numero2);
}