#include <stdio.h>

float sumArray(int arr[]);
int n = 3;
float total;
float media;

int main(){
    int arr[n];

    for (int i = 0; i < n; i++){
        printf("coloque suas notas %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    sumArray(arr);
    printf("media: %.2f\n", media);
}

float sumArray(int arr[]){
   
        for(int i = 0; i < n; i++){
        total += arr[i];
    }
    
    media = total / n;
    return media;
}