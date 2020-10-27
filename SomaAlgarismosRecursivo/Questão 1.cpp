//Criado por Pedro Figueiredo
//Faz soma ex: entrada: 1375 -> 1 + 3 + 7 + 5 = 16

#include <iostream>
using namespace std;

void fazSomaRecursiva(int num,int flag, int &tot)
{
    if(flag == 1)
    {
        tot+=num;
    }
    else
    {
        tot += num/flag;
        fazSomaRecursiva( (num%flag) , (flag/10) , tot);
    }
}

int main()
{

    int num = 13759;
    int flag = 10000;
    int tot;

    int uni,dez,cent,mil;

    mil = 1375/1000;
    cent = ((1375%1000)/100);
    dez = (((1375%1000)%100)/10);
    uni = (((1375%1000)%100)%10);


    cout << mil << endl;
    cout << cent << endl;
    cout << dez << endl;
    cout << uni << endl;

    fazSomaRecursiva(num,flag,tot);

    cout << tot << endl;
    return 0;
}
