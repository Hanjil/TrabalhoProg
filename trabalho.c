#include <stdio.h>
#include <string.h>
//colocar toda parte dos alimentos em uma struct 

//atualiza o estoque
void atualizarEstoque(int estoque[], char alimentos[][20], const char tipo_alimento[]) {
    char nome_alimento[20];

    printf("Digite o nome do alimento: ");
    scanf("%s", nome_alimento);

    int estoque_alterado;
    printf("Escreva o estoque alterado: ");
    scanf("%d", &estoque_alterado);

    for (int i = 0; i < 3; i++) {
        if (strcmp(nome_alimento, alimentos[i]) == 0) {
            estoque[i] = estoque_alterado;
            printf("Estoque atual de %s: %d\n", nome_alimento, estoque[i]);
            return;
        }
    }
}

//verifica a quantidade de determinado elemento no estoque
void verificarEstoque(const char tipo_alimento[], char alimentos[][20], int quantidades[], int tamanho) {
    char nome_alimento[20];
    printf("Digite o nome do alimento: ");
    scanf("%s", nome_alimento);

    int quantidade_em_estoque = -1;

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(nome_alimento, alimentos[i]) == 0) {
            quantidade_em_estoque = quantidades[i];
            break;
        }
    }

    if (quantidade_em_estoque >= 0) {
        printf("Estoque de %s: %d\n", nome_alimento, quantidade_em_estoque);

    } else {
        printf("%s nao foi encontrado no estoque.\n", nome_alimento);
    }
}

//adiciona alimento no estoque
void adicionar_alimento(char tipo_alimento[], char alimentos[4][20], int quantidades[], int *quantidade_atual) {
    char alimento_adicionado[20];
    printf("Digite o nome do alimento a ser adicionado: ");
    scanf("%s", alimento_adicionado);

    strcpy(alimentos[3], alimento_adicionado);

    int quant_adicionada;
    printf("Digite a quantidade desse elemento: ");
    scanf("%d", &quant_adicionada);

    int novo_elemento[4];

    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            novo_elemento[i] = quantidades[i];
        }else{
            novo_elemento[i] = quant_adicionada;
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("Quantidade de %s: %d\n", alimentos[i], novo_elemento[i]);
    }
    
    // atualiza as quantidades apenas se não ultrapassar o máximo
    if (*quantidade_atual < 4) {
        (*quantidade_atual)++;
    }
}

int main(){
    int opcao = 0;
    
    char carboidratos[3][20] = {"bolo", "pao", "biscoito"};
    int quant_carboidratos[3] = {10, 150, 120};

    char proteinas[4][20] = {"carne", "peixe", "ovo"};
    int quant_proteinas[4] = {90, 30, 200};

    char lipideos[3][20] = {"castanha", "oleo", "chocolate"};
    int quant_lipideos[3] = {30, 70, 50};

    while (1) {
        printf("Selecione uma opcao:\n [1] Alterar o estoque\n [2] Consultar o estoque\n [3] Adicionar ao estoque\n [0] Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;  //Sai do loop se o usuário escolher 0
        }

        if(opcao == 1){
            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                atualizarEstoque(quant_carboidratos, carboidratos, tipo_alimento);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                atualizarEstoque(quant_proteinas, proteinas, tipo_alimento);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                atualizarEstoque(quant_lipideos, lipideos, tipo_alimento);

            } else {
                printf("Tipo de alimento nao encontrado.\n");
            }


        }else if (opcao == 2){
            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                verificarEstoque(tipo_alimento, quant_carboidratos, quant_carboidratos, 4);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                verificarEstoque(tipo_alimento, quant_proteinas, quant_proteinas, 4);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                verificarEstoque(tipo_alimento, lipideos, quant_lipideos, 4);

            } else {
                printf("Tipo de alimento nao encontrado.\n");
            }


        }else if(opcao == 3){
            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            int quant_atual_carboidratos;
            int quant_atual_proteinas;
            int quant_atual_lipideos;

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                adicionar_alimento(tipo_alimento, carboidratos, quant_carboidratos, &quant_atual_carboidratos);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                adicionar_alimento(tipo_alimento, proteinas, quant_proteinas, &quant_atual_proteinas);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                adicionar_alimento(tipo_alimento, lipideos, quant_lipideos, &quant_atual_lipideos);

            } else {
                printf("Tipo de alimento nao encontrado.\n");
            }

        }else{
            printf("Opcao invalida");
        }
    }
    return 0;
}
