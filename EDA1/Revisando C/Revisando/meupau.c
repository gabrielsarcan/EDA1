#include <stdio.h>
#include <stdbool.h>

// Função para verificar se o padrão P ocorre no texto T a partir do deslocamento s
bool comparar_subsequencia(int *T, int *P, int s, int m) {
    for (int i = 0; i < m; i++) {
        if (T[s + i] != P[i]) {
            return false;
        }
    }
    return true;
}

// Função para encontrar todos os deslocamentos válidos
void encontrar_deslocamentos(int *T, int n, int *P, int m) {
    printf("Deslocamentos válidos: ");
    for (int s = 0; s <= n - m; s++) {
        if (comparar_subsequencia(T, P, s, m)) {
            printf("%d ", s);
        }
    }
    printf("\n");
}

int main() {
    // Exemplo de uso
    int T[] = {1, 2, 3, 1, 2, 3, 4}; // Vetor texto
    int P[] = {1, 2, 3};             // Vetor padrão
    int n = sizeof(T) / sizeof(T[0]);
    int m = sizeof(P) / sizeof(P[0]);

    encontrar_deslocamentos(T, n, P, m);

    return 0;
}
