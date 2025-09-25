#include <stdio.h>

int main() {
    // TORRE – movimento horizontal (direita) usando FOR
    int casasTorre = 5;
    printf("Movimento da TORRE:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita (casa %d)\n", i);
    }

    // BISPO – movimento diagonal (cima + direita) usando WHILE
    int casasBispo = 7;
    int contadorBispo = 1;
    printf("\nMovimento do BISPO:\n");
    while (contadorBispo <= casasBispo) {
        printf("Cima, Direita (casa %d)\n", contadorBispo);
        contadorBispo++;
    }

    // RAINHA – movimento horizontal (esquerda) usando DO-WHILE
    int casasRainha = 8;
    int contadorRainha = 1;
    printf("\nMovimento da RAINHA:\n");
    do {
        printf("Esquerda (casa %d)\n", contadorRainha);
        contadorRainha++;
    } while (contadorRainha <= casasRainha);
// ==============================================
// CAVALO – movimento em "L"
// 2 casas para baixo e 1 para esquerda
// usando loops aninhados (for + while)
// ==============================================
printf("\nMovimento do CAVALO:\n");

// Loop externo: duas casas para baixo
for (int i = 1; i <= 2; i++) {
    printf("Baixo (casa %d)\n", i);
}

// Loop interno: uma casa para a esquerda (usando while)
int movimentosEsquerda = 1;
int contador = 1;
while (contador <= movimentosEsquerda) {
    printf("Esquerda (casa %d)\n", contador);
    contador++;}
    
    return 0; // fim do programa
}


