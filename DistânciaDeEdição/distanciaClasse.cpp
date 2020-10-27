//Criado por: Pedro Figueiredo, Carlos Silvestre, Gabriel Henrique, Lucas Melgaço e Pedro Nielson
//Distância de edição SKIENA, Steven S. The Algorithm Design Manual. London: Springer London, 2008.
//https://doi.org/10.1007/978-1-84800-070-4.


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MATCH       0     //constante de match
#define INSERT      1     //constante de inserçao
#define DELETE      2     //constante de exclusão
#define MAXLEN      30    //tamanho máximo de caracteres da palavra

class Cell                //classe que se refere a menor estrutura da classe distancia
{
private:
    int cost;
    int parent;

public:
    Cell()
    {
        cost = 0;
        parent = -1;
    }

    int getCost()
    {
        return cost;
    }

    int getParent()
    {
        return parent;
    }

    void setCost(int _cost)
    {
        cost = _cost;
    }

    void setParent(int _parent)
    {
        parent = _parent;
    }
};

class Distancia{                          //classe que detem os metodos para estimar a distancia entre as palavras
private:
    Cell m[MAXLEN+1][MAXLEN+1];           //instância de matriz da classe Cell

public:
    Distancia()
    {
        for(int i=0; i<MAXLEN; i++)
        {
            m[0][i].setCost(i);
            if(i>0)
                m[0][i].setParent(INSERT);
            else
                m[0][i].setParent(-1);

            m[i][0].setCost(i);
            if(i>0)
                m[i][0].setParent(DELETE);
            else
                m[i][0].setParent(-1);
        }
    }

    void goal_cell(string str1, string str2, int *i, int *j)
    {
        *i = str1.length()-1;                                    //faz com que i aponte para a útlima posição
        *j = str2.length()-1;                                    //faz com que j aponte para a última posição
    }

    int match(char c, char d)                                     //verifica se um caracter é igual ao outro retornando 0 em caso positivo e 1 em negativo.
    {
        if(c == d)
            return 0;
        return 1;
    }
    void insert_out(string str2, string &str3, int j)              //método de inserção
    {
        cout << "I \t -> ";
        str3[j] = toupper(str2[j]);
        str3.resize(str3.length()+1);
        cout << str3 << endl;                                          //imprime o status da string 3

    }

    void delete_out(string str1, string str2, string &str3, int i)  //método de exclusão
    {
        cout << "D \t -> ";
        str3[i] = toupper(str2[i]);
        str3.resize(str3.length()-1);
        cout << str3 << endl;                                        //imprime o status da string 3
    }

    void match_out(string str1, string str2, string &str3, int i, int j)   //método de encontro do caractere
    {
        if(str1[i]==str2[j])                                             //confirma a igualdade dos caracteres.
        {
            str3[j] = str2[j];
            cout << "M \t -> ";
            cout << str3 << endl;                                      //imprime o status da string 3
        }

        else
        {
            str3[j] = toupper(str2[j]);                                //verificacao de match mesmo se uma string esteja no modo maiúsculo
            cout << "S \t -> ";
            cout << str3 << endl;                                      //imprime o status da string 3
        }


    }

    void caminho(string str1, string str2, string &str3, int i, int j)   //metodo que executa o caminho , chamando match_out, insert_out ou delete_out conforme a situação do caractere
    {
        if(m[i][j].getParent() == -1)
            return;

        if(m[i][j].getParent() == MATCH)                             //compara com MATCH o elemento de m
        {
            caminho(str1, str2, str3, i-1, j-1);
            match_out(str1, str2, str3, i, j);
            return;
        }

        if(m[i][j].getParent() == INSERT)                              //compara com INSERT o elemento de m
        {
            caminho(str1, str2, str3, i, j-1);
            insert_out(str2,str3, j);
            return;
        }

        if(m[i][j].getParent() == DELETE)                                 //compara com DELETE o elemento de m
        {
            caminho(str1, str2, str3, i-1, j);
            delete_out(str1, str2, str3, i);
            return;
        }
}

    int distancia(string str1, string str2, string &str3)                 //método de calcula a distancia
    {
        int i, j, k, s1 = str1.length(), s2 = str2.length(), opt[3];

        for(i=1; i<s1; i++)                                                     //laço que analisa a primeira string
        {
            for(j=1; j<s2; j++)                                                      //laço que analisa a segunda string
            {
                opt[MATCH] = m[i-1][j-1].getCost() + match(str1[i], str2[j]);
                opt[INSERT] = m[i][j-1].getCost() + 1;
                opt[DELETE] = m[i-1][j].getCost() + 1;

                m[i][j].setCost(opt[MATCH]);
                m[i][j].setParent(MATCH);
                for(k=INSERT; k<=DELETE; k++)
                {
                    if(opt[k] < m[i][j].getCost())
                    {
                        m[i][j].setCost(opt[k]);
                        m[i][j].setParent(k);
                    }
                }
            }
        }
        goal_cell(str1, str2, &i, &j);
        caminho(str1, str2, str3, i, j);
        return m[i][j].getCost();                                     //retorna a distancia
    }
};

void leArquivo(string &entrada, string &saida)   //leitira do arquivo de texto
{
    ifstream entradaTXT;

    entradaTXT.open("teste.txt");                 //abertura do arquivo de texto.

    getline(entradaTXT, entrada);
    getline(entradaTXT, saida);
    entrada = " " + entrada;
    saida = " " + saida;

    entradaTXT.close();                             //fechamento do arquivo do txt.
}

int main()
{
    string s1, s2;
    string s3 = "                   ";
    leArquivo(s1, s2);
    Distancia *d = new Distancia;                  //criação do objeto ponteiro de distancia


    s3 = s1;

    cout << "Entrada: " << s1 << endl << endl;
    int res = d->distancia(s1, s2, s3);       //res recebe a distancia que equivale quantidade de operacoes para modificar a palavra.
    cout << endl << "Saida: " << s3 << endl;
    cout << "Distancia: " << res << endl;       //imprime a distancia
    delete d;


    return 0;
}
