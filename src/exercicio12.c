/*
 ============================================================================
 Nome        : exercicio12.c
 Autor       : Yuri140
 Data        : 14/10/2025
 Descrição   : Desenvolver funções genéricas para manipulação de matrizes 
               bidimensionais de tamanhos variáveis, incluindo inserir valores,
               exibir matriz, somar elementos, gerar matrizes com padrões 
               específicos (diagonal, linhas específicas, extremidades, 
               multiplicação linha×coluna) e realizar operações entre matrizes.
 ============================================================================
*/

#include <stdio.h>

// Protótipos das funções
void inserirValoresNaMatriz(int linhas, int colunas, int matriz[linhas][colunas]);
void mostrarMatriz(int linhas, int colunas, int matriz[linhas][colunas]);
int somarValoresMatriz(int linhas, int colunas, int matriz[linhas][colunas]);
void gerarMatrizDiagonal(int linhas, int colunas, int matriz[linhas][colunas]);
void gerarMatrizLinhasEspecificas(int linhas, int colunas, int matriz[linhas][colunas], int linha1, int linha2);
void gerarMatrizExtremidades(int linhas, int colunas, int matriz[linhas][colunas]);
void gerarMatrizLinhaVezesColuna(int linhas, int colunas, int matriz[linhas][colunas]);
void somarDuasMatrizes(int linhas, int colunas, int matriz1[linhas][colunas], int matriz2[linhas][colunas], int matriz3[linhas][colunas]);
void exibirMenu();

int main() {
    int opcao;
    int linhas, colunas;
    int linha1, linha2;
    int soma;

    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 0) {
            printf("Encerrando programa...\n");
            break;
        }

        // Solicitar dimensões da matriz para a maioria das opções
        if (opcao >= 1 && opcao <= 7) {
            printf("Digite o número de linhas (max 10): ");
            scanf("%d", &linhas);
            printf("Digite o número de colunas (max 10): ");
            scanf("%d", &colunas);

            if (linhas <= 0 || linhas > 10 || colunas <= 0 || colunas > 10) {
                printf("Dimensões inválidas! Tente novamente.\n");
                printf("\n");
                continue;
            }

            // Declaração da matriz com tamanho variável
            int matriz[linhas][colunas];
            int matriz1[linhas][colunas];
            int matriz2[linhas][colunas];
            int matriz3[linhas][colunas];

            // Inicializar matrizes
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    matriz[i][j] = 0;
                    matriz1[i][j] = 0;
                    matriz2[i][j] = 0;
                    matriz3[i][j] = 0;
                }
            }

            switch (opcao) {
                case 1:
                    printf("=== Inserir valores na matriz %dx%d ===\n", linhas, colunas);
                    inserirValoresNaMatriz(linhas, colunas, matriz);
                    mostrarMatriz(linhas, colunas, matriz);
                    break;

                case 2:
                    printf("=== Somar valores da matriz %dx%d ===\n", linhas, colunas);
                    inserirValoresNaMatriz(linhas, colunas, matriz);
                    mostrarMatriz(linhas, colunas, matriz);
                    soma = somarValoresMatriz(linhas, colunas, matriz);
                    printf("\nSoma de todos os valores: %d\n", soma);
                    break;

                case 3:
                    printf("=== Gerar matriz diagonal %dx%d ===\n", linhas, colunas);
                    gerarMatrizDiagonal(linhas, colunas, matriz);
                    mostrarMatriz(linhas, colunas, matriz);
                    break;

                case 4:
                    printf("=== Gerar matriz com linhas específicas preenchidas ===\n");
                    printf("Digite o número da primeira linha a preencher (0-%d): ", linhas - 1);
                    scanf("%d", &linha1);
                    printf("Digite o número da segunda linha a preencher (0-%d): ", linhas - 1);
                    scanf("%d", &linha2);
                    
                    if (linha1 < 0 || linha1 >= linhas || linha2 < 0 || linha2 >= linhas) {
                        printf("Linhas inválidas!\n");
                    } else {
                        gerarMatrizLinhasEspecificas(linhas, colunas, matriz, linha1, linha2);
                        mostrarMatriz(linhas, colunas, matriz);
                    }
                    break;

                case 5:
                    printf("=== Gerar matriz de extremidades %dx%d ===\n", linhas, colunas);
                    gerarMatrizExtremidades(linhas, colunas, matriz);
                    mostrarMatriz(linhas, colunas, matriz);
                    break;

                case 6:
                    printf("=== Gerar matriz %dx%d (linha × coluna) ===\n", linhas, colunas);
                    gerarMatrizLinhaVezesColuna(linhas, colunas, matriz);
                    mostrarMatriz(linhas, colunas, matriz);
                    break;

                case 7:
                    printf("=== Somar duas matrizes %dx%d ===\n", linhas, colunas);
                    printf("\nMatriz 1 (diagonal):\n");
                    gerarMatrizDiagonal(linhas, colunas, matriz1);
                    mostrarMatriz(linhas, colunas, matriz1);
                    
                    printf("\nMatriz 2 (extremidades):\n");
                    gerarMatrizExtremidades(linhas, colunas, matriz2);
                    mostrarMatriz(linhas, colunas, matriz2);
                    
                    somarDuasMatrizes(linhas, colunas, matriz1, matriz2, matriz3);
                    printf("\nMatriz resultante (Matriz 1 + Matriz 2):\n");
                    mostrarMatriz(linhas, colunas, matriz3);
                    break;

                default:
                    printf("Opção inválida! Tente novamente.\n");
            }
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }

        printf("\n");

    } while (opcao != 0);

    return 0;
}

