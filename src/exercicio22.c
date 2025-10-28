/*
 ============================================================================
 Nome        : exercicio22.c
 Autor       : Yuri140
 Data        : 28/10/2025
 Descrição   : Desenvolver um programa que utilize uma estrutura (struct) para
               armazenar informações de funcionários (registro e salário).
               O programa deve ler os dados de 3 funcionários e exibir essas
               informações de forma organizada.
 ============================================================================
*/

#include <stdio.h>

struct Funcionario{
    int registro;
    float salario;
};

void exibirVetor(struct Funcionario vet[], int tamanho);
void atribuirValores(struct Funcionario vet[], int tamanho);

int main(){

    struct Funcionario vetFunc[3];

    atribuirValores(vetFunc, 3);
    exibirVetor(vetFunc, 3);

    return 0;
}

void exibirVetor(struct Funcionario vet[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("Funcionario %i - Registro: %i, Salario: %.2f \n", i + 1, vet[i].registro, vet[i].salario);
    }
}

void atribuirValores(struct Funcionario vet[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("Digite o registro do funcionario %i: ", i + 1);
        scanf("%i", &vet[i].registro);
        printf("Digite o salario do funcionario %i: ", i + 1);
        scanf("%f", &vet[i].salario);
    }
}