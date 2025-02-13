#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMEROS 1000  
#define MAX_LINHA 10000   


int buscaSequencial(int *numeros, int indice, int chave){
    int p = -1;

    for(int i = 0; i <= indice; i++){
        if (numeros[i] == chave){
            p = i;
            return p;
        }
    }
    return p;
}

int buscaSequencialOrdenada(int *numeros, int indice, int chave){
    int p = 0;
    int posic = -1;
    
    while (p < indice && numeros[p] <= chave){
        if (numeros[p] == chave){
            posic = p;
            return posic;
        } 
    p++; 
    }
    return posic;
}

int buscaBinaria(int *numeros, int indice, int chave){
    int inicio = 0;
    int meio;
    int final = indice - 1;

    while(inicio <= final){
        meio = (inicio + final) / 2; 
        if(chave == numeros[meio]){
            return meio;
        }
        if(chave < numeros[meio]){
           final = meio - 1;
        }
        if(chave > numeros[meio]){
            inicio = meio + 1;
        }

    }
    return -1;
}

void main(){
    FILE *arquivo;
    char linha[MAX_LINHA];
    int numeros[MAX_NUMEROS];
    int indice = 0;

    arquivo = fopen("ordernado.txt", "r");

    if (arquivo == NULL){
        printf("Unable to open file\n");
        system("pause");
        exit(0);
    }

    if (fgets(linha, MAX_LINHA, arquivo) != NULL){
        char *token = strtok(linha, " ");

        while (token != NULL && indice < MAX_NUMEROS) {
            numeros[indice++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }
    fclose(arquivo);

    int x = buscaBinaria(numeros, indice, 5);
    printf("%d", x);


}