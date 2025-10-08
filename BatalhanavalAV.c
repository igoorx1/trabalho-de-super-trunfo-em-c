#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa tudo com 0 (água)

    // ======= Navio 1 (horizontal) =======
    for (int j = 1; j <= 3; j++) {
        tabuleiro[8][j] = 3; // Linha 2, colunas 1-3
    }

    // ======= Navio 2 (vertical) =======
    for (int i = 4; i <= 6; i++) {
        tabuleiro[i][5] = 3; // Coluna 5, linhas 4-6
    }

    // ======= Navio 3 (diagonal principal) =======
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3; // (0,0), (1,1), (2,2)
    }

    // ======= Navio 4 (diagonal secundária) =======
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3; // (0,9), (1,8), (2,7)
    }

    // ======= Exibir o tabuleiro =======
    printf("=== Tabuleiro de Batalha Naval ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

