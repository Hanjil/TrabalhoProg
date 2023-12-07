#include <stdio.h>
#include <string.h>

typedef struct {
    char nome_alimento[30];
} NomeAlimento;

// Função para atualizar o estoque
void atualizarEstoque(int estoque[], NomeAlimento alimentos[]) {
    NomeAlimento nome_alimento;

    printf("Digite o nome do alimento: ");
    scanf("%s", nome_alimento.nome_alimento);

    int estoque_alterado;
    printf("Escreva o estoque alterado: ");
    scanf("%d", &estoque_alterado);

    for (int i = 0; i < 3; i++) {
        if (strcmp(nome_alimento.nome_alimento, alimentos[i].nome_alimento) == 0) {
            estoque[i] = estoque_alterado;
            printf("Estoque atual de %s: %d\n", nome_alimento.nome_alimento, estoque[i]);
            return;
        }
    }
}

// Função para verificar o estoque
void verificarEstoque(NomeAlimento alimentos[], int quantidades[], int tamanho) {
    NomeAlimento nome_alimento;
    printf("Digite o nome do alimento a ser procurado: ");
    scanf("%s", nome_alimento.nome_alimento);

    int quantidade_em_estoque = -1;

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(nome_alimento.nome_alimento, alimentos[i].nome_alimento) == 0) {
            quantidade_em_estoque = quantidades[i];
            break;
        }
    }

    if (quantidade_em_estoque >= 0) {
        printf("Estoque de %s: %d\n", nome_alimento.nome_alimento, quantidade_em_estoque);
    } else {
        printf("%s nao foi encontrado no estoque.\n", nome_alimento.nome_alimento);
    }
}

// Função para adicionar ao estoque
void adicionar_alimento(NomeAlimento alimentos[], int quantidades[], int *quantidade_atual) {
    NomeAlimento alimento_adicionado;
    printf("Digite o nome do alimento a ser adicionado: ");
    scanf("%s", alimento_adicionado.nome_alimento);

    strcpy(alimentos[3].nome_alimento, alimento_adicionado.nome_alimento);

    int quant_adicionada;
    printf("Digite a quantidade desse elemento: ");
    scanf("%d", &quant_adicionada);

    int novo_elemento[4];

    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            novo_elemento[i] = quantidades[i];
        } else {
            novo_elemento[i] = quant_adicionada;
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("Quantidade de %s: %d\n", alimentos[i].nome_alimento, novo_elemento[i]);
    }

    // Atualizar as quantidades apenas se não ultrapassar o máximo
    if (*quantidade_atual < 4) {
        (*quantidade_atual)++;
    }
}

void LerDados(NomeAlimento carboidratos[], int quant_carboidratos[],
              NomeAlimento proteinas[], int quant_proteinas[],
              NomeAlimento lipideos[], int quant_lipideos[])
{
    FILE *LerArquivo;

    if ((LerArquivo = fopen("Estoque.txt", "r")) == NULL)
    {
        printf("Erro na leitura do estoque.");
        return;
    }

    // Ler carboidratos
    fscanf(LerArquivo, "%s %s %s", carboidratos[0].nome_alimento, carboidratos[1].nome_alimento, carboidratos[2].nome_alimento);
    fscanf(LerArquivo, "%d %d %d", &quant_carboidratos[0], &quant_carboidratos[1], &quant_carboidratos[2]);

    // Ler proteinas
    fscanf(LerArquivo, "%s %s %s", proteinas[0].nome_alimento, proteinas[1].nome_alimento, proteinas[2].nome_alimento);
    fscanf(LerArquivo, "%d %d %d", &quant_proteinas[0], &quant_proteinas[1], &quant_proteinas[2]);

    // Ler lipideos
    fscanf(LerArquivo, "%s %s %s", lipideos[0].nome_alimento, lipideos[1].nome_alimento, lipideos[2].nome_alimento);
    fscanf(LerArquivo, "%d %d %d", &quant_lipideos[0], &quant_lipideos[1], &quant_lipideos[2]);

    fclose(LerArquivo);
}

