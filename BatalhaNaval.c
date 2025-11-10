#include <stdio.h>
#include <stdlib.h>


const int TAMANHO_MAPA = 10;
const char AGUA = '~';
const char NAVIO = 'N';
const char ACERTO = 'X';
const char ERRO = 'O';

void inicializarTabuleiro(char tabuleiro[10][10]);
void mostrarTabuleiro(char tabuleiro[10][10], int mostrarNavios);
int validarPosicao(char tabuleiro[10][10], int linha, int coluna, int tamanhoNavio, int direcao);
void posicionarNavio(char tabuleiro[10][10], int linha, int coluna, int tamanhoNavio, int direcao);
int verificarFimDeJogo(char tabuleiro[10][10]);
void limparBuffer();

int main() {
    char tabuleiroJogador1[10][10];
    char visaoJogador2[10][10];

    inicializarTabuleiro(tabuleiroJogador1);
    inicializarTabuleiro(visaoJogador2);

    printf("=== BATALHA NAVAL ===\n\n");
    printf("Jogador 1, posicione seus 6 navios no mapa %dx%d.\n", TAMANHO_MAPA, TAMANHO_MAPA);
    

    int navios[][2] = {{5, 1}, {4, 2}, {3, 3}};
    
    int tamanhoNavioAtual;
    int x, y, direcao;
    int leitura_ok;

    for (int k = 0; k < 3; k++) {
        tamanhoNavioAtual = navios[k][0];
        int numNavios = navios[k][1];
        
        for (int i = 0; i < numNavios; i++) {
            system("cls || clear");
            mostrarTabuleiro(tabuleiroJogador1, 1);
            
            do {
                printf("Posicione seu navio de tamanho %d (Item %d/%d):\n", tamanhoNavioAtual, i + 1, numNavios);
                printf("  Casa Inicial - Linha (1-%d), Coluna (1-%d): ", TAMANHO_MAPA, TAMANHO_MAPA);
                leitura_ok = scanf("%d %d", &y, &x);
                
                printf("  Direcao - Horizontal (1) ou Vertical (2): ");
                leitura_ok += scanf("%d", &direcao);
                
                if (leitura_ok != 3) {
                    printf("Erro: Entrada invalida. Por favor, insira apenas numeros inteiros.\n");
                    limparBuffer();
                    y = -1; 
                    x = -1;
                    direcao = 0;
                }
            } while (validarPosicao(tabuleiroJogador1, y - 1, x - 1, tamanhoNavioAtual, direcao) == 0);
            
            posicionarNavio(tabuleiroJogador1, y - 1, x - 1, tamanhoNavioAtual, direcao);
        }
    }

    system("cls || clear");
    printf("Mapa final do Jogador 1:\n");
    mostrarTabuleiro(tabuleiroJogador1, 1);
    printf("Todos os navios posicionados!\n");

    // Limpar tela e inicio do jogo
    printf("Pressione Enter para iniciar a batalha...");
    getchar();
    limparBuffer();
    system("cls || clear");

    printf("=== A BATALHA COMECOU! ===\n\n");

    while (verificarFimDeJogo(tabuleiroJogador1) == 0) {
        printf("\n-- VEZ DO JOGADOR 2 --\n");
        printf("Mapa Inimigo (Onde atirar):\n");
        mostrarTabuleiro(visaoJogador2, 0);

        printf("Atirar: Linha (1-%d) e Coluna (1-%d): ", TAMANHO_MAPA, TAMANHO_MAPA);
        leitura_ok = scanf("%d %d", &y, &x);

        if (leitura_ok != 2) {
            printf("Erro: Entrada invalida. Por favor, insira apenas numeros inteiros.\n");
            limparBuffer();
            continue;
        }
        
        limparBuffer();

        int linha = y - 1;
        int coluna = x - 1;

        if (linha < 0 || linha >= TAMANHO_MAPA || coluna < 0 || coluna >= TAMANHO_MAPA) {
            printf("Coordenadas invalidas! Tente novamente.\n");
            continue;
        }

        if (visaoJogador2[linha][coluna] == ACERTO || visaoJogador2[linha][coluna] == ERRO) {
            printf("Voce ja atirou nesta casa! Tente outra.\n");
            continue;
        }

        if (tabuleiroJogador1[linha][coluna] == NAVIO) {
            printf("\n>>> ACERTOU! <<<\n");
            visaoJogador2[linha][coluna] = ACERTO;
            tabuleiroJogador1[linha][coluna] = ACERTO;
            printf("Jogue novamente!\n");
        } else {
            printf("\n>>> ERROU! (Agua) <<<\n");
            visaoJogador2[linha][coluna] = ERRO;
            printf("Passando a vez...\n");
            break;
        }
    }

    if (verificarFimDeJogo(tabuleiroJogador1)) {
        printf("\n==================================\n");
        printf("=== FIM DE JOGO! JOGADOR 2 VENCEU! ===\n");
        printf("==================================\n");
    } else {
        printf("\nAQUI COMECARIA A VEZ DO JOGADOR 1.\n");
    }

    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inicializarTabuleiro(char tabuleiro[10][10]) {
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void mostrarTabuleiro(char tabuleiro[10][10], int mostrarNavios) {
    printf("   ");
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            if (tabuleiro[i][j] == NAVIO && !mostrarNavios) {
                printf("%c  ", AGUA); 
            } else {
                printf("%c  ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int validarPosicao(char tabuleiro[10][10], int linha, int coluna, int tamanhoNavio, int direcao) {
    if (linha < 0 || linha >= TAMANHO_MAPA || coluna < 0 || coluna >= TAMANHO_MAPA) {
        printf("Erro: Posicao inicial fora do mapa! Escolha entre 1 e %d.\n", TAMANHO_MAPA);
        return 0;
    }
    
    if (direcao != 1 && direcao != 2) {
        printf("Erro: Direcao invalida! Escolha 1 (Horizontal) ou 2 (Vertical).\n");
        return 0;
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        int r = linha + (direcao == 2 ? i : 0);
        int c = coluna + (direcao == 1 ? i : 0);

        if (r >= TAMANHO_MAPA || c >= TAMANHO_MAPA) {
            printf("Erro: O navio de tamanho %d nao cabe !\n", tamanhoNavio);
            return 0;
        }

        if (tabuleiro[r][c] != AGUA) {
            printf("Erro: Ja existe um navio nesta posicao!\n");
            return 0;
        }
    }

    return 1;
}

void posicionarNavio(char tabuleiro[10][10], int linha, int coluna, int tamanhoNavio, int direcao) {
    for (int i = 0; i < tamanhoNavio; i++) {
        int r = linha + (direcao == 2 ? i : 0);
        int c = coluna + (direcao == 1 ? i : 0);
        tabuleiro[r][c] = NAVIO;
    }
}

int verificarFimDeJogo(char tabuleiro[10][10]) {
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            if (tabuleiro[i][j] == NAVIO) {
                return 0;
            }
        }
    }
    return 1;
}
