#include <stdio.h>
int add(int a, int b);

int main() {
    int a;
    int b;
    int c;

    printf("x: ");
    scanf("%d", &a);

    printf("y: ");
    scanf("%d", &b);

    c = add(a, b);
    printf("%i\n", c);
}

int add(int a, int b){

    int c = a + b;
    return c;
}