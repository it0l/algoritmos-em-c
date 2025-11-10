#include <stdio.h>
#include <stdlib.h>


void preencher_espiral(int N, int matriz[][N]) {
    int min_linha = 0;
    int max_linha = N - 1;
    int min_coluna = 0;
    int max_coluna = N - 1;

    int valor = 1;

    while (min_linha <= max_linha && min_coluna <= max_coluna) {
        
        for (int j = min_coluna; j <= max_coluna; j++) {
            matriz[min_linha][j] = valor++;
        }
        min_linha++; 

        for (int i = min_linha; i <= max_linha; i++) {
            matriz[i][max_coluna] = valor++;
        }
        max_coluna--; 

        if (min_linha <= max_linha) {
            for (int j = max_coluna; j >= min_coluna; j--) {
                matriz[max_linha][j] = valor++;
            }
            max_linha--; 
        }

        if (min_coluna <= max_coluna) {
            for (int i = max_linha; i >= min_linha; i--) {
                matriz[i][min_coluna] = valor++;
            }
            min_coluna++; 
        }
    }
}

void exibir_matriz(int N, int matriz[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matriz[i][j]); 
        }
        printf("\n");
    }
}

int main() {
    int N;

    printf("Digite o tamanho da matriz quadrada N (N x N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Entrada invalida. N deve ser um inteiro positivo.\n");
        return 1;
    }

    int matriz[N][N];

    preencher_espiral(N, matriz);

    printf("\nMatriz %d x %d preenchida em espiral (sentido horario):\n", N, N);
    exibir_matriz(N, matriz);

    return 0;
}
