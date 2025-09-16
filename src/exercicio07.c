/*
 ============================================================================
 Nome        : exercicio07.c
 Autor       : Yuri140
 Data        : 16/09/2025
 Descrição   : Desenvolver um programa que simule operações bancárias simples
               com um menu de opções para o usuário: depositar dinheiro, 
               realizar saques, consultar saldo e sair do programa. O sistema
               deve verificar se há saldo suficiente para saques e apresentar
               mensagens apropriadas para cada operação realizada.
 ============================================================================
*/

#include <stdio.h>
#include <windows.h>

int main(){
	
	int menu, executando = 1;
	float saldo = 0, saque, deposito;
	
	while(executando == 1){
		printf("\nMenu Bancário \n 1 - Depositar \n 2 - Sacar \n 3 - Exibir Saldo \n 4 - Sair \nInsira uma das opções acima.\n");
		scanf("%i", &menu);
		
		switch(menu){
		case 1:
			system("cls");
			printf("====== DEPOSITO ====== \n");
			printf("Insira o valor que deseja Depositar \n");
			scanf("%f", &deposito);
			saldo = saldo + deposito;
			printf("Valor de R$%.2f depositado na conta. \n", deposito);
			break;
		case 2:
			system("cls");
			printf("====== SAQUE ====== \n");
			printf("Insira o valor que deseja Sacar \n");
			scanf("%f", &saque);
			if(saldo >= saque){
				saldo = saldo - saque;
				printf("Valor de R$%.2f foi sacado com sucesso. \n", saque);
			}else{
				printf("Saldo insuficiente, consulte a opção de saldo para mais detalhes. \n");
			}
			break;
		case 3:
			system("cls");
			printf("====== SALDO ====== \n");
			printf("Seu saldo atual é de: R$%.2f \n", saldo);
			break;
		case 4:
			executando = 0;
			break;
		default: 
			system("cls");
			printf(" \n\nOpção incorreta. Insira novamente! \n\n");
		}
	
	
	}

    printf("Programa Encerrado. \n");
	
	return 0;
	
}