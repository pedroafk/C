/* Criado por: 
Pedro Henrique Figueiredo Cota Oliveira
Saulo Peixoto de Castro
Anderson Araujo de Souza Ferreira
Luiz Henrique Barcelos Duarte

Durante a disciplina de Algoritmos e Estutura de Dados 1
e tem como finalidade ver se um número é complexo ou não
utilizando Tipo Abstrato de Dados.
*/

#ifndef DECLARACAOFUNCOES_H_INCLUDED
#define DECLARACAOFUNCOES_H_INCLUDED

const int MAX = 2;

typedef struct
{
    double real, imaginario;
    char i = 'i';

}num_complexo;

void atribuiComplexo (num_complexo** comp);
void imprimeComplexo (num_complexo* comp);
void copiaComplexo (num_complexo* comp1, num_complexo** comp2);
void somaComplexo(num_complexo* comp1, num_complexo* comp2);
void EhReal (num_complexo* comp1);

#endif // DECLARACAOFUNCOES_H_INCLUDED
