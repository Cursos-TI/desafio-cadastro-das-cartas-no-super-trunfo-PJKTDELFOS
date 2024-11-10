#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.


 typedef struct CartasSuperTrunfo
    {
        char codigo_carta[4];
        char estado[50];
        char cidade[50];
        struct atributos
        {
            double populacao;
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
        scanf(" %lf", &cartas[i].atributos.populacao);

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
            printf("Codigo da Carta %s\n",cartas[i].codigo_carta);
            printf("Estado %s\n",cartas[i].estado);
            printf("Cidade %s\n",cartas[i].cidade);
            printf("Populacao %.2f\n",cartas[i].atributos.populacao);
            printf("Area %.2f km^2 \n",cartas[i].atributos.area);
            printf("Pib %.2f\n",cartas[i].atributos.pib);
            printf("Pontos Turisticos %d\n\n",cartas[i].atributos.pontos_turisticos);

        }


    }

int main() {
    int numero_cartas=32;
    int max_num=4;

    CartasSuperTrunfo cartas[numero_cartas];

    gerador_cartas(cartas,numero_cartas,max_num);

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
// feito por Aluno: Albert Pimentel França  / Curso: Ciência da Computação/ Matricula 202405681304


