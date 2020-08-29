/* Criado por:
Pedro Henrique Figueiredo Cota Oliveira
Saulo Peixoto de Castro
Anderson Araujo de Souza Ferreira
Luiz Henrique Barcelos Duarte

Durante a disciplina de Algoritmos e estrutura de dados 1
e tem como objetivo simular uma conta bancária utilizando Tipo
Abstratos de Dados.
*/

# include <iostream>
# include "ContaBancaria.h"

using namespace std;

void Inicializa(ContaBancaria* conta, int numero, double saldo){
	(*conta).numero = numero;
	(*conta).saldo = saldo;
}

void InicializaData (Data *contaData, int dia, int mes, int ano)
{
    contaData->dia = dia;
    contaData->mes = mes;
    contaData->ano = ano;
}

void ImprimeData (Data *contaData)
{
    cout << contaData->dia << "/" << contaData->mes << "/" << contaData->ano;
    cout << endl;
}

void ImprimeExtento (Data *contaData)
{
    if(contaData->mes == 1)
    {
        cout << contaData->dia << " de " << "Janeiro" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 2)
    {
        cout << contaData->dia << " de " << "Fevereiro" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 3)
    {
        cout << contaData->dia << " de " << "Marco" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 4)
    {
        cout << contaData->dia << " de " << "Abril" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 5)
    {
        cout << contaData->dia << " de " << "Maio" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 6)
    {
        cout << contaData->dia << " de " << "Junho" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 7)
    {
        cout << contaData->dia << " de " << "Julho" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 8)
    {
        cout << contaData->dia << " de " << "Agosto" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 9)
    {
        cout << contaData->dia << " de " << "Setembro" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 10)
    {
        cout << contaData->dia << " de " << "Outubro" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 11)
    {
        cout << contaData->dia << " de " << "Novembro" << " de " << contaData->ano;
        cout << endl;
    }
    if(contaData->mes == 12)
    {
        cout << contaData->dia << " de " << "Dezembro" << " de " << contaData->ano;
        cout << endl;
    }
}

void Deposito (ContaBancaria* conta, double valor){
	(*conta).saldo += valor;
}
void Saque (ContaBancaria* conta, double valor){
	(*conta).saldo -= valor;
}

void Imprime (ContaBancaria conta){
	cout << "Numero: " << conta.numero << endl;
	cout << "Saldo: " <<  conta.saldo << endl;
}

void Transferencia(ContaBancaria* c1, ContaBancaria* c2, float valor){

   Saque (c1, valor);
   Deposito (c2, valor);

}

