#include <stdio.h>
#include <string.h>
// Desafio Super Trunfo - Países
int main() {
    /* ====== Opções de comparação: altere aqui ======
   COMPARE_POPULACAO     -> comparar população (maior vence)
   COMPARE_AREA          -> comparar área (maior vence)
   COMPARE_PIB           -> comparar PIB em bilhões (maior vence)
   COMPARE_DENSIDADE     -> comparar densidade populacional (menor vence)
   COMPARE_PIB_PER_CAPITA-> comparar PIB per capita (maior vence)
*/
    #define COMPARE_POPULACAO      1
    #define COMPARE_AREA           2
    #define COMPARE_PIB            3
    #define COMPARE_DENSIDADE      4
    #define COMPARE_PIB_PER_CAPITA 5
    /* Escolha o atributo aqui (troque o valor se quiser comparar outro atributo) */
    #define COMPARE_ATTRIBUTE COMPARE_POPULACAO
    // Definição das variáveis para armazenar as propriedades das cidades
        /* --- Variáveis da Carta 1 --- */
    char estado1;
    char codigo1[4];          /* ex: "A01" - reservar 3 chars + terminador */
    char nomeCidade1[100];
    unsigned long int populacao1;
    float area1;
    float pib1;               /* em BILHÕES de reais */
    int pontosTuristicos1;
    float densidade1;         /* habitantes por km^2 */
    float pibPerCapita1;      /* em reais */

    /* --- Variáveis da Carta 2 --- */
    char estado2;
    char codigo2[4];
    char nomeCidade2[100];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;

    
    // Cadastro das Cartas:
    /* --- Entrada: Carta 1 --- */
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Código da Carta (Ex: A01): ");
    scanf(" %3s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %99[^\n]", nomeCidade1); /* lê linha com espaços (limita a 99 chars) */

    printf("Digite a População (numero inteiro): ");
    scanf("%lu", &populacao1);

    printf("Digite a Área em km² (ex: 1521.11): ");
    scanf("%f", &area1);

    printf("Digite o PIB em BILHÕES de reais (ex: 699.28): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    /* --- Entrada: Carta 2 --- */
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (Ex: B02): ");
    scanf(" %3s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %99[^\n]", nomeCidade2);

    printf("Digite a População (número inteiro): ");
    scanf("%lu", &populacao2);

    printf("Digite a Área em km² (ex: 1200.25): ");
    scanf("%f", &area2);

    printf("Digite o PIB em BILHÕES de reais (ex: 300.50): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

     /* --- Cálculos: densidade e PIB per capita --- */
    if (area1 > 0.0f) {
        densidade1 = (float)populacao1 / area1;
    } else {
        densidade1 = 0.0f; /* proteção contra divisão por zero */
        printf("\nAviso: Area da Carta 1 igual a zero. Densidade definida como 0.\n");
    }

    if (populacao1 > 0u) {
        pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    } else {
        pibPerCapita1 = 0.0f;
        printf("Aviso: Populacao da Carta 1 igual a zero. PIB per capita definido como 0.\n");
    }

    if (area2 > 0.0f) {
        densidade2 = (float)populacao2 / area2;
    } else {
        densidade2 = 0.0f;
        printf("Aviso: Area da Carta 2 igual a zero. Densidade definida como 0.\n");
    }

    if (populacao2 > 0u) {
        pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    } else {
        pibPerCapita2 = 0.0f;
        printf("Aviso: Populacao da Carta 2 igual a zero. PIB per capita definido como 0.\n");
    }

    /* --- Exibir as cartas (dados + calculados) --- */
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
/*
    // === Comparação: seleciona o atributo definido em COMPARE_ATTRIBUTE === 
    printf("\n=== Comparacao de cartas (atributo escolhido no codigo) ===\n");

    // População 
    if (COMPARE_ATTRIBUTE == COMPARE_POPULACAO) {
        printf("\nAtributo: Populacao\n");
        printf("Carta 1 - %s: %lu\n", nomeCidade1, populacao1);
        printf("Carta 2 - %s: %lu\n", nomeCidade2, populacao2);

        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (populacao1 < populacao2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    // Área 
    else if (COMPARE_ATTRIBUTE == COMPARE_AREA) {
        printf("\nAtributo: Area (km^2)\n");
        printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);

        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (area1 < area2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    // PIB (em bilhoes)
    else if (COMPARE_ATTRIBUTE == COMPARE_PIB) {
        printf("\nAtributo: PIB (bilhoes de reais)\n");
        printf("Carta 1 - %s: %.2f bilhoes\n", nomeCidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhoes\n", nomeCidade2, pib2);

        if (pib1 > pib2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (pib1 < pib2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    // Densidade populacional: menor valor vence 
    else if (COMPARE_ATTRIBUTE == COMPARE_DENSIDADE) {
        printf("\nAtributo: Densidade Populacional (hab/km^2) — MENOR vence\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidade1);
        printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidade2);

        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (densidade1 > densidade2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    // PIB per capita (em reais)
    else if (COMPARE_ATTRIBUTE == COMPARE_PIB_PER_CAPITA) {
        printf("\nAtributo: PIB per Capita (reais)\n");
        printf("Carta 1 - %s: %.2f reais\n", nomeCidade1, pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", nomeCidade2, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (pibPerCapita1 < pibPerCapita2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    // Caso a macro esteja com valor inválido
    else {
        printf("Erro: atributo de comparacao invalido. Verifique a macro COMPARE_ATTRIBUTE no codigo.\n");
    }
*/ 
        int opcao;

    printf("===== MENU SUPER TRUNFO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nComparação de cartas:\n");
    printf("Carta 1 - %s", nomeCidade1);
    printf("Carta 2 - %s: \n", nomeCidade2);

    switch(opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lu\n", nomeCidade1, populacao1);
            printf("%s: %lu\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 venceu!\n");
            } else if (populacao1 < populacao2) {
                printf("Resultado: Carta 2 venceu!\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);
            if (area1 > area2) {
                printf("Resultado: Carta 1 venceu!\n");
            } else if (area1 < area2) {
                printf("Resultado: Carta 2 venceu!\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", nomeCidade1, pib1);
            printf("%s: %.2f bilhões\n", nomeCidade2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: Carta 1 venceu!\n");
            } else if (pib1 < pib2) {
                printf("Resultado: Carta 2 venceu!\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d\n", nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: Carta 1 venceu!\n");
            } else if (pontosTuristicos1 < pontosTuristicos2) {
                printf("Resultado: Carta 2 venceu!\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (regra invertida)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);
            if (densidade1 < densidade2) {
                printf("Resultado: Carta 1 venceu!\n");
            } else if (densidade1 > densidade2) {
                printf("Resultado: Carta 2 venceu!\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // PIB per Capita
            printf("Atributo: PIB per Capita\n");
            printf("%s: %.2f reais\n", nomeCidade1, pibPerCapita1);
            printf("%s: %.2f reais\n", nomeCidade2, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2) {
                printf("Resultado: Carta 1 venceu!\n");
            } else if (pibPerCapita1 < pibPerCapita2) {
                printf("Resultado: Carta 2 venceu!\n");
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}