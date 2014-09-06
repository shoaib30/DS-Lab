#include<iostream>
using namespace std;
int fact(int x)
{
    int i,fa=1;
    for(i=1;i<=x;i++)
    {
        fa*=i;
    }
    return fa;
}
int main()
{
    int a,f;
    cout<<"Enter a number : ";
    cin>>a;
    f=fact(a);
    cout<<"Factorial = "<<f;
}
