#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}
int main()
{
    int a;
    cout<<"Enter the number : ";
    cin>>a;
    cout<<"\nFactorial of "<<a<<" = "<<fact(a);
    return 0;
}

