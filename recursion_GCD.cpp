#include<iostream>
using namespace std;
int GCD(int m,int n)
{
    if(n==0)
        return m;
    else
        return (GCD(n,(m%n)));
}
int main()
{
    int a,b;
    cout<<"Enter the two numbers : ";
    cin>>a>>b;
    cout<<"\nGCD of "<<a<<" & "<<b<<" = "<<GCD(a,b);
    return 0;
}

