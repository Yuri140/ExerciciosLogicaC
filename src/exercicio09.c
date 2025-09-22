/*
 ============================================================================
 Nome        : exercicio09.c
 Autor       : Yuri140
 Data        : 22/09/2025
 Descrição   : Desenvolver um jogo onde o jogador controla uma nave fixa e deve
               acertar um monstro em posição aleatória, informando a distância
               entre o cano da nave e o pé esquerdo do monstro. O jogador tem
               3 vidas e o jogo inclui animações de tiro e morte do monstro.
 ============================================================================
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void gotoxy(short x, short y);
void DesenharMonstro(int posicaoX, int posicaoY);
void DesenharMonstroMorto(int posicaoX, int posicaoY);
void DesenharNave(int posX, int posY);
void AtualizarVidas();
void Introducao();
void Fim();
void LimparAreaDetalhes();
int Atirar(int distancia, int posicaoMonstroX, int posicaoCanoX, int tiroY);

int vidas = 3;

int posicaoNaveX = 10;
int posicaoNaveY = 12;

int main() {
    int distancia, posicaoMonstroX, posicaoMonstroY = posicaoNaveY;
    int resp;

    SetConsoleOutputCP(CP_UTF8);

    Introducao();

    srand((unsigned) time(NULL));
    posicaoMonstroX = (rand() % (80 - 60 + 1)) + 60;

    system("cls");
    AtualizarVidas();

    DesenharNave(posicaoNaveX, posicaoNaveY);
    DesenharMonstro(posicaoMonstroX, posicaoMonstroY);

    
    while (vidas > 0) {

        LimparAreaDetalhes();

        gotoxy(0, 17);
        printf("Insira a distância para atirar no monstro: ");
        scanf("%d", &distancia);

        while (distancia < 0) {
            gotoxy(0, 17);
            LimparAreaDetalhes();
            printf("Distância inválida. Tente novamente.\n");
            printf("Insira a distância para atirar no monstro: ");
            scanf("%d", &distancia);
        }

        int posicaoCanoX = posicaoNaveX + 1;
        int distanciaReal = posicaoMonstroX - posicaoCanoX;

        resp = Atirar(distancia, posicaoMonstroX, posicaoCanoX, posicaoMonstroY);

        if (resp == 1) {
            Fim();
            return 0;
        } else {
            vidas--;
            AtualizarVidas();
            gotoxy(0, 20);
            printf("Errou o monstro!");

            if (distancia < distanciaReal) {
                gotoxy(0, 21);
                printf("Dica: o monstro está MAIS LONGE.");
            } else if (distancia > distanciaReal) {
                gotoxy(0, 21);
                printf("Dica: o monstro está MAIS PERTO.");
            } else {
                gotoxy(0, 21);
                printf("Você atirou na posição certa, mas algo impediu o acerto.");
            }

            if (vidas > 0) {
                gotoxy(0, 22);
                printf("Tente novamente.");
            } else {
                gotoxy(0, 22);
                printf("Sem vidas restantes.");
            }
        }

        gotoxy(0, 24);
        system("pause");
    }

    if (vidas <= 0) {
        LimparAreaDetalhes();
        gotoxy(0, 18);
        printf("Você perdeu todas as vidas! Fim de jogo!");
        gotoxy(0, 20);
        printf("O monstro estava na distância: %d.", posicaoMonstroX - (posicaoNaveX + 1));
    }

    gotoxy(0, 27);
    system("pause");
    LimparAreaDetalhes();
    return 0;
}


void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void DesenharMonstro(int posicaoX, int posicaoY) {
    gotoxy(posicaoX, posicaoY);          printf("█   █");
    gotoxy(posicaoX, posicaoY - 1);      printf("█ █ █");
    gotoxy(posicaoX + 2, posicaoY - 2);  printf("█");
    gotoxy(posicaoX + 2, posicaoY - 3);  printf("█");
    gotoxy(posicaoX - 1, posicaoY - 4);  printf("█  █ █ █ ");
    gotoxy(posicaoX + 2, posicaoY - 5);  printf("█   █");
}


void DesenharMonstroMorto(int posicaoX, int posicaoY) {
    gotoxy(posicaoX, posicaoY);          printf("X   X");
    gotoxy(posicaoX, posicaoY - 1);      printf("X X X");
    gotoxy(posicaoX + 2, posicaoY - 2);  printf("X");
    gotoxy(posicaoX + 2, posicaoY - 3);  printf("X");
    gotoxy(posicaoX - 1, posicaoY - 4);  printf("X  X X X ");
    gotoxy(posicaoX + 2, posicaoY - 5);  printf("X   X");
}


void DesenharNave(int posX, int posY) {
    gotoxy(posX, posY - 1); printf("█");
    gotoxy(posX, posY);     printf("█");
    gotoxy(posX + 1, posY); printf("█");
    gotoxy(posX, posY + 1); printf("█");
}


int Atirar(int distancia, int posicaoMonstroX, int posicaoCanoX, int tiroY) {
    gotoxy(0, 19);
    printf("Disparando a uma distância de %d unidades...", distancia);

    int posicaoInicialX = posicaoCanoX + 1;
    int posicaoAlvoX = posicaoCanoX + distancia;
    int posicaoAnteriorX = -1;

    // Para evitar ultrapassar os limites do console, pode ser ajustado de acordo com o tamanho do console.
    if (posicaoAlvoX > 100){
        posicaoAlvoX = 100;
    }

    int monstroPosicaoInicial = posicaoMonstroX;
    int monstroPosicaoFinal = posicaoMonstroX + 5;

    for (int x = posicaoInicialX; x <= posicaoAlvoX; x++) {
        gotoxy(x, tiroY);
        printf("→");
        Sleep(12);

        if (posicaoAnteriorX >= 0) {
            gotoxy(posicaoAnteriorX, tiroY);
            printf(" ");
        }
        posicaoAnteriorX = x;
    }

    if (posicaoAnteriorX >= 0) {
        gotoxy(posicaoAnteriorX, tiroY);
        printf(" ");
    }
    
    if (posicaoAlvoX >= monstroPosicaoInicial) {
        DesenharMonstro(posicaoMonstroX, tiroY);
    }

    if (posicaoAlvoX == posicaoMonstroX) {
        for (int frame = 0; frame < 6; frame++) {
            gotoxy(posicaoMonstroX, tiroY);
            switch(frame) {
                case 0: printf("*"); break;
                case 1: printf("⚡"); break;
                case 2: printf("✴"); break;
                case 3: printf("💥"); break;
                case 4: printf("⚡"); break;
                case 5: printf("*"); break;
            }
            Sleep(80);
        }
        
        DesenharMonstroMorto(posicaoMonstroX, tiroY);
        gotoxy(0, 20);
        printf("BOOM! Acertou o ponto fraco do monstro!");
        gotoxy(0, 21);
        printf("Distância exata: %d unidades.\n", distancia);
        system("pause");
        return 1;
    } else {
        return 0;
    }
}


void AtualizarVidas() {
    for (int y = 0; y <= 3; y++) {
        gotoxy(0, y);
        printf("                                                                    ");
    }
    
    gotoxy(0, 0);
    printf("Vidas: ");
    
    for (int i = 0; i < vidas; i++) {
        printf("♥ ");
    }
}


void LimparAreaDetalhes() {
    for (int y = 17; y <= 27; y++) {
        gotoxy(0, y);
        printf("                                                                                ");
    }
    gotoxy(0, 17);
}


void Introducao() {
    system("cls");
    printf("=================================================\n");
    printf("            CAÇA AO MONSTRO ESPACIAL             \n");
    printf("=================================================\n");
    printf("\nVocê controla uma nave fixa e deve acertar o monstro.\n");
    printf("O ponto fraco do monstro é o seu pé ESQUERDO. Você deve\n");
    printf("informar a distância entre o cano da nave e o pé esquerdo\n");
    printf("do monstro (valor em colunas). Você tem 3 vidas. Boa sorte!\n\n");
    system("pause");
}

void Fim() {
    system("cls");
    printf("=============================================\n");
    printf("               PARABÉNS!!! 🎉               \n");
    printf("=============================================\n");
    printf("\nVocê conseguiu derrotar o monstro espacial!\n");
    printf("A galáxia está em paz graças a você.\n\n");
    printf("Fim de jogo.\n");
    printf("=============================================\n");
    system("pause");
}