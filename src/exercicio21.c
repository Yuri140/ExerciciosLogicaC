/*
 ============================================================================
 Nome        : exercicio21.c
 Autor       : Yuri140
 Data        : 24/10/2025
 Descrição   : Desenvolver um programa que leia uma quantidade digitada pelo
               usuário e exiba os primeiros N números perfeitos. Um número
               perfeito é aquele cuja soma de seus divisores próprios (exceto
               ele mesmo) é igual ao próprio número.
 ============================================================================
*/

#include <stdio.h>

void exibirNumerosPerfeitos(int quantidade);

int main(){
    int quantidade;
    printf("Digite quantos números perfeitos quer achar: ");
    scanf("%d", &quantidade);

    if(quantidade <= 0){
        printf("Quantidade inválida. Insira um número positivo.\n");
    }else if(quantidade > 4){
        printf("Quantidade muito grande. Insira um número menor ou igual a 4.\n");
    }else{
        exibirNumerosPerfeitos(quantidade);
    }

    return 0;
}

void exibirNumerosPerfeitos(int quantidade){

    int somaDivisores = 0;
    int numeroPerfeito = 0;

    for (int i = 1; numeroPerfeito < quantidade; i++)
    {

        somaDivisores = 0;
        
        for (int j = 1; j <= i/2; j++)
        {

            if(i % j == 0){
                somaDivisores += j;
            }
        }

        if (somaDivisores == i)
            {
                printf("Número perfeito encontrado: %i \n", i);
                numeroPerfeito++;
            }
    }
}