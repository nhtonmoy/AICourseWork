#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==0 || n==1) return n;
    else return fib(n-2)+fib(n-1);
}

void rec(int n)
{
    if(n <= 25)
    {
        cout<< fib(n) << " ";
        n++;
        rec(n);
    }
}

int main()
{
//    for(int i = 0; i <= 25; i++)
//    {
//        cout<< fib(i) << " ";
//    }

    rec(0);
    return 0;
}
