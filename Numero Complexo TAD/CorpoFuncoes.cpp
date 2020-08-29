/* Criado por: 
Pedro Henrique Figueiredo Cota Oliveira
Saulo Peixoto de Castro
Anderson Araujo de Souza Ferreira
Luiz Henrique Barcelos Duarte

Durante a disciplina de Algoritmos e Estutura de Dados 1
e tem como finalidade ver se um número é complexo ou não
utilizando Tipo Abstrato de Dados.
*/

#include <iostream>
#include "DeclaracaoFuncoes.h"

using namespace std;

void atribuiComplexo (num_complexo** comp)
{
    *comp = new (nothrow) num_complexo();

    if(*comp)
    {
        cout << "Real: ";
        cin >> (*comp)->real;
        cout << "Imaginario: ";
        cin >> (*comp)->imaginario;
    }
}

void imprimeComplexo(num_complexo* comp)
{
    cout << comp->real << " + " << comp->imaginario << comp->i;
    cout << endl;
}

void copiaComplexo (num_complexo* comp1, num_complexo** comp2)
{
    *comp2 = new (nothrow) num_complexo();
    if(*comp2)
    {
        (*comp2)->real = comp1->real;
        (*comp2)->imaginario = comp1->imaginario;
    }
}

void somaComplexo(num_complexo* comp1, num_complexo* comp2)
{
    cout << "Soma: " << comp1->real + comp2-> real << " + " << comp1->imaginario + comp2->imaginario << comp1->i;
    cout << endl;
}

void EhReal (num_complexo* comp1)
{
    if (comp1->imaginario != 0.0)
    {
        cout << "N Eh Real!" << endl;
    }
    else
    {
        cout << "Eh Real!" << endl;
    }
}












