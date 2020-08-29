/*  Criado por Pedro Figueiredo e Bruna Lima
Programa desenvolvido durante a disciplina de Algoritmos e Estrutura
de dados 2 e tem como finalidade pegar uma massa de dados do tipo
Template e realizar operações com as seguintes estruturas de dados:

Arvore binária
Busca linear de vector
Hashing Linear
Hashing de endereçamento Aberto
*/

#ifndef CLASSEBINARIA_H_INCLUDED
#define CLASSEBINARIA_H_INCLUDED
#include<queue>
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<cmath>
#include<vector>
#include<list>
#include<cstdio>
using namespace std;

class pessoa
{
    public:
    int chave;
    char nome[50];
};

template <typename T>
class No
{
private:
    T info;
    No<T> *dir;
    No<T> *esq;

public:
    No(T infoConstrutor)
    {
        info = infoConstrutor;
        esq = NULL;
        dir = NULL;
    }
    No *getEsquerdo()
    {
        return esq;
    }
    No *getDireito()
    {
        return dir;
    }
    T getInfo()
    {
        return info;
    }
    void setInfo(T informacao)
    {
        info = informacao;
    }
    void setEsquerdo(No<T> *esqinfo)
    {
        esq = esqinfo;
    }
    void setDireito(No<T> *dirinfo)
    {
        dir = dirinfo;
    }
};

template <typename A>
class Arvore
{
private:
    No<A> *raiz;

public:
    Arvore()
    {
        inicializa();
    }
    ~Arvore()
    {
        destroi(raiz);
    }
    void inicializa()   //Fun��o para inicializar a raiz da arvore com 0;
    {
        raiz = NULL;
    }
    void destroi (No<A>* raizdestrutor)
    {
        if (raizdestrutor != NULL)
        {
            destroi(raizdestrutor->getEsquerdo());
            destroi(raizdestrutor->getDireito());
            delete raizdestrutor;
            raizdestrutor = NULL;
        }
    }
    No<A>* getRaiz()
    {
        return raiz;
    }

    bool vazia()    //Verifica se esta vazia;
    {
        if(raiz ==  0)
            return 1;
        else
            return 0;
    }

    void insere (A info) //Insere um elemento dentro da arvore;
    {
        //clock_t ti, tf;
        //double tempogasto;
        //ti = clock();
        No<A> *ramo = new No<A>(info);

        if(vazia())
            raiz = ramo;
        else
        {
            No<A> *aux = raiz;
            No<A> *ant = NULL;

            while (aux != 0)
            {
                ant = aux;
                if (info < aux->getInfo())
                    aux = aux->getEsquerdo();
                else
                    aux = aux->getDireito();
            }

            if(info < ant->getInfo())
                ant->setEsquerdo(ramo);
            else
                ant->setDireito(ramo);
        }
        //tf = clock();
        //tempogasto = ((double)(tf-ti)) / CLOCKS_PER_SEC;

        //cout<<"\n\nO tempo gasto na execucao foi: "<<tempogasto;
    }

    bool pesquisa (A info)    //Comando para pesquisar se elemento esta na arvore;
    {
        int cont = 0;
        No<A> *aux = raiz;
        while (aux != 0)
        {
            if (info == aux->getInfo())
            {
                cout << "-----> " << info << " encontrado!" << endl;
                cout << "----->Quant Busca: " << cont << endl;
                return 1;
            }
            else
            {
                if(info < aux->getInfo())
                    aux = aux->getEsquerdo();
                else
                    aux = aux->getDireito();
            }
            cont++;
        }
        cout << " " << info << " nao encontrado!" << endl;
        cout << "Quant Busca: " << cont << endl;
        return 0;
    }

    void imprimeOrdem () //Comando para chamar impressao da arvore em ordem;
    {
        if(vazia())
            cout << "Arvore Vazia!" << endl;
        else
        {
            cout << "Arvore em ordem: ";
            emOrdem(raiz);
            cout << endl;
        }
    }
    void emOrdem (No<A> *aux)  //Imprime a arvore em ordem;
    {
        if (aux != 0)
        {
            emOrdem(aux->getEsquerdo());
            cout << aux->getInfo() << " ";
            emOrdem(aux->getDireito());
        }
    }
    int altura (No<A> *aux)    //Calcula a altura da arvore;
    {
        if (aux == 0)
            return -1;
        else
        {
            int alturaEsq = altura(aux->getEsquerdo());
            int alturaDir = altura(aux->getDireito());

            if (alturaEsq < alturaDir)
                return alturaDir+1;
            else
                return alturaEsq+1;
        }
    }
    void imprimeAltura() //Imprime a altura da arvore;
    {
        if (altura(raiz) >= 0)
            cout << "**********Altura da arvore: " << altura(raiz) << endl;
        else
            cout << "Arvore vazia! " << endl;
    }

