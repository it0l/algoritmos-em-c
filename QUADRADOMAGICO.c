#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void limparTela() {
    system("cls");
}

void mostrarQuadrado(int quadrado[3][3]) {
    limparTela();
    printf(" (Quadrado Magico)\n");
    printf("Preencha com numeros de 1 a 9 sem repetir.\n\n");
    for (int i = 0; i < 3; i++) {
        printf("\t");
        for (int j = 0; j < 3; j++) {
            if (quadrado[i][j] == 0) {
                printf(" x "); 
            } else {
                printf("%d ", quadrado[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool contemNumero(int quadrado[3][3], int numero) {
    bool encontrado = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (quadrado[i][j] == numero) {
                encontrado = true;
                break;
            }
        }
        if (encontrado) {
            break;
        }
    }
    return encontrado;
}

void preencher(int quadrado[3][3]) {
    int numero;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mostrarQuadrado(quadrado);
            while (true) {
                printf("Digite um numero para a posicao linha %d e coluna %d: ", i, j);
                scanf("%d", &numero);

                if (numero < 1 || numero > 9) {
                    printf("Numero invalido. Tente um valor entre 1 e 9.\n");
                } else if (contemNumero(quadrado, numero)) {
                    printf("Numero repetido. Tente outro numero.\n");
                } else {
                    quadrado[i][j] = numero;
                    break;
                }
            }
        }
    }
}

bool verificarQuadradoMagico(int quadrado[3][3]) {
    int somaReferencia = 15;
    bool ehMagico = true;

    for (int i = 0; i < 3; i++) {
        int somaLinha = 0;
        int somaColuna = 0;
        for (int j = 0; j < 3; j++) {
            somaLinha += quadrado[i][j];
            somaColuna += quadrado[j][i];
        }
        if (somaLinha != somaReferencia || somaColuna != somaReferencia) {
            ehMagico = false;
        }
    }

    int somaDiagonalPrincipal = 0;
    int somaDiagonalSecundaria = 0;
    for (int i = 0; i < 3; i++) {
        somaDiagonalPrincipal += quadrado[i][i];
        somaDiagonalSecundaria += quadrado[i][2 - i];
    }

    if (somaDiagonalPrincipal != somaReferencia || somaDiagonalSecundaria != somaReferencia) {
        ehMagico = false;
    }

    return ehMagico;
}

int main() {
    int quadrado[3][3] = {0};

    preencher(quadrado);

    mostrarQuadrado(quadrado);

    if (verificarQuadradoMagico(quadrado)) {
        printf("Parabens! Este e um Quadrado Magico!\n");
    } else {
        printf("Este nao e um Quadrado Magico. Tente novamente.\n");
    }

    return 0;
}
