#include <stdio.h>
#include <string.h>

// Estrutura de Carta
typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

// Função para imprimir o menu de atributos
void imprimirMenu(int excluir) {
    printf("Escolha um atributo para comparar:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
    printf("Opção: ");
}

// Função que retorna o valor de um atributo da carta
float obterAtributo(Carta c, int atributo) {
    switch(atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"A", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    Carta carta2 = {"B", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Calculando atributos derivados
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int escolha1, escolha2;

    // Primeiro atributo
    imprimirMenu(0);
    scanf("%d", &escolha1);

    // Segundo atributo (menu dinâmico sem o primeiro escolhido)
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    imprimirMenu(escolha1);
    scanf("%d", &escolha2);

    // Obter valores para os dois atributos
    float valor1_c1 = obterAtributo(carta1, escolha1);
    float valor1_c2 = obterAtributo(carta2, escolha1);

    float valor2_c1 = obterAtributo(carta1, escolha2);
    float valor2_c2 = obterAtributo(carta2, escolha2);

    // Comparações individuais (com regra da densidade invertida)
    int resultado1 = (escolha1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0))
                                     : (valor1_c1 > valor1_c2 ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0));

    int resultado2 = (escolha2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0))
                                     : (valor2_c1 > valor2_c2 ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0));

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    int vencedorFinal = (soma_c1 > soma_c2) ? 1 : (soma_c1 < soma_c2 ? 2 : 0);

    // Exibição dos resultados
    printf("\n===== RESULTADO =====\n");
    printf("Carta 1 - %s (%s)\n", carta1.nomeCidade, carta1.estado);
    printf("Carta 2 - %s (%s)\n\n", carta2.nomeCidade, carta2.estado);

    printf("Atributo 1: %s\n", nomeAtributo(escolha1));
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor1_c1, carta2.nomeCidade, valor1_c2);
    printf("Vencedor do atributo 1: %s\n\n", resultado1 == 1 ? "Carta 1" : (resultado1 == 2 ? "Carta 2" : "Empate"));

    printf("Atributo 2: %s\n", nomeAtributo(escolha2));
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor2_c1, carta2.nomeCidade, valor2_c2);
    printf("Vencedor do atributo 2: %s\n\n", resultado2 == 1 ? "Carta 1" : (resultado2 == 2 ? "Carta 2" : "Empate"));

    printf("Soma dos Atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.nomeCidade, soma_c1, carta2.nomeCidade, soma_c2);

    if (vencedorFinal == 1) {
        printf("Resultado Final: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (vencedorFinal == 2) {
        printf("Resultado Final: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado Final: Empate!\n");
    }

    return 0;
}
