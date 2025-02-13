int maior(int *v, int n) {
    if (n == 1) {
        return v[0]; // Caso base: um único elemento, retorna ele
    } else {
        int m = maior(v, n - 1); // Calcula o maior do subvetor
        if (v[n - 1] > m) {
            return v[n - 1]; // Se o último elemento for maior, retorna ele
        } else {
            return m; // Caso contrário, retorna o maior do subvetor
        }
    }
}

int main() {
    int n, v[100];
    printf("Digite o tamanho do vetor (no máximo 100): ");
    scanf("%d", &n);
    srand(time(NULL));
    printf("O vetor gerado aleatoriamente é: ");
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
        printf("%d ", v[i]);
    }
    printf("\nO maior elemento do vetor é %d\n", maior(v, n));
    return 0;
}