#include <stdio.h>
#include <stdlib.h>
#include "VetoresC.h"

int main() {
    // Criar um vetor de inteiros com 3 elementos
    int* vetor = CriaVetInt(3);

    // Verificar se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao criar o vetor.\n");
        return 1; // Encerrar o programa em caso de erro
    }

    // Imprimir o endereço do vetor
    printf("Endereço do vetor: %p\n",vetor);

    // Liberar a memória alocada
    free(vetor);

    return 0;
}