/*
 ============================================================================
 Nome        : exercicio13.c
 Autor       : Yuri140
 Data        : 21/10/2025
 Descrição   : Jogo de batalha naval simplificado em tabuleiro, onde o
               jogador posiciona três tipos de embarcações (submarino, porta-
               aviões e navio) e depois deve destruí-las através de disparos
               coordenados. O jogo conta os mísseis utilizados e exibe a
               quantidade final de mísseis utilizados.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_LINHA 5
#define TAMANHO_COLUNA 5

const int tamanhoLinha = 5, tamanhoColuna = 5;

int posicionar(int tipo, int linha, int coluna);
void exibirTabuleiro();
void inicializarTabuleiro();
int atirar(int linha, int coluna);
void posicionarPecasManualmente();
void posicionarPecasAutomaticamente();
int tabuleiro[TAMANHO_LINHA][TAMANHO_COLUNA];

int main(){
    int linha, coluna;
    int submarino = 2, porta = 3, navio = 4;
    int misseis = 0;
    int opcao;

    srand(time(NULL));

    inicializarTabuleiro();

    printf("=== BEM-VINDO AO JOGO DE BATALHA NAVAL ===\n\n");
    printf("Escolha o modo de posicionamento das embarcacoes:\n");
    printf("1 - Posicionar manualmente\n");
    printf("2 - Posicionar automaticamente\n");
    printf("Opcao: ");
    scanf("%i", &opcao);

    if (opcao == 1) {
        posicionarPecasManualmente();
    } else if (opcao == 2) {
        posicionarPecasAutomaticamente();
    } else {
        printf("Opcao invalida! Usando posicionamento manual.\n");
        posicionarPecasManualmente();
    }

    while(submarino != 5 || porta != 5 || navio != 5){

        printf("\n\nIniciando disparos\n\n");
        printf("Insira a linha: ");
        scanf("%i", &linha);
        printf("Insira a coluna: ");
        scanf("%i", &coluna);
        misseis++;

        switch(atirar(linha, coluna)){
            case 1:
                printf("\nVoce acertou o submarino!\n");
                submarino--;
                break;
            case 2:
                printf("\nVoce acertou o porta avioes!\n");
                porta--;
                break;
            case 3:
                printf("\nVoce acertou o navio!\n");
                navio--;
                break;
            case 4:
                printf("\nVoce acertou a agua...\n");
                break;
            case 9:
                printf("\nVoce já tinha acertado essa parte da embarcacao\n");
                break;
            default:
                printf("\nErro\n");
                misseis--;
                break;
        }

        if(submarino == 0){
            printf("Voce destruiu o submarino\n");
            submarino = 5;
        }
        if(porta == 0){
            printf("Voce destruiu o porta avioes\n");
            porta = 5;
        }
        if(navio == 0){
            printf("Voce destruiu o navio\n");
            navio = 5;
        }

	}
    exibirTabuleiro();
    printf("\n\n\nParabens voce destruiu todas as embarcacoes inimigas, para isso voce utilizou %i misseis\n\n\n", misseis);

	return 0;
}

int posicionar(int tipo, int linha, int coluna){
	if(coluna > tamanhoColuna - 1 || linha > tamanhoLinha - 1){
		return 0;
	}
	switch(tipo){
		case 1:
			if(linha > tamanhoLinha -1 || coluna >= tamanhoColuna - 1)
				return 0;
			if(tabuleiro[linha][coluna] == 0 && tabuleiro[linha][coluna + 1] == 0){
				tabuleiro[linha][coluna] = 1;
				tabuleiro[linha][coluna + 1] = 1;
				return 1;
			}else
				return 0;
			break;
		case 2:
			if(linha > tamanhoLinha - 1 || coluna >= tamanhoColuna - 2)
				return 0;
			if(tabuleiro[linha][coluna] == 0 && tabuleiro[linha][coluna + 1] == 0 && tabuleiro[linha][coluna + 2] == 0){
				tabuleiro[linha][coluna] = 2;
				tabuleiro[linha][coluna + 1] = 2;
				tabuleiro[linha][coluna + 2] = 2;
				return 1;
			}else
				return 0;
			break;
		case 3:
			if(linha > tamanhoLinha - 1 || linha == 1 || coluna >= tamanhoColuna - 2)
				return 0;
			if(tabuleiro[linha][coluna] == 0 && tabuleiro[linha][coluna + 1] == 0 && tabuleiro[linha-1][coluna+1] == 0 && tabuleiro[linha][coluna+2] == 0){
				tabuleiro[linha][coluna] = 3;
				tabuleiro[linha][coluna + 1] = 3;
				tabuleiro[linha - 1][coluna + 1] = 3;
				tabuleiro[linha][coluna + 2] = 3;
				return 1;
			}else
				return 0;
			break;
		default:
			return 0;
	}
}

void exibirTabuleiro(){
	printf("\n==== TABULEIRO === \n");
	for(int linha=0; linha<=tamanhoLinha-1; linha++){
		for(int coluna=0; coluna<=tamanhoColuna-1; coluna++){
			printf("%i ", tabuleiro[linha][coluna]);
		}
		printf("\n");
	}
}

void inicializarTabuleiro(){
	for(int linha=0; linha<=tamanhoLinha-1; linha++){
		for(int coluna=0; coluna<=tamanhoColuna-1; coluna++){
			tabuleiro[linha][coluna] = 0;
		}
	}
}

int atirar(int linha, int coluna){
	if(linha > tamanhoLinha - 1 || coluna > tamanhoColuna - 1){
        return 0;
    }
    if(tabuleiro[linha][coluna] == 1){
        tabuleiro[linha][coluna] = 9;
        return 1;
    }else if(tabuleiro[linha][coluna] == 2){
        tabuleiro[linha][coluna] = 9;
        return 2;
    }else if(tabuleiro[linha][coluna] == 3){
        tabuleiro[linha][coluna] = 9;
        return 3;
    }else if(tabuleiro[linha][coluna] == 9){
        return 9;
    }else{
        return 4;
    }
}

void posicionarPecasManualmente(){

    int submarino_posicionado = 0, porta_avioes_posicionado = 0, navio_posicionado = 0;
    int linha, coluna;

    printf("Posicione suas embarcações para começar o jogo.\n");

    while (!submarino_posicionado) {
        printf("\nPosicione o Submarino (tipo 1)\n");
        printf("Em qual linha quer posicionar: ");
        scanf("%i", &linha);
        printf("Em qual coluna quer posicionar: ");
        scanf("%i", &coluna);
        if (posicionar(1, linha, coluna) == 1) {
            printf("Submarino posicionado com sucesso!\n");
            submarino_posicionado = 1;
        } else {
            printf("\nErro no posicionamento. Tente novamente.\n");
        }
    }

    while (!porta_avioes_posicionado) {
        printf("\nPosicione o Porta-Aviões (tipo 2)\n");
        printf("Em qual linha quer posicionar: ");
        scanf("%i", &linha);
        printf("Em qual coluna quer posicionar: ");
        scanf("%i", &coluna);
        if (posicionar(2, linha, coluna) == 1) {
            printf("Porta-Aviões posicionado com sucesso!\n");
            porta_avioes_posicionado = 1;
        } else {
            printf("\nErro no posicionamento. Tente novamente.\n");
        }
    }

    while (!navio_posicionado) {
        printf("\nPosicione o Navio (tipo 3)\n");
        printf("Em qual linha quer posicionar: ");
        scanf("%i", &linha);
        printf("Em qual coluna quer posicionar: ");
        scanf("%i", &coluna);
        if (posicionar(3, linha, coluna) == 1) {
            printf("Navio posicionado com sucesso!\n");
            navio_posicionado = 1;
        } else {
            printf("\nErro no posicionamento. Tente novamente.\n");
        }
    }

    printf("\nTodas as embarcações foram posicionadas. Boa sorte!\n");
}

void posicionarPecasAutomaticamente(){
    int linha, coluna;
    
    printf("Posicionando embarcações automaticamente...\n");
    
    do {
        linha = rand() % tamanhoLinha;
        coluna = rand() % tamanhoColuna;
    } while (posicionar(1, linha, coluna) != 1);
    printf("Submarino posicionado!\n");
    
    do {
        linha = rand() % tamanhoLinha;
        coluna = rand() % tamanhoColuna;
    } while (posicionar(2, linha, coluna) != 1);
    printf("Porta-Aviões posicionado!\n");
    
    do {
        linha = rand() % tamanhoLinha;
        coluna = rand() % tamanhoColuna;
    } while (posicionar(3, linha, coluna) != 1);
    printf("Navio posicionado!\n");
    
    printf("\nTodas as embarcações foram posicionadas automaticamente. Boa sorte!\n");
}