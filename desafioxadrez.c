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

    return 0; // fim do programa
}

