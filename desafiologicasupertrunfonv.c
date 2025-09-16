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

int main() {
    // Cadastro pré-definido das cartas
    Carta c1 = {"BR", "A01", "Brasil", 213000000, 8515767.0f, 1900000.0f, 15};
    Carta c2 = {"AR", "B02", "Argentina", 45376763, 2780400.0f, 500000.0f, 10};

    // Cálculos automáticos
    c1.densidade = c1.populacao / c1.area;
    c1.pib_per_capita = c1.pib / c1.populacao;

    c2.densidade = c2.populacao / c2.area;
    c2.pib_per_capita = c2.pib / c2.populacao;

    int opcao;
    float valor1 = 0, valor2 = 0;
    char nomeAtributo[40];

    printf("===== SUPER TRUNFO - MENU DE COMPARACAO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Sua opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: // População
            valor1 = (float)c1.populacao;
            valor2 = (float)c2.populacao;
            strcpy(nomeAtributo, "Populacao");
            break;

        case 2: // Área
            valor1 = c1.area;
            valor2 = c2.area;
            strcpy(nomeAtributo, "Area");
            break;

        case 3: // PIB
            valor1 = c1.pib;
            valor2 = c2.pib;
            strcpy(nomeAtributo, "PIB");
            break;

        case 4: // Pontos Turísticos
            valor1 = (float)c1.pontos_turisticos;
            valor2 = (float)c2.pontos_turisticos;
            strcpy(nomeAtributo, "Pontos Turisticos");
            break;

        case 5: // Densidade Demográfica
            valor1 = c1.densidade;
            valor2 = c2.densidade;
            strcpy(nomeAtributo, "Densidade Demografica");
            break;

        default:
            printf("Opcao invalida!\n");
            return 1;
    }

    // Exibir valores
    printf("\nComparacao de Cartas (Atributo: %s)\n\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome, c2.estado, valor2);

    // If-else aninhados para determinar vencedor
    if (opcao == 5) {
        // Para Densidade Demográfica: menor vence
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
