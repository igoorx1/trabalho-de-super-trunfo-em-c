#include <stdio.h>
#include <string.h>

// Definição da struct Carta
typedef struct {
    char estado[3];
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;       // População / Área
    float pib_per_capita;  // PIB / População
} Carta;

// Função auxiliar para pegar o valor do atributo escolhido
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        case 6: return c.pib_per_capita;
        default: return 0;
    }
}

// Função auxiliar para retornar o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta c1 = {"BR", "A01", "Brasil", 213000000, 8515767.0f, 1900000.0f, 15};
    Carta c2 = {"AR", "B02", "Argentina", 45376763, 2780400.0f, 500000.0f, 10};

    // Cálculos automáticos
    c1.densidade = c1.populacao / c1.area;
    c1.pib_per_capita = c1.pib / c1.populacao;

    c2.densidade = c2.populacao / c2.area;
    c2.pib_per_capita = c2.pib / c2.populacao;

    int atributo1, atributo2;

    // Primeiro menu
    printf("===== SUPER TRUNFO - DESAFIO FINAL =====\n\n");
    printf("Escolha o primeiro atributo:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Sua opcao: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 6) {
        printf("Opcao invalida!\n");
        return 1;
    }

    // Segundo menu (dinâmico)
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Sua opcao: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
        printf("Opcao invalida!\n");
        return 1;
    }

    // Valores dos atributos para cada carta
    float valor1A = obterValorAtributo(c1, atributo1);
    float valor2A = obterValorAtributo(c2, atributo1);
    float valor1B = obterValorAtributo(c1, atributo2);
    float valor2B = obterValorAtributo(c2, atributo2);

    // Comparação atributo 1
    int resultadoA;
    if (atributo1 == 5) {
        resultadoA = (valor1A < valor2A) ? 1 : (valor2A < valor1A) ? 2 : 0;
    } else {
        resultadoA = (valor1A > valor2A) ? 1 : (valor2A > valor1A) ? 2 : 0;
    }

    // Comparação atributo 2
    int resultadoB;
    if (atributo2 == 5) {
        resultadoB = (valor1B < valor2B) ? 1 : (valor2B < valor1B) ? 2 : 0;
    } else {
        resultadoB = (valor1B > valor2B) ? 1 : (valor2B > valor1B) ? 2 : 0;
    }

    // Soma dos atributos
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    // Determinar vencedor final pela soma
    int vencedorFinal = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;

    // Exibição dos resultados
    printf("\n===== RESULTADOS =====\n");
    printf("Carta 1: %s (%s)\n", c1.nome, c1.estado);
    printf("Carta 2: %s (%s)\n\n", c2.nome, c2.estado);

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("Carta 1: %.2f | Carta 2: %.2f\n", valor1A, valor2A);
    printf("Vencedor atributo 1: %s\n\n", resultadoA == 1 ? c1.nome : resultadoA == 2 ? c2.nome : "Empate");

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("Carta 1: %.2f | Carta 2: %.2f\n", valor1B, valor2B);
    printf("Vencedor atributo 2: %s\n\n", resultadoB == 1 ? c1.nome : resultadoB == 2 ? c2.nome : "Empate");

    printf("Soma dos atributos:\n");
    printf("Carta 1: %.2f | Carta 2: %.2f\n", soma1, soma2);

    // Resultado final
    if (vencedorFinal == 1) {
        printf("\nResultado Final: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (vencedorFinal == 2) {
        printf("\nResultado Final: Carta 2 (%s) venceu!\n", c2.nome);
    } else {
        printf("\nResultado Final: Empate!\n");
    }

    return 0;
}
