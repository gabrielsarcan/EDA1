#include <stdio.h>

int encontra(int *vetor, int x, int tamanho){
    if (tamanho == 0){
        return -1;
    }
    if (vetor[tamanho] == x){
        return tamanho + 1;
    }
    else{
        return encontra(vetor, x, tamanho - 1);
    }

}

int main(){
    int vetor[10] = {1, 2, 3, 4, 5, 500, 20, 30, 40, 100};
    int x = 11;
    int tamanho = 9;
    int resultado = encontra(vetor, x, tamanho);
    printf("%d", resultado);
}