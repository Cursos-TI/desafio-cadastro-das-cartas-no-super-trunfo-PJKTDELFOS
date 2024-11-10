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

        if(cartas[i].atributos.area!=0 && cartas[i].atributos.populacao!=0)
        {
            cartas[i].atributos.densidade_populacional=cartas[i].atributos.populacao/cartas[i].atributos.area;
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
            cartas[i].atributos.densidade_populacional=0;
        }

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
            printf("Densidade Populacional %.2f  habitantes /km2 \n",cartas[i].atributos.densidade_populacional);
            printf("Pib %.2f Mil reais por pessoa\n",cartas[i].atributos.pib_per_capta );
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
//não se esquecer dos ; sempre estão gerando erro


                                                                                // documentação


// cuidado aonde poe as variaveis, fora da ordem pode dar estouro de pilha, e mais facil por na ordem certa que fazer uma função de alocação dinamica de memoria

// nesta estapa, são calculados o pib per capita(pib/população) e densidade demografica(população/area) o programa ja faz esse calculo de forma direta, sem necessidade do usiario realiza-lo, caso qualquer um dos dados como pib, area ou populaçao for zero os resultados destes dados da carta sera zero,essa evita-se problemas de divisao por 0 e o jogo prossegue entao nao coloque zero

// feito por Aluno: Albert Pimentel França  / Curso: Ciência da Computação/ Matricula 202405681304



