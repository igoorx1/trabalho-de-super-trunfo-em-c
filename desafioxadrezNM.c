#include <stdio.h>

// ===============================
// Função recursiva para Torre (direita)
// ===============================
void moverTorre(int casas, int atual) {
    if (atual > casas) return; // caso base
    printf("Direita (casa %d)\n", atual);
    moverTorre(casas, atual + 1); // chamada recursiva
}

// ===============================
// Função recursiva para Rainha (esquerda)
// ===============================
void moverRainha(int casas, int atual) {
    if (atual > casas) return; // caso base
    printf("Esquerda (casa %d)\n", atual);
    moverRainha(casas, atual + 1); // chamada recursiva
}

// ===============================
// Função recursiva para Bispo
// Aqui chamamos recursivamente cada passo diagonal
// e também podemos usar loops aninhados para vertical/horizontal
// ===============================
void moverBispoRecursivo(int casas, int atual) {
    if (atual > casas) return; // caso base
    printf("Cima, Direita (casa %d)\n", atual);
    moverBispoRecursivo(casas, atual + 1); // chamada recursiva
}

// Versão com loops aninhados (vertical externo, horizontal interno)
void moverBispoLoops(int casasVert, int casasHoriz) {
    for (int v = 1; v <= casasVert; v++) {
        for (int h = 1; h <= casasHoriz; h++) {
            printf("Cima, Direita (passo V%d-H%d)\n", v, h);
        }
    }
}

// ===============================
// Movimento do Cavalo (duas para cima e uma para direita)
// usando loops aninhados + múltiplas variáveis + break/continue
// ===============================
void moverCavalo() {
    int movVertical = 2; // duas casas para cima
    int movHorizontal = 1; // uma casa para direita
    printf("\nMovimento do CAVALO:\n");
    for (int v = 1; v <= movVertical; v++) {
        if (v == 1) {
            printf("Cima (passo %d)\n", v);
        } else if (v == 2) {
            printf("Cima (passo %d)\n", v);
            // loop interno para o movimento horizontal (direita)
            for (int h = 1; h <= movHorizontal; h++) {
                if (h == 1) {
                    printf("Direita (passo %d)\n", h);
                } else {
                    // só para demonstrar uso do continue/break
                    continue;
                }
            }
        }
    }
}

int main() {
    // ===============================
    // TORRE – usando recursividade
    // ===============================
    printf("Movimento da TORRE:\n");
    moverTorre(5, 1);

    // ===============================
    // BISPO – recursivo
    // ===============================
    printf("\nMovimento do BISPO (recursivo):\n");
    moverBispoRecursivo(5, 1);

    // ===============================
    // BISPO – loops aninhados (extra)
    // ===============================
    printf("\nMovimento do BISPO (loops aninhados):\n");
    moverBispoLoops(2, 2); // exemplo: 2 verticais x 2 horizontais

    // ===============================
    // RAINHA – usando recursividade
    // ===============================
    printf("\nMovimento da RAINHA:\n");
    moverRainha(8, 1);

    // ===============================
    // CAVALO – loops complexos
    // ===============================
    moverCavalo();

    return 0;
}

