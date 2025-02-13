#include <stdio.h>
#include <string.h>

int palindromo(char *str, int inicio, int fim){
    char temp;

    if (inicio >= fim){
        return 1;

    } if (str[inicio] != str[fim]) {
        return 0;

    } else {      
        palindromo(str,inicio + 1 , fim - 1);

    }
}

int main (){
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    int n = strlen(str) -1;

    if (palindromo(str,0 , n) == 1) {
        printf("A string '%s' é um palíndromo.\n", str);

    } else {
        printf("A string '%s' não é um palíndromo.\n", str);
    }
    
}