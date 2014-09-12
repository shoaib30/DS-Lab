#include<iostream>
using namespace std;
int b_search(int u,int l, int a[],int x)
{
    if(u>=l)
    {
        int mid=(u+l)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
            return b_search(mid-1,l,a,x);
        else if(a[mid]<x)
            return b_search(u,mid+1,a,x);
    }
    else
        return -5;
}
int main()
{
    int a[10],x,p,l=0,u=9;
    cout<<"Enter the elements of the array :";
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    cout<<"\n\nEnter the element to be searched :";
    cin>>x;
    p=b_search(u,l,a,x);
    if(p==-5)
        cout<<"Element not found";
    else
        cout<<"Element found at "<<p+1;
    return 0;
}
