#include <stdio.h>

int somanumero(int x){
    if (x == 0){
        return 0;

    } else {
        return x % 10 + somanumero(x / 10);
    }
}

int main(){
    int resultado = somanumero(23);
    printf("%d\n", resultado);
}