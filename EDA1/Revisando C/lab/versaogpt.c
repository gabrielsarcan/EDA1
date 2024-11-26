#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include <string.h>

void reset(int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas);
void inserir(TMedidas **medidas, int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas);
void exibir(TMedidas **medidas, int *qtde_medidas, TTemperaturas *temperaturas);
void estatistica(TMedidas **medidas, int *qtde_medidas, TTemperaturas *temperaturas);
void liberar_memoria(TTemperaturas *temperaturas);

int main() {
    int opcao;
    TTemperaturas temperaturas = {0}; // Inicializa todos os campos com 0 ou NULL
    int qtde_dias = 0, qtde_medidas = 0;

    do {
        printf("\nMenu:\n");
        printf("1 - Reset\n");
        printf("2 - Inserir\n");
        printf("3 - Estatística\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                reset(&qtde_dias, &qtde_medidas, &temperaturas);
                break;
            case 2:
                inserir(&temperaturas.medidas, &qtde_dias, &qtde_medidas, &temperaturas);
                exibir(&temperaturas.medidas, &qtde_medidas, &temperaturas);
                break;
            case 3:
                estatistica(&temperaturas.medidas, &qtde_medidas, &temperaturas);
                break;
            case 4:
                printf("Saindo do programa...\n");
                liberar_memoria(&temperaturas);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void reset(int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas) {
    liberar_memoria(temperaturas);

    printf("\nColoque quantos dias: ");
    scanf("%d", qtde_dias);

    temperaturas->medidas = malloc((*qtde_dias) * sizeof(TMedidas));
    if (temperaturas->medidas == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }
    *qtde_medidas = 0;
}

void inserir(TMedidas **medidas, int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas) {
    if (*qtde_medidas >= *qtde_dias) {
        printf("Não é possível adicionar mais medidas. Limite alcançado.\n");
        return;
    }

    printf("\nColoque o nome da cidade: ");
    scanf(" %19[^\n]", (*medidas)[*qtde_medidas].cidade);

    (*medidas)[*qtde_medidas].temperatura = malloc(*qtde_dias * sizeof(float));
    if ((*medidas)[*qtde_medidas].temperatura == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }

    for (int j = 0; j < *qtde_dias; j++) {
        printf("Temperatura do dia %d: ", j + 1);
        scanf("%f", &(*medidas)[*qtde_medidas].temperatura[j]);
    }

    (*qtde_medidas)++;
}

void estatistica(TMedidas **medidas, int *qtde_medidas, TTemperaturas *temperaturas) {
    if (*qtde_medidas == 0) {
        printf("Nenhuma medida registrada.\n");
        return;
    }

    float soma = 0;
    float menorT = (*medidas)[0].temperatura[0];
    float maiorT = (*medidas)[0].temperatura[0];
    char *menorC = (*medidas)[0].cidade;
    char *maiorC = (*medidas)[0].cidade;

    for (int i = 0; i < *qtde_medidas; i++) {
        for (int j = 0; j < temperaturas->qtde_dias; j++) {
            float temp_atual = (*medidas)[i].temperatura[j];
            soma += temp_atual;

            if (temp_atual < menorT) {
                menorT = temp_atual;
                menorC = (*medidas)[i].cidade;
            }
            if (temp_atual > maiorT) {
                maiorT = temp_atual;
                maiorC = (*medidas)[i].cidade;
            }
        }
    }

    float media = soma / ((*qtde_medidas) * temperaturas->qtde_dias);
    printf("\nMédia das temperaturas: %.2f\n", media);
    printf("Menor temperatura: %.2f na cidade %s\n", menorT, menorC);
    printf("Maior temperatura: %.2f na cidade %s\n", maiorT, maiorC);
}

void exibir(TMedidas **medidas, int *qtde_medidas, TTemperaturas *temperaturas) {
    printf("\nCidades e suas temperaturas:\n");

    for (int i = 0; i < *qtde_medidas; i++) {
        printf("Cidade: %s\n", (*medidas)[i].cidade);
        for (int j = 0; j < temperaturas->qtde_dias; j++) {
            printf("  Dia %d: %.2f\n", j + 1, (*medidas)[i].temperatura[j]);
        }
    }
}

void liberar_memoria(TTemperaturas *temperaturas) {
    if (temperaturas->medidas != NULL) {
        for (int i = 0; i < temperaturas->qtde_medidas; i++) {
            free(temperaturas->medidas[i].temperatura);
        }
        free(temperaturas->medidas);
    }
    temperaturas->medidas = NULL;
    temperaturas->qtde_medidas = 0;
    temperaturas->qtde_dias = 0;
}
