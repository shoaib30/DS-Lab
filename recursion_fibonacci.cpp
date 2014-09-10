#include<iostream>
using namespace std;
int fib(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return (fib(n-1)+fib(n-2));
}
int main()
{
    int a;
    cout<<"Enter the number : ";
    cin>>a;
    cout<<"\nFibonacci : ";
    for(int i=1;i<=a;i++)
        cout<<fib(i)<<",";
    return 0;
}

