#include "VetoresC.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

}

int* CriaVetInt (int n) {
    int* vetor = (int*)malloc(sizeof(int)*n);

    if (vetor == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        return NULL;
    }    

    return vetor;
}

float* CriaVetFloat (int n) {
    float* vetor = (float*)malloc(sizeof(float)*n);

    if (vetor == NULL) {
        printf("Erro: não foi possivel alocar memória.\n");
    }

    return vetor;

char* CriaVetChar (int n) {
    char* vetor = (char*)malloc(sizeof(char)*n);

    if (vetor == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        return NULL;
    }    
    return vetor;
}
}
