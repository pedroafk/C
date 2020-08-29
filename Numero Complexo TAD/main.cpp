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

int main()
{
    setlocale (LC_ALL, "Portuguese");
    num_complexo *comp1 = NULL;
    num_complexo *comp2 = NULL;

    atribuiComplexo(&comp1);
    imprimeComplexo(comp1);
    copiaComplexo (comp1, &comp2);
    somaComplexo(comp1, comp2);
    EhReal (comp1);

    delete [] comp1;
    delete [] comp2;

    return 0;
}
