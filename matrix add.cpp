#include<iostream>
using namespace std;
void addmat(int a[2][2],int b[2][2],int c[2][2]);
int main()
{
    int x[2][2],y[2][2],i,j,z[2][2];
    cout<<"Enter 4 values of first matrix:\n";
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>x[i][j];
        }
    }
    cout<<"\n\nEnter 4 values of second matrix:\n";
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>y[i][j];
        }
    }
    addmat(x,y,z);
    cout<<"\n\nAdded Matrix is :-\n";
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cout<<z[i][j]<<"  ";
        }
        cout<<"\n";
    }
    return 0;
}
void addmat(int a[2][2],int b[2][2],int c[2][2])
{
    int i,j;

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}
