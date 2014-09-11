#include<iostream>
using namespace std;

void func (int n)
{
    if (n==1)
        cout<<1<<" ";
    else
    {
        func(n-1);
        cout<<n<<" ";
        func(n-1);
    }
}

int main()
{
    int x;
    cin>>x;
    func(x);
    return(0);
}
