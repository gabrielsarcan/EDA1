#include <stdio.h>
#include <stdlib.h>

float* carregarNumeros(char *nomeArquivo, int *ptamanho, int *pcapacidade);
void inclui_ordenado(float **pvalores, float pv, int *pcapacidade, int *ptamanho);

int main() {
    char *nomeArquivo = "dados.txt";
    int ptamanho = 0;
    int pcapacidade = 0;

    // Chama a função para carregar os números
    float *pvalores = carregarNumeros(nomeArquivo, &ptamanho, &pcapacidade);
    if (pvalores == NULL) {
        fprintf(stderr, "Falha ao carregar os números do arquivo.\n");
        return 1;
    }


    inclui_ordenado(&pvalores, 3.5, &pcapacidade, &ptamanho);

    // Exibe os números lidos
    printf("Números reais lidos do arquivo:\n");
    for (int i = 0; i < ptamanho; i++) {
        printf("%.2f\n", pvalores[i]);
    }

    // Libera a memória
    free(pvalores);
    return 0;
}


void inclui_ordenado(float **pvalores, float pv, int *pcapacidade, int *ptamanho) {
    int i;
    float *temp = NULL;

    for (i = 0; i < *ptamanho; i++) {
        if ((*pvalores)[i] > pv) {
            (*pcapacidade)++;
            float *temp = realloc(*pvalores, *pcapacidade * sizeof(float));
            *pvalores = temp; 
            break; 
        }
    }

    // Desloca os elementos para a direita
    for (int j = *ptamanho; j > i; j--) {
        (*pvalores)[j] = (*pvalores)[j - 1];
    }

    // Insere o valor na posição correta
    (*pvalores)[i] = pv;
    (*ptamanho)++;
}


float* carregarNumeros( char *nomeArquivo, int *ptamanho, int *pcapacidade){
   FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Errro ao abrir o arquivo");
    }

    float numero;
    float *pvalores = NULL;
    *ptamanho = 0;

    while (fscanf(arquivo, "%f", &numero) == 1) {
        float *temp = realloc(pvalores, (*ptamanho + 1) * sizeof(float));
        if (temp == NULL) {
            perror("Erro ao realocar memória");
            free(pvalores);
            fclose(arquivo);
            return NULL;
        }
        pvalores = temp;

        // Adicionando o número ao vetor
        pvalores[*ptamanho] = numero;
        (*ptamanho)++;
        (*pcapacidade) ++;
    }

    // Fechando o arquivo
    fclose(arquivo);
    return pvalores;
}