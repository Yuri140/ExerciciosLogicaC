/*
 ============================================================================
 Nome        : exercicio11.c
 Autor       : Yuri140
 Data        : 27/09/2025
 Descrição   : Programa para calcular o Índice de Massa Corporal (IMC) de uma
               pessoa a partir da altura e peso informados, classificando o 
               resultado em diferentes categorias como abaixo do peso, peso
               normal, sobrepeso e níveis de obesidade.
 ============================================================================
*/

#include <stdio.h>

void verificarIMC(float imc);

int main() {

    float altura, peso, imc;

    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    printf("Digite o seu peso (em kg): ");
    scanf("%f", &peso);

    imc = peso / (altura * altura);

    verificarIMC(imc);

    return 0;
}

void verificarIMC(float imc){
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc >= 18.5 && imc < 24.9) {
        printf("Peso normal\n");
    } else if (imc >= 25 && imc < 29.9) {
        printf("Sobrepeso\n");
    } else if (imc >= 30 && imc < 34.9) {
        printf("Obesidade Grau I\n");
    } else if (imc >= 35 && imc < 39.9) {
        printf("Obesidade Grau II\n");
    } else {
        printf("Obesidade Grau III\n");
    }
}
