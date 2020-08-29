#include "ClasseBinaria.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
    int quantElementos=0;
    int primo;
    FILE *pfile;
    pfile = fopen("teste100.txt","rt");
    if(pfile == NULL)
        exit(0);
    fscanf(pfile, "%d", &quantElementos);
    primo = calcPrimo(quantElementos);

    setlocale(LC_ALL, "Portuguese");
    char op;
    do
    {
        cout << "---------MENU--------" << endl << endl;
        cout << "a) Arvore" << endl;
        cout << "b) Busca Linear" << endl;
        cout << "c) Hashing Linear" << endl;
        cout << "d) Hashing Endereçamento Aberto" << endl;
        cout << "z) Sair" << endl;
        cout << endl;
        cout << "Opção: ";
        cin >> op;

        switch (op)
        {
            case 'a':
            {
                system("cls");
                cout << "-----ARVORE-----" << endl << endl;
                Arvore <int>*bi = new Arvore<int> ();
                abreArvore(bi);
                delete bi;
                system("pause");
                system("cls");
                break;
            }
            case 'b':
            {

                break;
            }
            case 'c':
            {
                system("cls");
                cout << "-----Hashing Linear-----" << endl << endl;
                HashLinear<int>*hlin = new HashLinear<int>(primo);
                abreHashing(hlin);
                delete hlin;
                system("pause");
                system("cls");
                break;
            }
            case 'd':
            {
                hashEndAberto<int>*hAberto = new hashEndAberto<int>(3);
                delete hAberto;
                break;
            }
            default:
            {
                system("cls");
                break;
            }
        }
    }while (op != 'z');




    return 0;
}
