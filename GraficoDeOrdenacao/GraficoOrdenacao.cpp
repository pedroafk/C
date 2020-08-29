/* Criado por:  Pedro Figueiredo
Este programa mede em milissegundos quanto tempo os algoritmos
Bubble sort, Selection sort e Quick sort levam para ordenar um
vetor de tamanho n = 100000 elementos;
*/

#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;

int bubblesort(int data[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>i; --j)
        {
            if(data[j] < data[j-1])
                swap(data[j],data[j-1]);
        }
    }
}

int selectionsort(int data[], int n)
{
    for(int i=0, j, least; i < n-1; i++)
    {
        for(j = i+1, least = i; j<n; j++)
            if(data[j] < data[least])
                least = j;
        swap(data[least],data[i]);
    }
}

void quicksort(int data[], int first, int last)
{
    int lower = first+1, upper = last;
    swap(data[first],data[(first + last)/2]);
    int bound = data[first];
    while(lower <= upper)
    {
        while (bound > data[lower])
            lower++;
        while (bound < data[upper])
            upper--;
        if(lower < upper)
            swap(data[lower++], data[upper--]);
        else lower++;
    }
    swap(data[upper], data[first]);
    if(first < upper-1)
        quicksort(data,first,upper-1);
    if(upper+1 < last)
        quicksort(data,upper+1,last);
}

void quicksort(int data[], int n)
{
    int i, max;
    if(n<2)
        return;
    for(i=1, max = 0; i<n; i++)
        if(data[max] < data[i])
            max = i;
    swap(data[n-1], data[max]);
    quicksort(data,0,n-2);
}

void preencheVetorCrescente(int vetorCrescente[], int n)
{
    for(int i=0; i<n; i++)
        vetorCrescente[i] = i; // Todos os inteiros positivos cresentes, sem o 0;
}

void preencheVetorDecrescente(int vetorDecrescente[], int n)
{
    for(int i=0; i<n; i++)
        vetorDecrescente[i] = n-i;  //Todos os inteiros positivos decrescente sem o 0;
}

void preencheVetorParcial(int vetorParcial[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(i < (n/2))
        {
            vetorParcial[i] = i+1;
        }
        else
        {
            vetorParcial[i] = n-i;
        }
    }
}

void preencheVetorAleatorio(int vetorAleatorio[],int n)
{
    for(int i=0; i<n; i++)
        vetorAleatorio[i] = 1 + (rand()%(n));
}

int main ()
{
    int n = 100000;
    int vetorBubble[n];
    int vetorSelection[n];
    int vetorQuick[n];

    //Preenchimento de vetores
    //preencheVetorCrescente(vetorCrescente, n);
    //preencheVetorDecrescente(vetorDecrescente,n);
    //preencheVetorParcial(vetorParcial,n);
    //preencheVetorAleatorio(VetorAleatorio,n);

    //Medi��o de tempo bubblesort;
    preencheVetorAleatorio(vetorBubble,n);//Vetor utilizado
    auto bubbleStart = chrono::system_clock::now();
    bubblesort(vetorBubble,n);//Fun��o utilizada
    auto bubbleEnd = chrono::system_clock::now();
    auto bubbleElapsed = chrono::duration_cast<chrono::milliseconds>(bubbleEnd - bubbleStart);
    cout << "Bubblesort milissegundos: " << bubbleElapsed.count() << endl;   // tempo de sa�da da fun��o;

    //Medi��o de tempo selectionsort;
    preencheVetorAleatorio(vetorSelection,n);   //Vetor utilizado;
    auto selectionStart = chrono::system_clock::now();
    selectionsort(vetorSelection,n);            //Fun��o utilizada;
    auto selectionEnd = chrono::system_clock::now();
    auto selectionElapsed = chrono::duration_cast<chrono::milliseconds>(selectionEnd - selectionStart);
    cout << "Selectionsort milissegundos: " << selectionElapsed.count() << endl;    //tempo de sa�da da fun��o;

    //Medi��o de tempo quicksort;
    preencheVetorAleatorio(vetorQuick,n);   //Vetor utilizado;
    auto quickStart = chrono::system_clock::now();
    quicksort(vetorQuick,n);                //Fun��o utilizada;
    auto quickEnd = chrono::system_clock::now();
    auto quickElapsed = chrono::duration_cast<chrono::milliseconds>(quickEnd - quickStart);
    cout << "Quicksort milissegundos: " << quickElapsed.count() << endl;       //tempo de sa�da da fun��o;

    return 0;
}