void SalvarDados(NomeAlimento carboidratos[], int quant_carboidratos[],
                 NomeAlimento proteinas[], int quant_proteinas[],
                 NomeAlimento lipideos[], int quant_lipideos[])
{
    FILE *SalvarArquivo;

    if ((SalvarArquivo = fopen("Estoque.txt", "w")) == NULL)
    {
        printf("Erro no salvamento do estoque.");
        return;
    }

    fprintf(SalvarArquivo, "%s %s %s\n", carboidratos[0], carboidratos[1], carboidratos[2]);
    fprintf(SalvarArquivo, "%d %d %d\n", quant_carboidratos[0], quant_carboidratos[1], quant_carboidratos[2]);
    fprintf(SalvarArquivo, "%s %s %s\n", proteinas[0], proteinas[1], proteinas[2]);
    fprintf(SalvarArquivo, "%d %d %d\n", quant_proteinas[0], quant_proteinas[1], quant_proteinas[2]);
    fprintf(SalvarArquivo, "%s %s %s\n", lipideos[0], lipideos[1], lipideos[2]);
    fprintf(SalvarArquivo, "%d %d %d\n", quant_lipideos[0], quant_lipideos[1], quant_lipideos[2]);

    fclose(SalvarArquivo);
}

int main() {
    int opcao = 0;

    /*
    // Arrays of structs
    NomeAlimento carboidratos[3] = {{"bolo"}, {"pao"}, {"biscoito"}};
    int quant_carboidratos[3] = {10, 150, 120};

    NomeAlimento proteinas[4] = {{"carne"}, {"peixe"}, {"ovo"}};
    int quant_proteinas[4] = {90, 30, 200};

    NomeAlimento lipideos[3] = {{"castanha"}, {"oleo"}, {"chocolate"}};
    int quant_lipideos[3] = {30, 70, 50};
    */

    NomeAlimento carboidratos[3];
    int quant_carboidratos[3];
    NomeAlimento proteinas[3];
    int quant_proteinas[3];
    NomeAlimento lipideos[3];
    int quant_lipideos[3];

    LerDados(carboidratos, quant_carboidratos, proteinas, quant_proteinas, lipideos, quant_lipideos);

    while (1) {
        printf("Selecione uma opcao:\n [1] Alterar o estoque\n [2] Consultar o estoque\n [3] Adicionar ao estoque\n [0] Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break; // Sai do loop se o usuário escolher 0
        }

        if (opcao == 1) {
            char tipo_alimento[20];
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                atualizarEstoque(quant_carboidratos, carboidratos);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                atualizarEstoque(quant_proteinas, proteinas);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                atualizarEstoque(quant_lipideos, lipideos);

            } else {
                printf("Tipo de alimento nao encontrado.\n");
            }

        } else if (opcao == 2) {
            char tipo_alimento[20];
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                verificarEstoque(carboidratos, quant_carboidratos, 4);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                verificarEstoque(proteinas, quant_proteinas, 4);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                verificarEstoque(lipideos, quant_lipideos, 4);

            } else {
                printf("Tipo de alimento nao encontrado.\n");
            }

        } else if (opcao == 3) {
            char tipo_alimento[20];
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            int quant_atual_carboidratos;
            int quant_atual_proteinas;
            int quant_atual_lipideos;

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                adicionar_alimento(carboidratos, quant_carboidratos, &quant_atual_carboidratos);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                adicionar_alimento(proteinas, quant_proteinas, &quant_atual_proteinas);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                adicionar_alimento(lipideos, quant_lipideos, &quant_atual_lipideos);

            } else {
                printf("Tipo de alimento inválido.\n");
            }

        } else {
            printf("Opcao invalida\n");
        }

        SalvarDados(carboidratos, quant_carboidratos, proteinas, quant_proteinas, lipideos, quant_lipideos);
    }
    return 0;
}