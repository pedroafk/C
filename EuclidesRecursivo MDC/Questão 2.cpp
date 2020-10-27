//Criado por Pedro Figueiredo
//Euclides Recursivo = MDC

#include <iostream>
using namespace std;

int Euclides(int m, int n)
{
    int r;
    do{
        r = m%n;
        m = n;
        n = r;

    }while (r != 0);
    return m;
}

int EuclidesRecursivo(int m,int n)
{
   if(n == 0)
    return m;

    return EuclidesRecursivo(n, m % n);
}

int main()
{
    int m = 37, n = 75;

    cout << Euclides(m,n) << endl;
    cout << EuclidesRecursivo(m,n) << endl;
    return 0;
}
