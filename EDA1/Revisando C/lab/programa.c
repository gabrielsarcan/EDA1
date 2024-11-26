#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include <string.h>

void reset(int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas);
void inserir(TMedidas **medidas, int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas);
void exibir(TMedidas **medidas, int *qtde_medidas, TTemperaturas *temperaturas);
void estatistica(TMedidas **medidas, int *qtde_medidas, TTemperaturas *temperaturas);

int main() {
    int opcao;
    int qtde_dias = 0;
    TTemperaturas temperaturas;

    int qtde_medidas = 0;
    
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
            reset(&temperaturas.qtde_dias, &temperaturas.qtde_medidas, &temperaturas);
                printf("%d", temperaturas.qtde_dias);
                printf("%d", temperaturas.qtde_medidas);
                break;
            case 2:
                inserir(&temperaturas.medidas, &temperaturas.qtde_dias, &temperaturas.qtde_medidas, &temperaturas);
                exibir(&temperaturas.medidas, &temperaturas.qtde_medidas, &temperaturas);
                break;
            case 3:
                estatistica(&temperaturas.medidas, &temperaturas.qtde_medidas, &temperaturas);;
                break;
            case 4:
                printf("Saindo do programa...\n");
                liberar_memoria(&temperaturas);
                break;               
                
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void reset(int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas) {
    if (temperaturas->medidas != NULL) {
        for (int i = 0; i < *qtde_medidas; i++) {
            free(temperaturas->medidas[i].temperatura);
        }
        free(temperaturas->medidas);
    }
    printf("\nColoque quantos dias:");
    scanf("%d", & temperaturas->qtde_dias);

    (*temperaturas).medidas = malloc((*temperaturas).qtde_dias* sizeof(TMedidas));
    (*temperaturas).qtde_medidas = 0;
    
    if (temperaturas->medidas == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
    }   
}

void inserir(TMedidas **medidas, int *qtde_dias, int *qtde_medidas, TTemperaturas *temperaturas) {

    if (*qtde_medidas == *qtde_dias){
        (*qtde_dias)++;
        *medidas = realloc(*medidas, (*qtde_dias) * sizeof(TMedidas));

    }
    printf("\nColoque nome da cidade e temperatura:");
    scanf(" %19[^\n]",(*medidas)[*qtde_medidas].cidade);   

    (*medidas)[*qtde_medidas].temperatura = malloc(*qtde_dias * sizeof(float));
    if ((*medidas)[*qtde_medidas].temperatura == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1); // Sai do programa em caso de erro crítico
    }
    
        for (int j = 0; j < *qtde_dias; j++) {
            printf("Temperatura do dia %d: ", j + 1);
            scanf("%f", &(*medidas)[*qtde_medidas].temperatura[j]);
        }  

    
    (*qtde_medidas)++;
}

void estatistica(TMedidas **medidas, int *qtde_medidas, TTemperaturas *temperaturas) {
    float soma = 0;
    float menorT = (*medidas)[0].temperatura[0];
    float maiorT = (*medidas)[0].temperatura[0];
    char *menorC = (*medidas)[0].cidade;  // Use ponteiros para evitar cópias
    char *maiorC = (*medidas)[0].cidade;

    printf("\nOpção Estatística escolhida. Calculando estatísticas...\n");
    printf("\nCidades e suas temperaturas:\n");

    for (int i = 0; i < *qtde_medidas; i++) {
        for (int j = 0; j < temperaturas->qtde_dias; j++) {
            float temp_atual = (*medidas)[i].temperatura[j];
            soma += temp_atual;

            if (temp_atual < menorT) {
                menorT = temp_atual;
                menorC = (*medidas)[i].cidade;  // Atualiza o ponteiro
            }
            if (temp_atual > maiorT) {
                maiorT = temp_atual;
                maiorC = (*medidas)[i].cidade;  // Atualiza o ponteiro
            }
        }
    }

    float media = soma / ((*qtde_medidas) * temperaturas->qtde_dias);
    printf("Média das temperaturas: %.2f\n", media);
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
        // Libera cada vetor de temperaturas alocado para as cidades
        for (int i = 0; i < temperaturas->qtde_medidas; i++) {
            free(temperaturas->medidas[i].temperatura);
        }
        // Libera o vetor principal de medidas
        free(temperaturas->medidas);
    }
    temperaturas->medidas = NULL; // Evita uso de ponteiro inválido
    temperaturas->qtde_medidas = 0;
    temperaturas->qtde_dias = 0;
}