    bool verifFolha (No <A> *def)   //Saber se o ponteiro est� na folha;
    {
        if (def->getEsquerdo() == NULL && def->getDireito() == NULL)
            return 1;
        else
            return 0;
    }

    No<A> *menorDosMaiores (No<A> *def) //retorna menor dos maiores;
    {
        if(def->getEsquerdo() == NULL)
            return def;
        else
            menorDosMaiores(def->getEsquerdo());
    }

    No<A> *maiorDosMenores (No<A> *def) //retorna maior dos menores;
    {
        if(def->getDireito() == NULL)
            return def;
        else
            maiorDosMenores(def->getDireito());
    }

    No<A> *setAntes(No<A> *ant, No<A> *def) //retorna antes do maior ou menor dos menores;
    {
        while (ant != NULL)
        {
            if(def->getInfo() > ant->getInfo())
            {
                if(ant->getDireito()->getInfo() == def->getInfo())
                {
                    break;
                }
                else
                {
                    ant = ant->getDireito();
                }
            }
            else
            {
                if(ant->getEsquerdo()->getInfo() == def->getInfo())
                {
                    break;
                }
                else
                {
                    ant = ant->getEsquerdo();
                }
            }
        }
        return ant;

    }

    void removeRamo (A info)
    {
        No <A> *aux = raiz; //Aponta para o alvo;
        No <A> *ant = NULL;
        No <A> *def = raiz; //Aponta pra folha de troca;

        while (aux != NULL)    //Coloca ponteiro aux no alvo;
        {
            if(info < aux->getInfo())
            {
                aux = aux->getEsquerdo();
            }
            else if (info > aux->getInfo())
            {
                aux = aux->getDireito();
            }
            else
                break;
        }

        if (aux == NULL)
        {
            cout << "Elemento N esta na arvore!" << endl;
            return;
        }

        if (aux->getInfo() == def->getInfo())   //Caso de raiz;
        {
            if(verifFolha(def))
            {
                delete aux;
                aux = def = raiz = NULL;
            }
            else if (def->getEsquerdo() == NULL && def->getDireito() != NULL)   //Vai pra direita da raiz;
            {
                def = def->getDireito();
                raiz = def;
                delete aux;
            }
            else if (def->getEsquerdo() != NULL && def->getDireito() == NULL)   //Vai pra direita da raiz;
            {
                def = def->getEsquerdo();
                raiz = def;
                delete aux;
            }
            else    //Se direita e esquerda tem gente;
            {
                ant = def;
                def = def->getDireito();
                def = menorDosMaiores(def);
                ant = setAntes(ant, def);

                if(verifFolha(def))
                {
                    if(ant->getEsquerdo()->getInfo() == def->getInfo())
                    {
                        aux->setInfo(def->getInfo());
                        ant->setEsquerdo(NULL);
                        delete def;
                        def = raiz;
                    }
                    else
                    {
                        aux->setInfo(def->getInfo());
                        ant->setDireito(NULL);
                        delete def;
                        def = raiz;
                    }
                }
                else
                {
                    if(ant->getInfo() == aux->getInfo())
                    {
                        ant = def->getDireito();
                        aux->setInfo(def->getInfo());
                        aux->setDireito(ant);
                        delete def;
                        def = raiz;
                    }
                    else
                    {
                        No<A> *ajud = ant;
                        ant = def->getDireito();
                        aux->setInfo(def->getInfo());
                        ajud->setEsquerdo(ant);
                        delete def;
                        def = raiz;
                    }
                }
            }
        }
        else    //Caso n�o raiz;
        {
            ant = def;
            def = aux;
            ant = setAntes(ant, def);
            if(verifFolha(aux))
            {
                if(ant->getEsquerdo() != NULL)
                {
                    if(ant->getEsquerdo()->getInfo() == aux->getInfo())
                    {
                        ant->setEsquerdo(NULL);
                        delete aux;
                        def = aux = raiz;
                    }
                    else
                    {
                        ant->setDireito(NULL);
                        delete aux;
                        def = aux = raiz;
                    }
                }
                else
                {
                    if(def->getDireito() == NULL)
                    {
                        if(ant->getDireito()->getInfo() == aux->getInfo())
                        {
                            ant->setDireito(NULL);
                            delete aux;
                            def = aux = raiz;
                        }
                        else
                        {
                            ant->setEsquerdo(NULL);
                            delete aux;
                            def = aux = raiz;
                        }
                    }
                    else
                    {
                        No<A> *ajud = ant;
                        ant = def->getDireito();
                        aux->setInfo(def->getInfo());
                        ajud->setDireito(ant);
                        delete def;
                        def = raiz;
                    }
                }
            }
            else
            {
                if(def->getDireito() == NULL)
                {
                    def = def->getEsquerdo();
                    def = maiorDosMenores(def);
                    ant = setAntes(ant, def);
                }
                else
                {
                    def = def->getDireito();
                    def = menorDosMaiores(def);
                    ant = setAntes(ant, def);
                }

                if(verifFolha(def))
                {
                    if(ant->getDireito() != NULL)
                    {
                        if(ant->getDireito()->getInfo() == def->getInfo())
                        {
                            aux->setInfo(def->getInfo());
                            ant->setDireito(NULL);
                            delete def;
                            def = raiz;
                        }
                    }
                    else
                    {
                        if(ant->getEsquerdo()->getInfo() == def->getInfo())
                        {
                            aux->setInfo(def->getInfo());
                            ant->setEsquerdo(NULL);
                            delete def;
                            def = raiz;
                        }
                    }
                }
                else
                {
                    if(def->getEsquerdo() == NULL)
                    {
                        No<A> *ajud = ant;
                        ant = def->getDireito();
                        aux->setInfo(def->getInfo());
                        if(ajud->getEsquerdo()->getInfo() == def->getInfo())
                        {
                            ajud->setEsquerdo(ant);
                            delete def;
                            def = raiz;
                        }
                        else
                        {
                            ajud->setDireito(ant);
                            delete def;
                            def = raiz;
                        }
                    }
                }
            }
        }
    }

