#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// ==========================================
// Função para exibir qualquer matriz (tabuleiro ou habilidade)
// ==========================================
void exibirMatriz(int matriz[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (matriz[i][j] == 0)
                printf(" 0 ");  // Água
            else if (matriz[i][j] == 3)
                printf(" 3 ");  // Navio
            else if (matriz[i][j] == 5)
                printf(" 5 ");  // Área afetada
        }
        printf("\n");
    }
}

// ==========================================
// Função para aplicar uma habilidade (5x5) sobre o tabuleiro
// ==========================================
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tabLinha = origemLinha - TAM_HABILIDADE / 2 + i;
            int tabColuna = origemColuna - TAM_HABILIDADE / 2 + j;

            // Valida se está dentro dos limites
            if (tabLinha >= 0 && tabLinha < TAM_TABULEIRO && tabColuna >= 0 && tabColuna < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1)
                    tabuleiro[tabLinha][tabColuna] = 5; // Marca área afetada
            }
        }
    }
}

// ==========================================
// Função principal
// ==========================================
int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // ==========================================
    // Criar as 3 habilidades
    // ==========================================
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // -------- Cone --------
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
        }
    }

    // -------- Cruz --------
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
        }
    }

    // -------- Octaedro --------
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(2 - i) + abs(2 - j) <= 2)
                octaedro[i][j] = 1;
        }
    }

    // ==========================================
    // Posicionar navios fixos (valor 3)
    // ==========================================
    tabuleiro[1][1] = tabuleiro[1][2] = tabuleiro[1][3] = 3; // Navio horizontal
    tabuleiro[4][4] = tabuleiro[5][4] = tabuleiro[6][4] = 3; // Navio vertical
    tabuleiro[7][2] = tabuleiro[8][3] = tabuleiro[9][4] = 3; // Navio diagonal
    tabuleiro[2][9] = tabuleiro[3][8] = tabuleiro[4][7] = 3; // Outro navio diagonal

    // ==========================================
    // Aplicar habilidades no tabuleiro
    // ==========================================
    aplicarHabilidade(tabuleiro, cone, 3, 3);      // Cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro mais à direita

    // ==========================================
    // Exibir tabuleiro final
    // ==========================================
    printf("=== TABULEIRO FINAL ===\n");
    exibirMatriz(tabuleiro);

    return 0;
}

