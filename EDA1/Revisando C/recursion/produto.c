#include <stdio.h>

int produto(int x, int y){
    if (y == 0){
        return 0;

    } else {
        return x + produto(x, y - 1);
    }
}

int main (){
    int resultado = produto(3, 3);
    printf("%d\n", resultado);
}