    void imprime_largura ()
    {
        queue<No<A>*> fila;
        No<A> *P = raiz;
        fila.push(P);
        cout<<"\nArvore em largura: \n";
        do
        {
            if (P->getEsquerdo() != NULL)
                fila.push(P->getEsquerdo());
            if (P->getDireito() != NULL)
                fila.push(P->getDireito());
            cout<<(fila.front()->getInfo())<<" ";
            fila.pop();
            P = fila.front();
        }
        while (!fila.empty());
        cout<<"\n\n";
    }

    void mostraArvore()
    {
        queue<No<A>*> nivelAtual, nivelSeguinte;
        nivelAtual.push(raiz);
        cout<<"\nArvore em largura:\n";
        while(!nivelAtual.empty())
        {
            No<A>* noAtual = nivelAtual.front();
            nivelAtual.pop();

            if(noAtual)
            {
                cout << noAtual->getInfo() << " ";
                nivelSeguinte.push(noAtual->getEsquerdo());
                nivelSeguinte.push(noAtual->getDireito());
            }
            if(nivelAtual.empty())
            {
                cout << endl;
                swap(nivelAtual, nivelSeguinte);
            }
        }
    }


    void espinhaDorsal (No<A> *aux, int primRot)
    {
        bool flag = true;
        No<A> *prox = aux;
        No<A> *ant = raiz;
        while (prox->getDireito()!=NULL && primRot!= 0)
        {
            if(aux->getDireito()==NULL)
                break;
            prox = aux->getDireito();
            aux->setDireito(NULL);
            prox->setEsquerdo(aux);
            if (flag)
            {
                raiz = prox;
            }
            else
            {
                ant = raiz;
                while(ant->getDireito()!=aux)
                {
                    ant = ant->getDireito();
                }
                ant->setDireito(prox);
            }
            aux = prox->getDireito();
            flag = false;
            --primRot;
        }
    }

