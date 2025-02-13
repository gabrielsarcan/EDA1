#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int resultado();
int arr[10];
int opt;
int qtd;
int produto;

int main () {
    srand(time(NULL));


    for (int i = 0; i < 10; i++){
        int n = (rand() % 100) + 1;
        arr[i] = n;
        printf("%d, ", arr[i]);
    }
    printf("\n");
    printf("Escolha uma das opções:\n");
    printf("1 - Compra\n");
    printf("2 - Adicionar\n");


    printf("Digite o número da opção desejada: ");
    scanf("%d", &opt);

    if (opt == 1){

        printf("Você escolheu: Compra\n");
        printf("Selecione o numero do Produto:");
        scanf("%d", &produto);
        printf("Selecione a quantidade:");
        scanf("%d", &qtd);
        arr[produto] -= qtd;
 

    } else if (opt == 2) {
        printf("Você escolheu: Adicionar\n");
        printf("Selecione o numero do Produto:");
        scanf("%d", &produto);
        printf("Selecione a quantidade:");
        scanf("%d", &qtd);
        arr[produto] += qtd;
    }
    
    resultado();
}

int resultado () {
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", arr[i]);
    }
    
}

