#include<iostream>
using namespace std;
int fib(int x)
{
    int i,c,a=0,b=1;
    if(x>=1)cout<<a;
    if(x>=2)cout<<","<<b;
    for(i=3;i<=x;i++)
    {
        c=a+b;
        cout<<","<<c;
        a=b;
        b=c;
    }
}
int main()
{
    int a,f;
    cout<<"Enter a number : ";
    cin>>a;
    cout<<"\n\nFibonacci series : ";
    f=fib(a);
    return 0;
}