    void rotacaoDSW(No<A> *aux, int m)
    {
        No<A> *prox = raiz;
        No<A> *ant = raiz;
        bool flag = true;
        for(int i=0; i<m; i++)
        {
            if(!flag)
            {
                if(aux->getDireito() != NULL)
                {
                    ant = aux;
                    aux = aux->getDireito();
                }
            }
            if(aux->getDireito()!= NULL)
            {
                prox = aux->getDireito();
                if(prox->getEsquerdo()!= NULL)
                {
                    aux->setDireito(prox->getEsquerdo());
                    prox->setEsquerdo(aux);
                }
                else
                {
                    prox->setEsquerdo(aux);
                    aux->setDireito(NULL);
                    if(!flag)
                    {
                        ant->setDireito(prox);
                        aux = prox;
                    }
                }
                if(flag)
                {
                    raiz = prox;
                    aux = raiz;
                    flag = false;
                }
            }
        }
    }

    void algDSW()
    {
        No<A> *tmp = raiz;
        No<A> *aux = NULL;
        No<A> *ant = raiz;
        bool flag = true;
        int n = 1, m = 0;
        if(vazia())
            cout << "Arvore vazia!" << endl;
        else
        {
            while (!verifFolha(tmp))
            {
                if(tmp->getEsquerdo()!=NULL)
                {
                    aux = tmp->getEsquerdo();
                    if(aux->getDireito()!= NULL)
                    {
                        tmp->setEsquerdo(aux->getDireito());
                        aux->setDireito(tmp);
                    }
                    else
                    {
                        tmp->setEsquerdo(NULL);
                        aux->setDireito(tmp);
                    }

                    if(flag)
                    {
                        raiz = aux;
                        tmp = raiz;
                    }
                    else
                    {
                        ant = raiz;
                        while(ant->getDireito()!= tmp)
                        {
                            ant = ant->getDireito();
                        }

                        ant->setDireito(aux);
                        tmp = aux;
                    }
                }
                else
                {
                    ++n;
                    flag = false;
                    tmp = tmp->getDireito();
                }
            }
        }
        //Segunda parte DSW;
        m = pow(2, floor(log2(n+1)))-1;
        int primRot = n - m;
        espinhaDorsal(raiz, primRot);
        while (m    >   1)
        {
            m = m/2;
            rotacaoDSW(raiz, m);
        }
    }




};

template <typename H>
class HashLinear
{
public:
    list<H> *listhash;
    int M;

    HashLinear(int tabHash)
    {
        M = tabHash;
        listhash = new list<H>[M];
    }

    ~HashLinear()
    {
        delete[] listhash;
    }

    void insereHashLin(H x)
    {
        listhash[x%M].push_back(x);
    }

    void buscaVal(H x)
    {
        int cont = 1;
        for(list<int>::iterator it = listhash[x%M].begin(); it!= listhash[x%M].end(); it++)
        {
            if(x == *it)
            {
                cout << "----->" << *it << " esta na lista!" << endl;
                cout << "----->Quant Pesquisa: " << cont << endl;
                return;
            }
            ++cont;
        }
        cout << x << " n esta na lista!" << endl;
        cout << "Quant Pesquisa: " << cont << endl;
    }

    void removeVal(H x)
    {
        listhash[x%M].remove(x);
    }
};

template <typename E>
class hashEndAberto
{
public:
    E *vetorhash;
    int M;
    int qte = 0;

    hashEndAberto(int tabHash)
    {
        M = tabHash;
        vetorhash = new E[M];
        for(int i=0; i<M; i++)
        {
            vetorhash[i] = NULL;
        }
    }

    ~hashEndAberto()
    {
        delete [] vetorhash;
    }

    void insere(E x)
    {
        int cont = 0;
        E pos = x%M;

        if (qte == M)
        {
            cout << "Vetor cheio!" << endl;
            return;
        }
        while( vetorhash[pos]!= NULL && (cont < M) )
        {
            if( (pos) == (M-1)  )
            {
                pos = 0;
                ++cont;
            }
            else
            {
                ++pos;
                ++cont;
            }
        }

        if(vetorhash[pos] == NULL)
        {
            vetorhash[pos] = x;
            ++qte;
        }
        else
        {
            cout << "Vetor Cheio!" << endl;
        }
    }

    void busca(E x)
    {
        E pos = x%M;
        int cont = 0;
        bool flag = true;

        while(vetorhash[pos] != x && cont < M && flag)
        {
            if (vetorhash[pos] == NULL)
            {
                flag = false;
            }
            else if(pos == M-1)
            {
                pos = 0;
                ++cont;
            }
            else
            {
                ++pos;
                ++cont;
            }
        }
        if(pos == NULL)
        {
            cout << "Elemento " << x << " n esta no vetor!" << endl;
        }
        else
        {
            cout << "Elemento " << x << " esta na lista!" << endl;
        }
    }

