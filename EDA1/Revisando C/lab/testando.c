#include <stdio.h>
#include <stdlib.h>

char *Q3(int *M, char *NC) {
    int n;
    char *code = (char *)malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++) {
        code[8 - i] = NC[M[i]];
        if (code[8 - i] == ' ') {
            code[8 - i] = '#';
        }
    }
    return code;
}

int main() {
    // Entrada: vetor de índices M e string NC
    int M[] = {2, 0, 2, 0, 4, 5, 7, 6, 9}; // Vetor de índices
    char NC[] = "gabriel saraiva canabrava"; // String

    // Chamando a função
    char *resultado = Q3(M, NC);

    // Imprimindo o resultado
    printf("Resultado: %s\n", resultado);

    // Liberando a memória alocada
    free(resultado);

    return 0;
}