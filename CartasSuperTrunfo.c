#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.


 typedef struct CartasSuperTrunfo
    {
        char codigo_carta[5];
        char estado[50];
        char cidade[50];
        struct atributos
        {
            int populacao;
            double area;
            double pib;
            int pontos_turisticos;
        } atributos;
    }CartasSuperTrunfo;

    void gerador_cartas(struct CartasSuperTrunfo cartas[],int numero_cartas,int max_num)
    {
        int index =0;
        for (char letra ='A'; letra <='H' && index < numero_cartas;letra++){
            for (int num=1;num <=max_num && index <numero_cartas;num++){
                snprintf(cartas[index].codigo_carta,5,"%c%02d",letra,num);
                index++;
            }

        }
    }

    void entrada_dados(CartasSuperTrunfo cartas[], int numero_cartas){
        printf("\n");
        printf("Registrando cartas:\n");
        printf("\n");

        for ( int i = 0; i< numero_cartas;i++){

        printf("Codigo da Carta %s\n",cartas[i].codigo_carta);

        printf("Digite o Estado: ");
        scanf(" %[^\n]", cartas[i].estado);

        printf("Digite a Cidade: ");
        scanf(" %[^\n]", cartas[i].cidade);

        printf("Digite a Populacao: ");
        scanf(" %d", &cartas[i].atributos.populacao);

        printf("Digite a Area (km^2): ");
        scanf("%lf", &cartas[i].atributos.area);

        printf("Digite o Pib: ");
        scanf("%lf", &cartas[i].atributos.pib);

        printf("Digite a quantidade de pontos turisticos: ");
        scanf("%d", &cartas[i].atributos.pontos_turisticos);
        printf("\n");

        }
    }

    void exibir_cartas (CartasSuperTrunfo cartas[],int numero_cartas){
        printf("\n");
        printf("Cartas cadastradas:\n");
        printf("\n");
        for (int i=0; i<numero_cartas;i++){
            printf("\n");
            printf("===================================================================\n");
            printf("\n");
            printf("Codigo da Carta %s\n",cartas[i].codigo_carta);
            printf("Estado %s\n",cartas[i].estado);
            printf("Cidade %s\n",cartas[i].cidade);
            printf("Populacao %d Habitantes\n",cartas[i].atributos.populacao);
            printf("Area %.2f km2 \n",cartas[i].atributos.area);
            printf("Pib %.2f bilhoes de Reais\n",cartas[i].atributos.pib );
            printf("Pontos Turisticos %d\n\n",cartas[i].atributos.pontos_turisticos);
            printf("\n");
            printf("===================================================================\n");
            printf("\n");

        }


    }


int main() {
        int numero_cartas;
        int estados;
        int cidades;


        printf("Digite a quantidade  de estados: ");
        scanf("%d", &estados);
        printf("\n");

        printf("Digite  a quantidade de Cidades: ");
        scanf("%d", &cidades);
        printf("\n");
        numero_cartas=estados*cidades;

        if( estados ==1 &&  cidades==1){
            printf("Sera criada %d carta \n\n",numero_cartas);
        } else{
            printf("Serao criadas %d cartas \n\n",numero_cartas);
        }



    CartasSuperTrunfo cartas[numero_cartas];

    gerador_cartas(cartas,numero_cartas,cidades);

    entrada_dados(cartas,numero_cartas);

    exibir_cartas(cartas,numero_cartas);

    return 0;

}

// Sugestão: Defina variáveis separadas para cada atributo da cidade.
// Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
// Cadastro das Cartas:
// Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
// Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
// Exibição dos Dados das Cartas:
// Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
// Exiba os valores inseridos para cada atributo da cidade, um por linha.
//LEMBRAR QUE  E PRA USAR ASPAS DUPLAS SEMPRE(" ")

// documentação

// nesta etapa, os dados inicias como população, area,pib, e pontos turisticos foram inseridas, e o programa gera automaticamente o codigo da carta, para evitar cartas duplicadas.
//basta ao usuario indicar quantos estados, e quantas cidades de cada estado, o programa que o programa irá calcular o total de cartas e fara os codigos de cada carta automaticamente
//quando inserir informaçoes como pib, area, usar para os decimais .(ponto) e não ,(virgula)
// cuidado aonde poe as variaveis, fora da ordem pode dar estouro de pilha, e mais facil por na ordem certa que fazer uma função de alocação dinamica de memoria


// feito por Aluno: Albert Pimentel França  / Curso: Ciência da Computação/ Matricula 202405681304


