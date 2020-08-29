/*  Criado por Pedro Figueiredo;
Este programa tem a finalidade pegar uma entrada massiva de dados e verificar
de forma recursiva qual e o maiorValor, menorValor destes dados, alem
de procurar se uma key esta dentro deste vetor massivo de dados, tudo
utilizando recursividade;

*/

#include <iostream>
using namespace std;

void preencheVetorAmostras(int i,int n, int vetorAmostras[])    //Preenche o vetor de forma recursiva;
{
    vetorAmostras[i] = 10000 + (rand()%10000);                  //Com valores de 10000 a 20000;
    if(i<n)
        preencheVetorAmostras(i+1,n,vetorAmostras);             //Sempre passa i+1 como proximo indice;
    else
        return;

}

void determinaAmostras (int i, int n, int vetorAmostras[], int *menorValor, int *maiorValor)    //Determina o menor e maior valor no vetor;
{
    if(i<n)
    {
        if(vetorAmostras[i] < (*menorValor))
            (*menorValor) = vetorAmostras[i];

        if(vetorAmostras[i] > (*maiorValor))
            (*maiorValor) = vetorAmostras[i];
    }
    else
    {
        return;
    }
    determinaAmostras(i+1,n,vetorAmostras,menorValor,maiorValor);
}

bool procuraKey(int key,int i, int n, int vetorAmostras[])
{
    if(i<n)
    {
        if(key == vetorAmostras[i])
            return 1;
        else
            procuraKey(key,i+1,n,vetorAmostras);
    }
    else
        return 0;
}


int main ()
{
    int n = 4096;
    int vetorAmostras[n];
    int menorValor = 20000, maiorValor = 10000;

    preencheVetorAmostras(0,n,vetorAmostras);
    determinaAmostras(0,n,vetorAmostras,&menorValor,&maiorValor);

    cout << "MenorValor: " << menorValor << endl;
    cout << "MaiorValor: " << maiorValor << endl;

    int key = 15723;
    bool validaKey;
    validaKey = procuraKey(key,0,n,vetorAmostras);

    if(validaKey)
        cout << "A chave esta nas amostras" << endl;
    else
        cout << "A chave nao esta nas amostras" << endl;

    return 0;
}
