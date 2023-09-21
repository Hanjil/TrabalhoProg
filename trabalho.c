#include <stdio.h>
#include <string.h>

int main() {

    int opcao = 0;
    printf("Digite 1 para alterar o estoque ou 2 para consultar o estoque: ");
    scanf("%d", &opcao);
    
    int a = 10, b = 150, c = 120; // as variaveis foram adicionadas assim para que seu valor possa ser mudado depois
    char carboidratos[3][20] = {"bolo", "pao", "biscoito"};
    int quant_carboidratos[3] = {a, b, c};

    int d = 90, e = 30, f = 200, g = 250;
    char proteinas[4][20] = {"carne", "peixe", "ovo", "laticineos"};
    int quant_proteinas[4] = {d, e, f, g};

    int h = 30, k = 70, l = 50;
    char lipideos[3][20] = {"castanha", "oleo", "chocolate"};
    int quant_lipideos[3] = {h, k, l};

        if(opcao == 1){

            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) { //a função confere se o que foi escrito bate com o tipo de alimento
                
                char nome_alimento[20];
                printf("Digite o nome do alimento(pao, bolo, biscoito): ");
                scanf("%s", nome_alimento);

                int estoque_atual;
                printf("Escreva o estoque alterado: ");
                scanf("%d", &estoque_atual);

                for (int i = 0; i < 3; i++) {
                    if (strcmp(nome_alimento, carboidratos[i]) == 0) { // comparar o nome_alimento com o elemento na posição i da matriz carboidratos
                        quant_carboidratos[i] = estoque_atual;
                        printf("estoque atual: %d", quant_carboidratos[i]);
                        break;
                    }
                }
                
            }else if (strcmp(tipo_alimento, "proteina") == 0) {
                
                char nome_alimento[20];
                printf("Digite o nome do alimento(carne, laticineos, ovo, peixe): ");
                scanf("%s", nome_alimento);

                int estoque_atual;
                printf("Escreva o estoque alterado: ");
                scanf("%d", &estoque_atual);

                for (int i = 0; i < 3; i++) {
                    if (strcmp(nome_alimento, proteinas[i]) == 0) {
                        quant_proteinas[i] = estoque_atual;
                        printf("estoque atual: %d", quant_proteinas[i]);
                        break;
                    }
                }
                
            }else if(strcmp(tipo_alimento, "lipideo") == 0) {
                
                char nome_alimento[20];
                printf("Digite o nome do alimento(oleo, castanha, chocolate): ");
                scanf("%s", nome_alimento);

                int estoque_atual;
                printf("Escreva o estoque alterado: ");
                scanf("%d", &estoque_atual);

                for (int i = 0; i < 3; i++) {
                    if (strcmp(nome_alimento, lipideos[i]) == 0) {
                        quant_lipideos[i] = estoque_atual;
                        printf("estoque atual: %d", quant_lipideos[i]);
                        break;
                    }
                }
                
            }

        }else if (opcao == 2){

            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if (strcmp(tipo_alimento, "carboidrato") == 0) {
                
                char nome_alimento[20];
                printf("Digite o nome do alimento(pao, bolo, biscoito): ");
                scanf("%s", nome_alimento);

                int quantidade_em_estoque = -1;

                for (int i = 0; i < 3; i++) {
                    if (strcmp(nome_alimento, carboidratos[i]) == 0) {
                        quantidade_em_estoque = quant_carboidratos[i];
                        break;
                    }
                }

                if (quantidade_em_estoque >= 0) {
                    printf("Estoque de %s: %d\n", nome_alimento, quantidade_em_estoque);
                } else {
                    printf("%s nao foi encontrado no estoque.\n", nome_alimento);
                }


            }else if(strcmp(tipo_alimento, "proteina") == 0) {
                
                char nome_alimento[20];
                printf("Digite o nome do alimento(carne, laticineos, ovo, peixe): ");
                scanf("%s", nome_alimento);

                int quantidade_em_estoque = -1;

                for (int i = 0; i < 4; i++) {
                    if (strcmp(nome_alimento, proteinas[i]) == 0) {
                        quantidade_em_estoque = quant_proteinas[i];
                        break;
                    }
                }

                if (quantidade_em_estoque >= 0) {
                    printf("Estoque de %s: %d\n", nome_alimento, quantidade_em_estoque);
                }else {
                    printf("%s nao foi encontrado no estoque.\n", nome_alimento);
                }


            }else if(strcmp(tipo_alimento, "lipideo") == 0) {
                
                char nome_alimento[20];
                printf("Digite o nome do alimento(oleo, castanha, chocolate): ");
                scanf("%s", nome_alimento);

                int quantidade_em_estoque = -1;

                for (int i = 0; i < 3; i++) {
                    if (strcmp(nome_alimento, lipideos[i]) == 0) {
                        quantidade_em_estoque = quant_lipideos[i];
                        break;
                    }
                }

                if (quantidade_em_estoque >= 0) {
                    printf("Estoque de %s: %d\n", nome_alimento, quantidade_em_estoque);
                }else {
                    printf("%s nao foi encontrado no estoque.\n", nome_alimento);
                }


            }else{
                printf("Tipo de alimento nao encontrado");

            }

        }else if(opcao == 3){

            char tipo_alimento[20];  
            printf("Digite o tipo de alimento (carboidrato, proteina, lipideo): ");
            scanf("%s", tipo_alimento);

            if(strcmp(tipo_alimento, "carboidrato") == 0) {

                char alimento_adicionado[20];
                printf("Digite o nome do alimento a ser adicionado: ");
                scanf("%s", &alimento_adicionado);
                
                strcpy(carboidratos[3], alimento_adicionado); //função usada para adicionar um elemento na matriz de strings

                int quant_adicionada;
                printf("Digite a quantidade desse elemento: ");
                scanf("%d", &quant_adicionada);
                
                int carboidratos_novo_elemento[4];

                for(int i = 0; i < 4; i++){ //looping para adicionar um elemento no vetor
                    if (i < 3){
                    carboidratos_novo_elemento[i] = quant_carboidratos[i];
                    }else{
                        carboidratos_novo_elemento[i] = quant_adicionada;
                    }
                }
            
                for(int i = 0; i < 4; i++){
                    printf("Quantidade de %s: %d\n", carboidratos[i], carboidratos_novo_elemento[i]);
                }

            }else if(strcmp(tipo_alimento, "proteina") == 0) {

                char alimento_adicionado[20];
                printf("Digite o nome do alimento a ser adicionado: ");
                scanf("%s", &alimento_adicionado);
                
                strcpy(proteinas[3], alimento_adicionado); //função usada para adicionar um elemento na matriz de strings

                int quant_adicionada;
                printf("Digite a quantidade desse elemento: ");
                scanf("%d", &quant_adicionada);
                
                int proteinas_novo_elemento[4];

                for(int i = 0; i < 4; i++){ //looping para adicionar um elemento no vetor
                    if (i < 3){
                    proteinas_novo_elemento[i] = quant_proteinas[i];
                    }else{
                        proteinas_novo_elemento[i] = quant_adicionada;
                    }
                }
            
                for(int i = 0; i < 4; i++){
                    printf("Quantidade de %s: %d\n", proteinas[i], proteinas_novo_elemento[i]);
                }
            }else if(strcmp(tipo_alimento, "lipideo") == 0) {

                char alimento_adicionado[20];
                printf("Digite o nome do alimento a ser adicionado: ");
                scanf("%s", &alimento_adicionado);
                
                strcpy(lipideos[3], alimento_adicionado); //função usada para adicionar um elemento na matriz de strings

                int quant_adicionada;
                printf("Digite a quantidade desse elemento: ");
                scanf("%d", &quant_adicionada);
                
                int lipideos_novo_elemento[4];

                for(int i = 0; i < 4; i++){ //looping para adicionar um elemento no vetor
                    if (i < 3){
                    lipideos_novo_elemento[i] = quant_lipideos[i];
                    }else{
                        lipideos_novo_elemento[i] = quant_adicionada;
                    }
                }
            
                for(int i = 0; i < 4; i++){
                    printf("Quantidade de %s: %d\n", lipideos[i], lipideos_novo_elemento[i]);
                }
            }

        }else{
            printf("Opcao invalida");
        }

    return 0;
}