#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int stlen(char a[]);
void stcon(char a[], char b[],char st3[]);
int main()
{
    char st[50],st2[50],st3[100];
    int x;
    cout<<"Enter the string : ";
    gets(st);
    x=stlen(st);
    cout<<"\nString Lenght = "<<x;
    cout<<"\n\nEnter Another String : ";
    gets(st2);
    stcon(st,st2,st3);
    cout<<"\nConcatenated Strings : "<<st3;
    return 0;
}
int stlen(char a[50])
{
    int i;
    for(i=0;i<100;i++)
    {
        if(a[i]=='\0')
        {
            break;
        }
    }
    return i;
}
void stcon(char a[50],char b[50],char st3[100])
{
    int i,j=0,k=0;
    for(i=0;i<strlen(a);i++)
        st3[i]=a[i];
    for(j=0;j<strlen(b);j++,i++)
        st3[i]=b[j];
    st3[i+1]='\0';
}
