#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 200

// Estrutura da arvore binaria
typedef struct Node{
    int age;
    int tumor;
    int line;
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Criar um node e alocar na memoria
Node* criarNode(int age, int tumor, int line){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->age = age;
    newNode->tumor = tumor;
    newNode->line = line;
    newNode->esquerda = NULL;
    newNode->direita = NULL;
    return newNode;
}

// Função inserir um nó
Node *inserirNode(Node* raiz, int age, int tumor, int line){
    if (raiz == NULL){
        return criarNode(age, tumor, line);
    }

    if (age < raiz->age) {
        raiz->esquerda = inserirNode(raiz->esquerda, age, tumor, line);
    }

    else if (age > raiz->age){
        raiz->direita = inserirNode(raiz->direita, age, tumor, line);
    }

    else {
        if (tumor <= raiz->tumor){
            raiz->esquerda = inserirNode(raiz->esquerda, age, tumor, line);
        }
        else {
            raiz->direita = inserirNode(raiz->direita, age, tumor, line);
        }
    }
    return raiz;
}

//Funcão para imprimir em ordem
void inOrder(Node* raiz){
    if (raiz != NULL){
        inOrder(raiz->esquerda);
        printf("idade: %i | tumor: %i | linha: %i\n", raiz->age, raiz->tumor, raiz->line);
        inOrder(raiz->direita);
    }
}

//Função para gerar o relatorio
void desalocarArvore(Node* raiz){
    if (raiz != NULL){
        desalocarArvore(raiz->esquerda);
        desolacarArvore(raiz->direita);
        free(raiz);
    }
}

// Função para ler o arquvo
void lerArquivo(char *NomeArquivo, Node** raiz){
    FILE *fp;
    char linha[MAX_LINHA];
    char *token;
    int nlinha = 1;

    
    fp = fopen(NomeArquivo, "r");

    if (fp == NULL){
        printf("não foi possivel abrir o arquivo");
        system("pause");
        exit(0);
    }

    fgets(linha, MAX_LINHA, fp); // pula a primeira linha
    // Lê as linhas seguintes (dados)
    while (fgets(linha, MAX_LINHA, fp)) {
        nlinha++;  // Conta a linha

        // Usa strtok para dividir a linha usando a vírgula como delimitador
        token = strtok(linha, ",");  // Primeiro campo (Age)
        int idade = atoi(token);     // Converte para inteiro
        
        // Pula para o campo "Tumor Size"
        for (int i = 0; i < 9; i++) {
            token = strtok(NULL, ",");
        }
        int tumorSize = atoi(token);  // Converte para inteiro

        *raiz = inserirNode(*raiz, idade, tumorSize, nlinha);
        // Exibe os dados lidos
    }

    // Fecha o arquivo
    fclose(fp);

}

int main(){
    Node* raiz = NULL;
    char NomeArquivo[100];

    printf("Digite o nome do arquivo: ");
    scanf("%s", NomeArquivo);
    lerArquivo(NomeArquivo, &raiz);
    inOrder(raiz);
    desalocarArvore(raiz);
}