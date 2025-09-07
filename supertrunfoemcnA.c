#include <stdio.h>

typedef struct {
    char estado[3];             // ex: "SP"
    char codigo[4];             // ex: "A01"
    char nome[50];              // ex: "Sao Paulo"
    unsigned long populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;            // NOVA VARIÁVEL
    float pib_per_capita;       // NOVA VARIÁVEL
} Carta;

// Funções para calcular os valores
float calcularDensidade(Carta c) {
    return c.populacao / c.area;
}

float calcularPibPerCapita(Carta c) {
    return c.pib / c.populacao;
}

// Exibir os dados da carta
void mostrarCarta(Carta c) {
    printf("Carta %s - %s (%s)\n", c.codigo, c.nome, c.estado);
    printf("Populacao: %lu\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Pop: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: %.2f\n\n", c.pib_per_capita);
}

int main() {
    // Cadastro inicial
    Carta c1 = {"SP", "A01", "Sao Paulo", 12300000, 1521.11f, 700000.0f, 10};
    Carta c2 = {"RJ", "B02", "Rio de Janeiro", 6700000, 1182.30f, 400000.0f, 8};

    // Calcula e armazena os novos valores
    c1.densidade = calcularDensidade(c1);
    c1.pib_per_capita = calcularPibPerCapita(c1);

    c2.densidade = calcularDensidade(c2);
    c2.pib_per_capita = calcularPibPerCapita(c2);

    // Mostra as cartas já com os cálculos
    mostrarCarta(c1);
    mostrarCarta(c2);

    return 0;
}

