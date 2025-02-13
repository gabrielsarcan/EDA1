#include <stdio.h>

int AckermannRecursivo (int m, int n){
    if (m < 0 || n < 0){
        printf("Não é um numero valido\n");

    }

    if (m == 0){
        return n+1;

    }

    if (m > 0 && n == 0) {
        return AckermannRecursivo(m - 1, 1);
    }

    if (m > 0 && n > 0) {
        return AckermannRecursivo(m -1, AckermannRecursivo(m, n -1));
    }
}

int main () {
    int m, n;

    printf("Coloque o primeiro numero:");
    scanf("%d", &m);
    printf("\n");
    printf("Coloque o segundo numero:");
    scanf("%d", &n);

    int total = AckermannRecursivo(m, n);
    printf("%d", total);
}