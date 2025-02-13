#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    int ibge;
    char uf[3];                // Sigla da UF (2 caracteres + '\0')
    char municipio[MAX_STRING_LENGTH]; // Nome do município
    char regiao[MAX_STRING_LENGTH]; // Região (como 'Região Norte')
    int populacao2010;         // População de 2010
    char porte[MAX_STRING_LENGTH]; // Porte (como 'Pequeno I', 'Médio', etc.)
} Municipio;

// Função de busca sequencial que retorna o índice do município encontrado ou -1
int buscaSequencial(Municipio *municipios, int chave, int tamanho) {
    for (int n = 0; n < tamanho; n++) {
        if (municipios[n].ibge == chave) {
            return n; // Retorna o índice se encontrar
        }
    }
    return -1; // Retorna -1 se não encontrar
}

void main() {
    int tamanho = 0;
    FILE *fp;
    fp = fopen("ibge.csv", "r");
    
    if (fp == NULL) {
        printf("Unable to open file\n");
        system("pause");
        exit(0);
    }

    Municipio *municipios = NULL;  // Ponteiro para array de structs (inicialmente NULL)
    int i = 0;  // Índice para a leitura

    // Lê uma linha do arquivo e preenche os campos
    while (fscanf(fp, "%d;%2s;%99[^;];%99[^;];%d;%99[^\n]\n",
                  &municipios[i].ibge,
                  municipios[i].uf, 
                  municipios[i].municipio, 
                  municipios[i].regiao,
                  &municipios[i].populacao2010,
                  municipios[i].porte) == 6) {

        // Realocação de memória para armazenar um novo município
        municipios = realloc(municipios, (i + 1) * sizeof(Municipio));

        if (municipios == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        i++;  // Incrementa o índice
        tamanho++;  // Incrementa o tamanho
    }

    fclose(fp);

    // Agora, vamos buscar o município pelo IBGE (exemplo: 110001)
    int chave = 110002;
    int posic = buscaSequencial(municipios, chave, tamanho);

    if (posic != -1) {
        printf("Município encontrado no índice %d: %s\n", posic, municipios[posic].municipio);
    } else {
        printf("Município com IBGE %d não encontrado.\n", chave);
    }

    // Libera a memória alocada
    free(municipios);
}
