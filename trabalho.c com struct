#include <stdio.h>
#include <string.h>
#define MAX_NOME_ALIMENTO  20
#define MAX_ALIMENTOS 10

//colocar tudo o que esta pedindo do teclado em uma struct

typedef struct Alimento {
    char nome[MAX_NOME_ALIMENTO];
}Alimento;

typedef struct Estoque {
    Alimento alimentos[MAX_ALIMENTOS]; 
    int quantidades[MAX_ALIMENTOS];
}Estoque;


void adiciona_um_alimento(Estoque* estoque, int numAlimentos, char nomeAlimento, int quantidade){
    if(*numAlimentos == MAX_ALIMENTOS){
        return;
    }

    estoque->quantidades[*numAlimentos] = quantidade;
    strcpy(estoque->alimentos[*numAlimentos].nome, nomeAlimento);

    

    for (int i = 0; i <= *numAlimentos; i++) {
        printf("Quantidade de %s: %d\n", estoque->alimentos[i].nome, estoque->quantidades[i]);
    }
    (*numAlimentos)++;
    
    return ;
    
}

//funcao para atualizar o estoque
void atualizarEstoque(Estoque *estoque) {

    char nome_alimento[20];
    int estoque_alterado;

    printf("Digite o nome do alimento: ");
    scanf("%s", nome_alimento);
    printf("Escreva o estoque alterado: ");
    scanf("%d", &estoque_alterado);

    for (int i = 0; i < MAX_ALIMENTOS; i++) {
        if (strcmp(nome_alimento, estoque->alimentos[i].nome) == 0) { //compara o elemento da variavel e o elemento presente no vetor
            estoque->quantidades[i] = estoque_alterado;
            printf("Estoque atual de %s: %d\n", nome_alimento, estoque->quantidades[i]);
            return;
        }
    }
}

//funcao para verificar o estoque
void verificarEstoque(Estoque *estoque, int tamanho) {

    char nome_alimento[20];
    printf("Digite o nome do alimento a ser procurado: ");
    scanf("%s", nome_alimento);

    int quantidade_em_estoque = -1;

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(nome_alimento, estoque->alimentos[i].nome) == 0) { //compara o elemento da variavel e o elemento presente no vetor
            quantidade_em_estoque = estoque->quantidades[i];
            break;
        }
    }

    if (quantidade_em_estoque >= 0) {
        printf("Estoque de %s: %d\n", nome_alimento, quantidade_em_estoque);

    } else {
        printf("%s nao foi encontrado no estoque.\n", nome_alimento);
    }
}

//funcao para adicionar ao estoque
//void adicionar_alimento(char tipo_alimento[], char alimentos[4][20], int quantidades[], int *quantidade_atual) {
void adicionar_alimento(Estoque *estoque, int *numAlimentos) {
    char alimento_adicionado[20];
    printf("Digite o nome do alimento a ser adicionado: ");
    scanf("%s", alimento_adicionado);

    strcpy(estoque->alimentos[*numAlimentos-1].nome, alimento_adicionado);

    int quant_adicionada;
    printf("Digite a quantidade desse elemento: ");
    scanf("%d", &quant_adicionada);

    int novo_elemento[MAX_ALIMENTOS];

    if(*numAlimentos == MAX_ALIMENTOS){
        return;
    }
    estoque->quantidades[*numAlimentos] = quant_adicionada;
    

    for (int i = 0; i < MAX_ALIMENTOS; i++) {
        printf("Quantidade de %s: %d\n", estoque->alimentos[i].nome, novo_elemento[i]);
    }
    
    // atualizar as quantidades apenas se não ultrapassar o máximo
    (*numAlimentos)++;
    
}

int main(){
    
    int opcao = 0;
    
    Estoque estoqueCarboidratos,estoqueProteinas,estoqueLipideos;
    
    char carboidratos[3][20] = {"bolo", "pao", "biscoito"};
    int quant_carboidratos[3] = {10, 150, 120};
    int numCarboidratos = 0;
    
    adiciona_um_alimento(&estoqueCarboidratos,&numCarboidratos,carboidratos[0],quant_carboidratos[0]);
    adiciona_um_alimento(&estoqueCarboidratos,&numCarboidratos,carboidratos[1],quant_carboidratos[1]);
    adiciona_um_alimento(&estoqueCarboidratos,&numCarboidratos,carboidratos[2],quant_carboidratos[2]);
    

    char proteinas[4][20] = {"carne", "peixe", "ovo"};
    int quant_proteinas[4] = {90, 30, 200};
    int numProteinas = 0;
    adiciona_um_alimento(&estoqueProteinas,&numProteinas,proteinas[0],quant_proteinas[0]);
    adiciona_um_alimento(&estoqueProteinas,&numProteinas,proteinas[1],quant_proteinas[1]);
    adiciona_um_alimento(&estoqueProteinas,&numProteinas,proteinas[2],quant_proteinas[2]);
    

    char lipideos[3][20] = {"castanha", "oleo", "chocolate"};
    int quant_lipideos[3] = {30, 70, 50};
    int numLipideos = 0;
    adiciona_um_alimento(&estoqueLipideos,&numLipideos,lipideos[0],quant_lipideos[0]);
    adiciona_um_alimento(&estoqueLipideos,&numLipideos,lipideos[1],quant_lipideos[1]);
    adiciona_um_alimento(&estoqueLipideos,&numLipideos,lipideos[2],quant_lipideos[2]);

    while (1) {
        printf("Selecione uma opcao:\n [1] Alterar o estoque\n [2] Consultar o estoque\n [3] Adicionar ao estoque\n [0] Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;  //sai do loop se o usuário escolher 0
        }

        if(opcao == 1){

            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                atualizarEstoque(&estoqueCarboidratos);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                atualizarEstoque(&estoqueProteinas);
                
            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                atualizarEstoque(&estoqueLipideos);
            } else {
                printf("Tipo de alimento nao encontrado.\n");
            }


        }else if (opcao == 2){

            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                verificarEstoque(&estoqueCarboidratos,numCarboidratos);
                //verificarEstoque(tipo_alimento, carboidratos, quant_carboidratos, 4);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                verificarEstoque(&estoqueProteinas,numProteinas);

                //verificarEstoque(tipo_alimento, proteinas, quant_proteinas, 4);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                verificarEstoque(&estoqueLipideos,numLipideos);
                //verificarEstoque(tipo_alimento, lipideos, quant_lipideos, 4);

            } else {
                printf("Tipo de alimento nao encontrado.\n");
            }


        }else if(opcao == 3){

            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                adicionar_alimento(&estoqueCarboidratos,&numCarboidratos);
                //adicionar_alimento(tipo_alimento, carboidratos, quant_carboidratos, &quant_atual_carboidratos);

            } else if (strcmp(tipo_alimento, "proteina") == 0) {
                adicionar_alimento(&estoqueProteinas,&numProteinas);

                //adicionar_alimento(tipo_alimento, proteinas, quant_proteinas, &quant_atual_proteinas);

            } else if (strcmp(tipo_alimento, "lipideo") == 0) {
                adicionar_alimento(&estoqueLipideos,&numLipideos);
                //adicionar_alimento(tipo_alimento, lipideos, quant_lipideos, &quant_atual_lipideos);

            } else {
                printf("Tipo de alimento inválido.\n");
            }

        }else{
            printf("Opcao invalida");
        }
    }
    return 0;
}
