#include <stdio.h>

typedef struct {
    char estado[3];             // Ex: "SP"
    char codigo[4];             // Ex: "A01"
    char nome[50];              // Ex: "Sao Paulo"
    unsigned long populacao;    // agora suporta números grandes
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

// Funções auxiliares
float calcularDensidade(Carta c) {
    return c.populacao / c.area;
}

float calcularPibPerCapita(Carta c) {
    return c.pib / c.populacao;
}

float calcularSuperPoder(Carta c) {
    return (float)c.populacao + c.area + c.pib + c.pontos_turisticos 
           + c.pib_per_capita + (1.0f / c.densidade);
}

// Função para ler os dados de uma carta
Carta lerCarta(int numero) {
    Carta c;

    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Digite o estado: ");
    scanf("%2s", c.estado);

    printf("Digite o codigo: ");
    scanf("%3s", c.codigo);

    printf("Digite o nome: ");
    scanf(" %[^\n]", c.nome); // permite ler nomes com espaço

    printf("Digite a populacao: ");
    scanf("%lu", &c.populacao);

    printf("Digite a area: ");
    scanf("%f", &c.area);

    printf("Digite o PIB: ");
    scanf("%f", &c.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &c.pontos_turisticos);

    // Calcula valores derivados
    c.densidade = calcularDensidade(c);
    c.pib_per_capita = calcularPibPerCapita(c);
    c.super_poder = calcularSuperPoder(c);

    return c;
}

// Comparação de atributos
void compararCartas(Carta c1, Carta c2) {
    printf("\n--- Comparacao de Cartas ---\n");

    printf("Populacao: Carta %d venceu (%d)\n", 
           (c1.populacao > c2.populacao ? 1 : 2), 
           (c1.populacao > c2.populacao ? 1 : 0));

    printf("Area: Carta %d venceu (%d)\n", 
           (c1.area > c2.area ? 1 : 2), 
           (c1.area > c2.area ? 1 : 0));

    printf("PIB: Carta %d venceu (%d)\n", 
           (c1.pib > c2.pib ? 1 : 2), 
           (c1.pib > c2.pib ? 1 : 0));

    printf("Pontos Turisticos: Carta %d venceu (%d)\n", 
           (c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2), 
           (c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 0));

    // Aqui a regra é invertida (menor densidade vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
           (c1.densidade < c2.densidade ? 1 : 2), 
           (c1.densidade < c2.densidade ? 1 : 0));

    printf("PIB per Capita: Carta %d venceu (%d)\n", 
           (c1.pib_per_capita > c2.pib_per_capita ? 1 : 2), 
           (c1.pib_per_capita > c2.pib_per_capita ? 1 : 0));

    printf("Super Poder: Carta %d venceu (%d)\n", 
           (c1.super_poder > c2.super_poder ? 1 : 2), 
           (c1.super_poder > c2.super_poder ? 1 : 0));
}

int main() {
    // Leitura das cartas
    Carta c1 = lerCarta(1);
    Carta c2 = lerCarta(2);

    // Comparação
    compararCartas(c1, c2);

    return 0;
}
