#include<iostream>
using namespace std;
struct stac
{
int top;
int item[10];
}A,B,C;
int isempty(stac s)
{
    if(s.top==-1)
    return true;
    else
    return false;
}
void push(stac &s, int x)
{

    s.top++;
    s.item[s.top]=x;
}
int pop(stac &s)
{
    return(s.item[s.top--]);
}
void display(stac s)
{
    if (isempty(s))
    cout<<"Empty";
    else
    {
        for(int i=0;i<=s.top;i++)
        cout<<s.item[i]<<" -> ";
        //cout<<endl;
    }
}
void towers(int n,stac &from,stac &to,stac &aux)
{
    if(n==1) // If there is only one disk
    {
        push(to,pop(from));
        //cout<<endl<<"move 1 from peg "<<from<<" to "<<to;
        return;
    }
    towers(n-1,from,aux,to); //Recursive Call
    push(to,pop(from));
    //cout<<endl<<"move "<<n<<" from peg "<<from<<" to "<<to;
    towers(n-1,aux,to,from);
}
int main()
{
    int n;
    A.top=-1;
    B.top=-1;
    C.top=-1;
    cout<<"entetr disc :";
    cin>>n;
    for(int i=n;i>0;i--)
        push(A,i);
    cout<<"PEG 1: ";display(A);cout<<endl;
    cout<<"PEG 2: ";display(B);cout<<endl;
    cout<<"PEG 3: ";display(C);cout<<endl<<endl;
    towers(n,A,C,B);
    cout<<"PEG 1: ";display(A);cout<<endl;
    cout<<"PEG 2: ";display(B);cout<<endl;
    cout<<"PEG 3: ";display(C);cout<<endl<<endl;
    return(0);
}
