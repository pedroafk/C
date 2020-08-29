/*  Criado por Pedro Figueiredo
É um programa básico em C criado durante a ajuda ao um amigo ao qual estava
cursando a disciplina de programação básica 1
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    float maxMilimetros, maxEntrada=0, maxSaida=0, quantidade = 0;
    float saida[12];
    float entrada[12];
    int i;

    printf("Digite a quantidade maxima de ml: ");
    scanf_s("%f", &maxMilimetros);

    for(i=0; i<12; i++) /* para preencher*/
    {
        printf("\n Mes: %d", i+1 ,"\n\n");
        printf("\n Entrada: ");
        scanf_s("%f", &entrada[i]);
        maxEntrada = maxEntrada + entrada[i]; /* Armazena quanto entrou no total dos 12 meses*/

        printf("\n Saida: ");
        scanf_s("%f", &saida[i]);
        printf("\n\n");
        maxSaida = maxSaida + saida[i]; /* Armazena quanto saiu no total dos 12 meses*/


        quantidade = quantidade + (entrada[i] - saida[i]);
        if(quantidade <= 0)
            printf("Reservatorio Vazio \n\n");
        if(quantidade < 0)
            quantidade = 0;

        if((quantidade) > maxMilimetros)
        {
            printf("reservatorio cheio \n\n");
            quantidade = maxMilimetros;
        }

        printf("Valor disponivel do mes: %d, %0.2f", i+1, quantidade);
        printf("\n\n");

    }

    printf("\n\n");
    system("pause");
}
