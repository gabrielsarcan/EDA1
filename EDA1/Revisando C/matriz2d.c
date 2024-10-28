#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int resultado ();
int arr[15][20];
int fileira;
int assento;

int main() {
    srand(time(NULL));

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 20; j++){
            int n = rand() % 2;
            arr[i][j] = n;
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("Qual a fileira do assento:");
    scanf("%d", &fileira);
    printf("\n");
    printf("Qual o numero do assento:");
    scanf("%d", &assento);
    
    if (arr[fileira][assento] == 1){
        printf("fileira ocupada");
    
    } else if (arr[fileira][assento] == 0){
        arr[fileira][assento] = 1;
    }
    resultado();
}

int resultado () {
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 20; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}