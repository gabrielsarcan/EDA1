#include <stdio.h>

int potencia(int x, int y){
    if (y == 0){
        return 1;

    } else {
        return x * potencia(x, y - 1);
    }
}

int main (){
    int resultado = potencia(3, 3);
    printf("%d\n", resultado);
}