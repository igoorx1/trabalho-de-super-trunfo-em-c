#include <stdio.h>

// Definição da struct Carta
typedef struct {
    char estado[3];         // Ex: "SP"
    char codigo[4];         // Ex: "A01"
    char nome[50];          // Ex: "Sao Paulo"
    int populacao;          // População (int conforme enunciado)
    float area;             // Área
    float pib;              // PIB
    int pontos_turisticos;  // Pontos turísticos
    float densidade;        // Densidade populacional
    float pib_per_capita;   // PIB per capita
} Carta;

int main() {
    // Cadastro das cartas pré-definidas
    Carta c1 = {"SP", "A01", "Sao Paulo", 12300000, 1521.11f, 700000.0f, 10};
    Carta c2 = {"RJ", "B02", "Rio de Janeiro", 6700000, 1182.30f, 400000.0f, 8};

    // Calcular densidade populacional e PIB per capita
    c1.densidade = c1.populacao / c1.area;
    c1.pib_per_capita = c1.pib / c1.populacao;

    c2.densidade = c2.populacao / c2.area;
    c2.pib_per_capita = c2.pib / c2.populacao;

    // Escolha do atributo para comparação:
    // 1 = População, 2 = Área, 3 = PIB, 4 = Densidade Populacional, 5 = PIB per Capita
    int atributo = 1; // Escolha aqui o atributo para comparação

    float valor1, valor2;
    char nomeAtributo[30];

    // Definir qual atributo comparar
    if (atributo == 1) {
        valor1 = (float)c1.populacao;
        valor2 = (float)c2.populacao;
        sprintf(nomeAtributo, "População");
    } else if (atributo == 2) {
        valor1 = c1.area;
        valor2 = c2.area;
        sprintf(nomeAtributo, "Área");
    } else if (atributo == 3) {
        valor1 = c1.pib;
        valor2 = c2.pib;
        sprintf(nomeAtributo, "PIB");
    } else if (atributo == 4) {
        valor1 = c1.densidade;
        valor2 = c2.densidade;
        sprintf(nomeAtributo, "Densidade Populacional");
    } else if (atributo == 5) {
        valor1 = c1.pib_per_capita;
        valor2 = c2.pib_per_capita;
        sprintf(nomeAtributo, "PIB per Capita");
    } else {
        printf("Atributo inválido.\n");
        return 1;
    }

    // Exibir valores antes da comparação
    printf("Comparação de cartas (Atributo: %s)\n\n", nomeAtributo);

    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome, c2.estado, valor2);

    // Determinar a carta vencedora
    if (atributo == 4) {
        // Para densidade populacional: menor vence
        if (valor1 < valor2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", c1.nome);
        } else if (valor2 < valor1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", c2.nome);
        } else {
            printf("\nResultado: Empate!\n");
        }
    } else {
        // Para os outros atributos: maior vence
        if (valor1 > valor2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", c1.nome);
        } else if (valor2 > valor1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", c2.nome);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }

    return 0;
}

