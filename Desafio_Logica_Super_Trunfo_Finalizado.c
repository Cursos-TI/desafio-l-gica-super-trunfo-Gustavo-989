#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados das cidades
typedef struct {
    char estado[3];  // Código do estado (ex: SP, RJ)
    char codigo[5];  // Código da cidade (ex: A01, B02, ...)
    char nome[50];   // Nome da cidade
    int populacao;   // População da cidade
    float area;      // Área da cidade (em km²)
    float pib;       // PIB da cidade (em bilhões)
    int pontos_turisticos; // Número de pontos turísticos
    float densidade_populacional; // Densidade populacional (calculada)
    float pib_per_capita; // PIB per capita (calculado)
} Cidade;

// Função para cadastrar os dados da cidade
void cadastrarCidade(Cidade* cidade) {
    printf("Digite o código do estado (2 letras): ");
    scanf("%s", cidade->estado);

    printf("Digite o código da cidade (ex: A01, B02, ...): ");
    scanf("%s", cidade->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade->nome);  // Lê a linha inteira, incluindo espaços

    printf("Digite a população da cidade: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &cidade->pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Calculando as propriedades adicionais
    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib * 1000000000 / cidade->populacao;  // Convertendo PIB de bilhões para unidades
}

// Função para exibir os dados da cidade
void exibirCidade(Cidade cidade) {
    printf("\n--- Dados da Cidade ---\n");
    printf("Estado: %s\n", cidade.estado);
    printf("Código: %s\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("População: %d habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Pontos turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade populacional: %.2f habitantes por km²\n", cidade.densidade_populacional);
    printf("PIB per capita: R$ %.2f\n", cidade.pib_per_capita);
}

// Função para comparar dois atributos diferentes
void compararAtributos(Cidade cidade1, Cidade cidade2, int atributo1, int atributo2) {
    float valor1_1 = 0, valor1_2 = 0, valor2_1 = 0, valor2_2 = 0;

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1: // População
            valor1_1 = cidade1.populacao;
            valor2_1 = cidade2.populacao;
            break;
        case 2: // Área
            valor1_1 = cidade1.area;
            valor2_1 = cidade2.area;
            break;
        case 3: // PIB
            valor1_1 = cidade1.pib;
            valor2_1 = cidade2.pib;
            break;
        case 4: // Pontos turísticos
            valor1_1 = cidade1.pontos_turisticos;
            valor2_1 = cidade2.pontos_turisticos;
            break;
        case 5: // Densidade populacional
            valor1_1 = cidade1.densidade_populacional;
            valor2_1 = cidade2.densidade_populacional;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1: // População
            valor1_2 = cidade1.populacao;
            valor2_2 = cidade2.populacao;
            break;
        case 2: // Área
            valor1_2 = cidade1.area;
            valor2_2 = cidade2.area;
            break;
        case 3: // PIB
            valor1_2 = cidade1.pib;
            valor2_2 = cidade2.pib;
            break;
        case 4: // Pontos turísticos
            valor1_2 = cidade1.pontos_turisticos;
            valor2_2 = cidade2.pontos_turisticos;
            break;
        case 5: // Densidade populacional
            valor1_2 = cidade1.densidade_populacional;
            valor2_2 = cidade2.densidade_populacional;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Comparação dos atributos
    float soma1 = 0, soma2 = 0;
    int vencedor1 = 0, vencedor2 = 0;

    // Comparação do primeiro atributo
    if (atributo1 == 5) {
        // Densidade populacional vence com o menor valor
        if (valor1_1 < valor2_1) {
            vencedor1 = 1;
            soma1 += valor1_1;
        } else if (valor1_1 > valor2_1) {
            vencedor2 = 1;
            soma2 += valor2_1;
        } else {
            soma1 += valor1_1;
            soma2 += valor2_1;
        }
    } else {
        // Para os outros atributos, vence com o maior valor
        if (valor1_1 > valor2_1) {
            vencedor1 = 1;
            soma1 += valor1_1;
        } else if (valor1_1 < valor2_1) {
            vencedor2 = 1;
            soma2 += valor2_1;
        } else {
            soma1 += valor1_1;
            soma2 += valor2_1;
        }
    }

    // Comparação do segundo atributo
    if (atributo2 == 5) {
        // Densidade populacional vence com o menor valor
        if (valor1_2 < valor2_2) {
            vencedor1 = 1;
            soma1 += valor1_2;
        } else if (valor1_2 > valor2_2) {
            vencedor2 = 1;
            soma2 += valor2_2;
        } else {
            soma1 += valor1_2;
            soma2 += valor2_2;
        }
    } else {
        // Para os outros atributos, vence com o maior valor
        if (valor1_2 > valor2_2) {
            vencedor1 = 1;
            soma1 += valor1_2;
        } else if (valor1_2 < valor2_2) {
            vencedor2 = 1;
            soma2 += valor2_2;
        } else {
            soma1 += valor1_2;
            soma2 += valor2_2;
        }
    }

    // Exibindo o resultado
    printf("\nResultado da Comparação:\n");
    printf("Cidade 1 (%s) vs Cidade 2 (%s)\n", cidade1.nome, cidade2.nome);
    printf("Atributo 1: ");
    if (atributo1 == 1) printf("População\n");
    else if (atributo1 == 2) printf("Área\n");
    else if (atributo1 == 3) printf("PIB\n");
    else if (atributo1 == 4) printf("Pontos turísticos\n");
    else if (atributo1 == 5) printf("Densidade populacional\n");

    printf("Atributo 2: ");
    if (atributo2 == 1) printf("População\n");
    else if (atributo2 == 2) printf("Área\n");
    else if (atributo2 == 3) printf("PIB\n");
    else if (atributo2 == 4) printf("Pontos turísticos\n");
    else if (atributo2 == 5) printf("Densidade populacional\n");

    printf("\nSoma dos Atributos:\n");
    printf("Carta 1 (%s): %.2f\n", cidade1.nome, soma1);
    printf("Carta 2 (%s): %.2f\n", cidade2.nome, soma2);

    // Verificando o vencedor ou empate
    if (soma1 > soma2) {
        printf("\nResultado final: Carta 1 (%s) venceu!\n", cidade1.nome);
    } else if (soma1 < soma2) {
        printf("\nResultado final: Carta 2 (%s) venceu!\n", cidade2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

// Função de menu interativo
int menu() {
    Cidade cidade1, cidade2;
    int atributo1, atributo2;

    // Cadastro das duas cidades
    printf("Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);

    printf("\nCadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);

    // Escolha de atributos
    do {
        printf("\nEscolha o primeiro atributo (1 a 5):\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos turísticos\n");
        printf("5. Densidade populacional\n");
        scanf("%d", &atributo1);
    } while (atributo1 < 1 || atributo1 > 5);

    do {
        printf("\nEscolha o segundo atributo (1 a 5), diferente do primeiro:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos turísticos\n");
        printf("5. Densidade populacional\n");
        scanf("%d", &atributo2);
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Comparação dos atributos escolhidos
    compararAtributos(cidade1, cidade2, atributo1, atributo2);

    return 0;
}

int main() {
    menu();
    return 0;
}
