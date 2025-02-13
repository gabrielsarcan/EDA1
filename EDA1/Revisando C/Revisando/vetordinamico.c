#include <stdio.h>
#include <stdlib.h>

void incluir_vetor(char **pvtcar, int *ptammax, int *pqtde, char valor){
    if(*pqtde == *ptammax){
        (*ptammax) ++;
        char *temp = (char *)realloc(*pvtcar, *ptammax * sizeof(char));
        if (temp == NULL) {
            printf("Erro");
            free(*pvtcar);
        }

        *pvtcar = temp;

    }

    (*pvtcar)[*pqtde] = valor;
    (*pqtde)++ ;
}

void char_delete(char **pvtcar, int *ptammax, int *pqtde, char valor){
    for (int i = 0; i < *pqtde; i++){
        if((*pvtcar)[i] == valor){
            for(int j = i; j < *pqtde - 1; j++){
                (*pvtcar)[j] = (*pvtcar)[j+1];
            }

            (*pqtde) --;
            (*ptammax) --;
            char *temp = (char *)realloc(*pvtcar, *ptammax * sizeof(char));
        
        if(temp == NULL){
            printf("Erro");
            free(*pvtcar);     
            return;      
        }
        *pvtcar = temp;
        break;
        }
    }
}


int main(){
    int ptammax = 2;
    int pqtde = 0;
    char *pvetcar = malloc(ptammax * sizeof(char));

    incluir_vetor(&pvetcar, &ptammax, &pqtde, 'a');
    incluir_vetor(&pvetcar, &ptammax, &pqtde, 'b');
    incluir_vetor(&pvetcar, &ptammax, &pqtde, 'c');
    char_delete(&pvetcar, &ptammax, &pqtde, 'c');

    for (int i = 0; i < pqtde; i++){
        printf("%c ", pvetcar[i]);
    }


    free(pvetcar);
}