    void retira(E x)
    {
        E pos = x%M;
        int cont = 0;
        bool flag = true;

        while (vetorhash[pos] != x && cont < M && flag)
        {
            if(vetorhash[pos] == NULL)
            {
                flag = false;
            }
            else if (pos == M-1)
            {
                pos = 0;
                ++cont;
            }
            else
            {
                ++pos;
                ++cont;
            }
        }
        if(vetorhash[pos] == NULL)
        {
            cout << "Elemento n esta no vetor!" << endl;
        }
        else
        {
            vetorhash[pos] = NULL;
            --qte;
        }
    }
};

void abreArvore (Arvore<int>*bi)
{
    FILE *pfile;
    fpos_t position;
    int quantElementos;

    //insere
    pfile = fopen("teste10000.txt","rt");
    if(pfile == NULL)
        exit(0);
    fscanf(pfile, "%d", &quantElementos);
    fgetpos(pfile, &position);

    cout << "Quantidade de elementos: " << quantElementos << endl << endl;

    pessoa *p = new pessoa[quantElementos]; //vetor pessoa com n elementos;

    for(int i=0; i<quantElementos; i++)
    {
        fscanf(pfile, "%d \n", &p[i].chave);
        fgetpos(pfile, &position);
        fgets(p[i].nome, sizeof(p[i].nome), pfile);
        fgetpos(pfile, &position);
    }

    for(int i=0; i<quantElementos; i++)
    {
        bi->insere(p[i].chave); //insere elementos na arvore;
    }


    //Pesquisa
    int quantPesquisa;
    fscanf(pfile, "%d", &quantPesquisa);
    fgetpos(pfile, &position);

    int *pesquisa = new int[quantPesquisa]; //vetor pesquisa com val a ser pesquisados;
    for(int i=0; i<quantPesquisa; i++)
    {
        fscanf(pfile, "%d \n", &pesquisa[i]);
    }

    for(int i=0; i<quantPesquisa; i++)
    {
        bi->pesquisa(pesquisa[i]);
    }
    cout << endl;
    bi->imprimeAltura();
    fclose(pfile);
    delete [] p;
    delete [] pesquisa;
}

int calcPrimo (int primo)
{
    int cont = 0;
    int i = 1;
    bool flag1 = false;
    bool flag2 = false;
    while (1)
    {
        if(primo%i == 0)
        {
            ++cont;
            ++i;
        }
        else
            ++i;

        if(cont == 2)
            flag1 = true;
        else
            flag1 = false;

        if(i == primo+2)
        {
            flag2 = true;
            primo++;
            i=1;
            cont = 0;
        }

        if(flag1 && flag2)
            return primo;
    }
}

void abreHashing(HashLinear<int>*hlin)
{
    FILE *pfile;
    fpos_t position;
    int quantElementos;

    //insere
    pfile = fopen("teste10000.txt","rt");
    if(pfile == NULL)
        exit(0);
    fscanf(pfile, "%d", &quantElementos);
    fgetpos(pfile, &position);

    cout << "Quantidade de elementos: " << quantElementos << endl << endl;

    pessoa *p = new pessoa[quantElementos]; //vetor pessoa com n elementos;

    for(int i=0; i<quantElementos; i++)
    {
        fscanf(pfile, "%d \n", &p[i].chave);
        fgetpos(pfile, &position);
        fgets(p[i].nome, sizeof(p[i].nome), pfile);
        fgetpos(pfile, &position);
    }

    for(int i=0; i<quantElementos; i++)
    {
        hlin->insereHashLin(p[i].chave); //insere elementos no hashing;
    }


    //Pesquisa
    int quantPesquisa;
    fscanf(pfile, "%d", &quantPesquisa);
    fgetpos(pfile, &position);

    int *pesquisa = new int[quantPesquisa]; //vetor pesquisa com val a ser pesquisados;
    for(int i=0; i<quantPesquisa; i++)
    {
        fscanf(pfile, "%d \n", &pesquisa[i]);
    }

    for(int i=0; i<quantPesquisa; i++)
    {
        hlin->buscaVal(pesquisa[i]);
    }

    fclose(pfile);
    delete [] p;
    delete [] pesquisa;
}

#endif // CLASSEBINARIA_H_INCLUDED
