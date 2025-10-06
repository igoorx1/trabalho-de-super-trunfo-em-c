#include <stdio.h>

// ---------- Constantes do jogo ----------
#define TAMANHO 10     // Tamanho fixo do tabuleiro 10x10
#define NAVIO 3        // Tamanho fixo dos navios (3 posições)
#define AGUA 0         // Representa água
#define NAVIO_VALOR 3  // Representa parte de navio

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Matriz 10x10 para o tabuleiro
    int i, j;

    // ---------- 1. Inicializar o tabuleiro ----------
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA; // Todas as posições começam como água (0)
        }
    }

    // ---------- 2. Definir coordenadas iniciais dos navios ----------
    // Navio 1 → Horizontal
    int linhaNavio1 = 2;   // linha inicial
    int colunaNavio1 = 4;  // coluna inicial

    // Navio 2 → Vertical
    int linhaNavio2 = 5;   // linha inicial
    int colunaNavio2 = 7;  // coluna inicial

    // ---------- 3. Validar limites e posicionar os navios ----------
    // Navio horizontal
    if (colunaNavio1 + NAVIO <= TAMANHO) {
        for (j = 0; j < NAVIO; j++) {
            tabuleiro[linhaNavio1][colunaNavio1 + j] = NAVIO_VALOR;
        }
    } else {
        printf("Erro: o navio horizontal ultrapassa os limites do tabuleiro.\n");
    }

    // Navio vertical
    if (linhaNavio2 + NAVIO <= TAMANHO) {
        for (i = 0; i < NAVIO; i++) {
            // Verifica se há sobreposição com outro navio
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] == AGUA) {
                tabuleiro[linhaNavio2 + i][colunaNavio2] = NAVIO_VALOR;
            } else {
                printf("Aviso: posição [%d][%d] já ocupada. Evitando sobreposição.\n",
                       linhaNavio2 + i, colunaNavio2);
            }
        }
    } else {
        printf("Erro: o navio vertical ultrapassa os limites do tabuleiro.\n");
    }

    // ---------- 4. Exibir o tabuleiro ----------
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}