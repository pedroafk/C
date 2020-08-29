/*  Criado por Pedro Figueiredo
É um programa básico em C criado durante a ajuda ao um amigo ao qual estava
cursando a disciplina de programação básica 1
*/

#include<stdio.h>   
#include<stdlib.h>


int main()
{
    int cod, qtd, nov;
    int qcachorro = 0;
    int qxsalada = 0;
    int qxbacon = 0;
    int qmisto = 0;
    int qsalada = 0;
    int qagua = 0;
    int qrefri = 0;
    float  val,total;

    printf(" Item    produto            codigo   Preco unitario\n");
    printf("**********************************************************\n");
    printf(" 1      Cachorro - quente   100        5,00\n");
    printf(" 2      X - salada          101        8,79\n");
    printf(" 3      X - bacon           102        9,99\n");
    printf(" 4      Misto               103        6,89\n");
    printf(" 5      Salada              104        4,80\n");
    printf(" 6      Agua                105        3,49\n");
    printf(" 7      Refrigerante        106        4,99\n");
    printf("**********************************************************\n");

    do
    {
        printf("Digite o codigo do item de 1 a 7:");
        scanf_s("%d", &cod);
        printf("Quantidade:");
        scanf_s("%d", &qtd);

        switch (cod)
        {
        case 1:
            val = val + (qtd * 5.00);
            qcachorro = qcachorro + qtd;
            break;
        case 2:
            val = val + (qtd * 8.79);
            qxsalada = qxsalada + qtd;
            break;
        case 3:
            val = val + (qtd * 9.99);
            qxbacon = qxbacon + qtd;
            break;
        case 4:
            val =  val + (qtd * 6.89);
            qmisto = qmisto + qtd;
            break;
        case 5:
            val = val + (qtd * 4.80);
            qsalada = qsalada + qtd;
            break;
        case 6:
            val = qtd * 3.49;
            qagua = qagua + qtd;
            break;
        case 7:
            val = val + (qtd * 4.99);
            qrefri = qrefri + qtd;
            break;

        }
        printf("\nDeseja outro intem?\n\nDigite [0] para sim e [8] para encerrar:");
        scanf_s("%d", &nov);
    }
    while (nov == 0);
    total = val;

    if (qcachorro != 0)
        printf("\n\n 1 - Cachorro Quente %d, %s \n", qcachorro, "5.00" );

    if (qxsalada != 0)
        printf("\n\n X salada %d, %s \n", qxsalada, "8.79");

    if (qxbacon != 0)
        printf("\n\nX - bacon %d, %0.2f\n", qxbacon, val);

    if (qmisto != 0)
        printf("\n\nMisto %d = %0.2f\n", qmisto, val);

    if (qsalada != 0)
        printf("\n\nSalada %d = %0.2f\n", qsalada, val);

    if (qagua!= 0)
        printf("\n\nAgua * %d = %0.2f\n", qagua, val);

    if (qrefri != 0)
        printf("\n\nRefrigerante  * %d = %0.2f\n", qrefri, val);

    printf("\n\n");

    printf("O valor total a pagar: R$%.2f\n", total);



    system("pause");
    return 0;
}
