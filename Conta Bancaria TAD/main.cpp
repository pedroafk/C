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

int main (int argc, char **argv){
	ContaBancaria conta1, conta2;
	Data contaData;
	Inicializa(&conta1, 918556, 300.00);
	Inicializa(&conta2, 918578, 500.00);
	InicializaData (&contaData, 11, 7, 2018);
	ImprimeData (&contaData);
	ImprimeExtento (&contaData);
	cout << "\nAntes da movimentacao:\n ";
	Imprime(conta1);
	Deposito(&conta1, 50.00);
	Saque(&conta1, 70.00);
	cout << "\nDepois da movimentacao:\n ";
	Imprime (conta1);
	Imprime (conta2);
	Transferencia(&conta2, &conta1, 100);
	Imprime (conta1);
	Imprime (conta2);

	return 0;
}
