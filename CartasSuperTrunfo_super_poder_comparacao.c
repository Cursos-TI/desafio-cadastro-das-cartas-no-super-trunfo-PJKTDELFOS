 #include <stdio.h>
 #include <string.h>

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
            double densidade_populacional;
            double pib_per_capta;
            double super_poder;
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
        scanf(" %[^\n]", &cartas[i].cidade);

        printf("Digite a Populacao: ");
        scanf(" %d", &cartas[i].atributos.populacao);

        printf("Digite a Area (km^2): ");
        scanf("%lf", &cartas[i].atributos.area);

        printf("Digite o Pib: ");
        scanf("%lf", &cartas[i].atributos.pib);

        printf("Digite a quantidade de pontos turisticos: ");
        scanf("%d", &cartas[i].atributos.pontos_turisticos);
        printf("\n");



        if(cartas[i].atributos.area!=0 && cartas[i].atributos.populacao!=0)
        {
            cartas[i].atributos.densidade_populacional=(double)cartas[i].atributos.populacao/cartas[i].atributos.area;
        }
        else
        {
            cartas[i].atributos.densidade_populacional=0;
        }


         if(cartas[i].atributos.populacao!=0 && cartas[i].atributos.pib!=0)
        {
            cartas[i].atributos.pib_per_capta=cartas[i].atributos.pib/cartas[i].atributos.populacao;
        }
        else
        {
            cartas[i].atributos.pib_per_capta=0;
        }

        cartas[i].atributos.super_poder=cartas[i].atributos.area+cartas[i].atributos.pib+
        cartas[i].atributos.populacao+cartas[i].atributos.pontos_turisticos+
        cartas[i].atributos.densidade_populacional+cartas[i].atributos.pib_per_capta;

        }


    }

    void exibir_cartas(CartasSuperTrunfo *carta, int numero_cartas){
        for (int i=0; i<numero_cartas;i++){
            printf("\n");
            printf("===================================================================\n");
            printf("\n");
            printf("Codigo da Carta %s\n",carta[i].codigo_carta);
            printf("Estado %s\n",carta[i].estado);
            printf("Cidade %s\n",carta[i].cidade);
            printf("Populacao %d Habitantes\n",carta[i].atributos.populacao);
            printf("Area %.2f km2 \n",carta[i].atributos.area);
            printf("Pib %.2f bilhoes de Reais\n",carta[i].atributos.pib );
            printf("Pontos Turisticos %d\n\n",carta[i].atributos.pontos_turisticos);
            printf("Densidade Populacional %.2f  habitantes /km2 \n",carta[i].atributos.densidade_populacional);
            printf("Pib per capta %.2f Mil reais por pessoa\n",carta[i].atributos.pib_per_capta );
            printf("Super Poder %.2f Pontos\n",carta[i].atributos.super_poder );
            printf("\n");
            printf("===================================================================\n");
            printf("\n");
        }

    }

    CartasSuperTrunfo* escolher_cartas(CartasSuperTrunfo cartas[],int numero_cartas,char *codigo){
        for(int i=0; i<numero_cartas;i++){
            if(strcmp(cartas[i].codigo_carta,codigo)==0){
                return &cartas[i];
            }
        }
        return NULL;

    }
    double valor_atributo(CartasSuperTrunfo *carta,char *atributo){
        if(strcmp(atributo,"populacao")==0)
            return carta->atributos.populacao;

        if(strcmp(atributo,"area")==0)
            return carta->atributos.area;

        if(strcmp(atributo,"pib")==0)
            return carta->atributos.pib;

        if(strcmp(atributo,"pontos_turisticos")==0)
            return carta->atributos.pontos_turisticos;

        if(strcmp(atributo,"densidade_populacional")==0)
            return carta->atributos.densidade_populacional;

        if(strcmp(atributo,"pib_per_capta")==0)
            return carta->atributos.pib_per_capta;

        if(strcmp(atributo,"super_poder")==0)
            return carta->atributos.super_poder;

        return -1;


    }

    void comparar_cartas(CartasSuperTrunfo *carta1, CartasSuperTrunfo *carta2, char *atributo){
        double valor1=valor_atributo(carta1,atributo);
        double valor2=valor_atributo(carta2,atributo);

        if(valor1 == -1|| valor2 == -1){
            printf("Atributo invalido\n");
            return ;
        }

        printf("\nBatalha!!!!\n");
        printf(" Carta 1 (%s): %s =%.2f\n",carta1->codigo_carta,atributo,valor1);
        printf(" Carta 2 (%s): %s =%.2f\n",carta2->codigo_carta,atributo,valor2);

        if (strcmp(atributo,"densidade_populacional")==0)
        {
            if( valor1 < valor2)
                {
                    printf(" jogador 1 vencedor com a carta %s\n",carta1->codigo_carta);
                    exibir_cartas(carta1,1);
                }

                else if(valor1 > valor2)
                {
                    printf(" jogador 2 vencedor com a carta %s\n",carta2->codigo_carta);
                    exibir_cartas(carta2,1);
                }

                else
                {
                    printf("Empatou!!\n");
                }

        }

        else
        {

            if(valor1 > valor2){
                printf(" jogador 1 vencedor com a carta %s\n",carta1->codigo_carta);
                exibir_cartas(carta1,1);
            }else if(valor1 < valor2){
                printf(" jogador 2 vencedor com a carta %s\n",carta2->codigo_carta);
                exibir_cartas(carta2,1);
            }else{
                printf("Empatou!!\n");}

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
    char carta1[5];
    char carta2[5];



    printf("\n");
    printf("===================================================================\n");
    printf("\n");
    printf("Player 1 escolha sua carta(codigo)!:");
    scanf(" %s", carta1);
    printf(" jogador 1 escolheu a carta: %s\n",carta1);
    printf("\n");
    printf("===================================================================\n");

    printf("\n");
    printf("===================================================================\n");
    printf("\n");
    printf("Player 2 escolha sua carta(codigo)!:");
    scanf(" %s", carta2);
    printf(" jogador 2 escolheu a carta: %s\n",carta2);
    printf("\n");
    printf("===================================================================\n");
    printf("\n");

    CartasSuperTrunfo *carta_escolhida1 = escolher_cartas(cartas, numero_cartas, carta1);
    CartasSuperTrunfo *carta_escolhida2 = escolher_cartas(cartas, numero_cartas, carta2);

    if (carta_escolhida1!=NULL && carta_escolhida2!=NULL)
    {
        printf("Carta Player 1\n");
        exibir_cartas(carta_escolhida1,1);
         printf("Carta Player 2\n");
        exibir_cartas(carta_escolhida2,1);
    }else
    {
        printf("Uma das cartas nao foi encontrada!\n");
    }


    if (carta_escolhida1 != NULL && carta_escolhida2 != NULL)
        {
        printf("Escolha o atributo para comparar (populacao, area, pib, pontos_turisticos, densidade_populacional, pib_per_capta, super_poder): ");
        char atributo[50];
        scanf(" %s", atributo);

        comparar_cartas(carta_escolhida1, carta_escolhida2, atributo);
    } else {
        printf("Uma das cartas nao foi encontrada!\n");
    }

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
//não se esquecer dos ; sempre estão gerando erro


                                                                                // documentação


// cuidado aonde poe as variaveis, fora da ordem pode dar estouro de pilha, e mais facil por na ordem certa que fazer uma função de alocação dinamica de memoria

// nesta ultima etapa todos os valores sao somados para se chegar ao poder total da carta(super poder) o programa ja faz isso.
//tambem sera adicionado  a função de comparação para que seja efetivamente jogado o jogo, comparando cartas eseus tributos uma vez que forem criadas
// atenção no acesso as variaveis, pois sao acessadas atrave de ponteiros, não acessar ponteiros de ponteiros, pois sempre darao nulos(Muito cuidado nessa parte,se for fazer alterações)



// feito por Aluno: Albert Pimentel França  / Curso: Ciência da Computação/ Matricula 202405681304



