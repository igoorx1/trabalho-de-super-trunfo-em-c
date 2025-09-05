#include <stdio.h>

typedef struct {
    char estado[3];             // array de chars (ex: "SP")
    char codigo[4];             // array de chars (ex: "A01")
    char nome[50];              // array de chars (ex: "Sao Paulo")
    unsigned long populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

float densidadePopulacional(Carta c) {
    return c.populacao / c.area;
}

float pibPerCapita(Carta c) {
    return c.pib / c.populacao;
}

void mostrarCarta(Carta c) {
    printf("Carta %s - %s (%s)\n", c.codigo, c.nome, c.estado);
    printf("Populacao: %lu\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Pop: %.2f hab/km²\n", densidadePopulacional(c));
    printf("PIB per Capita: %.2f\n\n", pibPerCapita(c));
}

int main() {
    Carta c1 = {"SP", "A01", "Sao Paulo", 12300000, 1521.11f, 700000.0f, 10};
    Carta c2 = {"RJ", "B02", "Rio de Janeiro", 6700000, 1182.30f, 400000.0f, 8};

    mostrarCarta(c1);
    mostrarCarta(c2);

    int atributo = 1; // Aqui você pode mudar para 1,2,3,4 ou 5
    float valor1, valor2;

    switch (atributo) {
        case 1:
            valor1 = (float)c1.populacao; 
            valor2 = (float)c2.populacao;
            break;
        case 2:
            valor1 = c1.area; 
            valor2 = c2.area;
            break;
        case 3:
            valor1 = c1.pib; 
            valor2 = c2.pib;
            break;
        case 4:
            valor1 = densidadePopulacional(c1); 
            valor2 = densidadePopulacional(c2);
            break;
        case 5:
            valor1 = pibPerCapita(c1); 
            valor2 = pibPerCapita(c2);
            break;
        default:
            printf("Atributo invalido.\n");
            return 1;
    }

    printf("Comparando atributo %d:\n", atributo);

    if (atributo == 4) { // Densidade Populacional: menor vence
        if (valor1 < valor2) printf("%s vence!\n", c1.nome);
        else if (valor2 < valor1) printf("%s vence!\n", c2.nome);
        else printf("Empate!\n");
    } else { // Maior valor vence
        if (valor1 > valor2) printf("%s vence!\n", c1.nome);
        else if (valor2 > valor1) printf("%s vence!\n", c2.nome);
        else printf("Empate!\n");
    }

    return 0;
}

