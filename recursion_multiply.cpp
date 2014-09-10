#include<iostream>
using namespace std;
int mul(int a,int b)
{
    if(b==1)
        return a;
    else
        return (a+mul(a,b-1));
}
int main()
{
    int a,b;
    cout<<"Enter the two numbers : ";
    cin>>a>>b;
    cout<<"\n"<<a<<" * "<<b<<" = "<<mul(a,b);
    return 0;
}