void exibirMenu() {
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║     MENU - MANIPULAÇÃO DE MATRIZES                 ║\n");
    printf("╠════════════════════════════════════════════════════╣\n");
    printf("║ 1. Inserir valores manualmente                     ║\n");
    printf("║ 2. Inserir valores e calcular soma                 ║\n");
    printf("║ 3. Gerar matriz diagonal                           ║\n");
    printf("║ 4. Gerar matriz com linhas específicas             ║\n");
    printf("║ 5. Gerar matriz de extremidades                    ║\n");
    printf("║ 6. Gerar matriz (linha × coluna)                   ║\n");
    printf("║ 7. Somar duas matrizes                             ║\n");
    printf("║ 0. Sair                                            ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
}

void inserirValoresNaMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int linha = 0; linha < linhas; linha++) {
        for (int coluna = 0; coluna < colunas; coluna++) {
            printf("Insira o valor para [%d][%d]: ", linha, coluna);
            scanf("%d", &matriz[linha][coluna]);
        }
    }
}

void mostrarMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("\nMatriz %dx%d:\n", linhas, colunas);
    
    // Cabeçalho das colunas
    printf("       ");
    for (int coluna = 0; coluna < colunas; coluna++) {
        printf("Col %d  ", coluna);
    }
    printf("\n");
    
    // Exibir matriz
    for (int linha = 0; linha < linhas; linha++) {
        printf("Lin %d: ", linha);
        for (int coluna = 0; coluna < colunas; coluna++) {
            printf("%4d   ", matriz[linha][coluna]);
        }
        printf("\n");
    }
}

int somarValoresMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int soma = 0;
    for (int linha = 0; linha < linhas; linha++) {
        for (int coluna = 0; coluna < colunas; coluna++) {
            soma += matriz[linha][coluna];
        }
    }
    return soma;
}

void gerarMatrizDiagonal(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int linha = 0; linha < linhas; linha++) {
        for (int coluna = 0; coluna < colunas; coluna++) {
            if (linha == coluna)
                matriz[linha][coluna] = 1;
            else
                matriz[linha][coluna] = 0;
        }
    }
}

void gerarMatrizLinhasEspecificas(int linhas, int colunas, int matriz[linhas][colunas], int linha1, int linha2) {
    for (int linha = 0; linha < linhas; linha++) {
        for (int coluna = 0; coluna < colunas; coluna++) {
            if (linha == linha1 || linha == linha2)
                matriz[linha][coluna] = 1;
            else
                matriz[linha][coluna] = 0;
        }
    }
}

void gerarMatrizExtremidades(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int linha = 0; linha < linhas; linha++) {
        for (int coluna = 0; coluna < colunas; coluna++) {
            // Primeira ou última linha, primeira ou última coluna
            if (linha == 0 || linha == linhas - 1 || coluna == 0 || coluna == colunas - 1)
                matriz[linha][coluna] = 1;
            else
                matriz[linha][coluna] = 0;
        }
    }
}

void gerarMatrizLinhaVezesColuna(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int linha = 0; linha < linhas; linha++) {
        for (int coluna = 0; coluna < colunas; coluna++) {
            matriz[linha][coluna] = linha * coluna;
        }
    }
}

void somarDuasMatrizes(int linhas, int colunas, int matriz1[linhas][colunas], int matriz2[linhas][colunas], int matriz3[linhas][colunas]) {
    for (int linha = 0; linha < linhas; linha++) {
        for (int coluna = 0; coluna < colunas; coluna++) {
            matriz3[linha][coluna] = matriz1[linha][coluna] + matriz2[linha][coluna];
        }
    }
}