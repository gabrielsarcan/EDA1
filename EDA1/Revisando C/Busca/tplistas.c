#include <stdio.h>

int faux(char *vet, int tam, int i) {
    int j, min = i;
    for (j = i + 1; j < tam; j++) {
        if (vet[j] < vet[min])
            min = j;
    }
    return min;
}

int Q4(char *vet, int tam) {
    int i, min, aux, pcont = 0;
    for (i = 0; i < tam; i++) {
        min = faux(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
        pcont = pcont + (tam - i);
    }
    return pcont;
}
// Qual o valor de R?
// Qual o valor de nome?
// Qual tipo de ordenacao da funcao q4?

int main(){
    char nc[] = "gabri";
    int res = Q4(nc, 5); // primeiro nome, qtd de letras 1o nome;
    printf("\n\nresposta = %d\n\nnc = %s\n\n", res, nc);
}