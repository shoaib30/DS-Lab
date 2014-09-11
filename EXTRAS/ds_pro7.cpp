#include<iostream>
using namespace std;
int counter=0;
int x[100];
int findloc(int n)
{
    for(int i=0;i<100;i++)
        if(x[i]==n)
            return i;

}
struct stac
{
    int top;
    int it[10];
}a,b,c;

void push(stac *s,int a)
{
    s->top++;
    s->it[s->top]=a;
}
int fin(stac *s, int a)
{
    if (s->it[s->top]==a)
    return true;
    else
    return false;
}
int pop(stac *s)
{
    return s->it[s->top--];
}
void display(stac s)
{
    for(int i=s.top;i>0;i--)
    cout<<s.it[i]<<endl;
}
void series (int n)
{
    if (n==1)
        x[counter++]==1;
    else
    {
        series(n-1);
        x[counter++]=n;
        series(n-1);
    }
}

void func(stac s,stac t, stac d,int n)
{
    //cout<<"h";
    int i;
    if (n==0)
    {
    func(t,s,d,t.top);cout<<"c";
    }
    else
    {

        int loc=findloc(n);
        if(n%2==0)
        {
            for(i=0;i<=loc;i++)
            {
                if(fin(&s,x[i]))
                {
                    if(x[i]%2==0)
                        push(&d,pop(&s));
                    else
                        push(&t,pop(&s));

                }
                else if(fin(&t,x[i]))
                {
                     if(x[i]%2==0)
                        push(&s,pop(&t));
                    else
                        push(&d,pop(&t));
                }
                else if(fin(&d,x[i]))
                {
                     if(x[i]%2==0)
                        push(&t,pop(&d));
                    else
                        push(&s,pop(&d));
                }

            }
            func(s,t,d,n-1);  //continue from here
        }
        else if(n%2!=0)
        {
            for(i=0;i<=loc;i++)
            {
                if(fin(&s,x[i]))
                {
                    if(x[i]%2==0)
                        push(&t,pop(&s));
                    else
                        push(&d,pop(&s));

                }
                else if(fin(&t,x[i]))
                {
                     if(x[i]%2==0)
                        push(&d,pop(&t));
                    else
                        push(&s,pop(&t));
                }
                else if(fin(&d,x[i]))
                {
                     if(x[i]%2==0)
                        push(&s,pop(&d));
                    else
                        push(&t,pop(&d));
                }

            }
            func(s,t,d,n-1);
        }
    }


}

int main()
{
    int n=3;
    series(n);
    a.top=0;b.top=0;c.top=0;
    push(&a,3);
    push(&a,2);
    push(&a,1);
    for(int i=0;i<15;i++)
    cout<<x[i];cout<<",";
    display(a);cout<<endl<<endl;
    display(b);cout<<endl<<endl;
    display(c);cout<<endl<<endl;
    cout<<"sadasd";
    func(a,b,c,n);
    cout<<"asd";
    display(a);
    cout<<endl<<endl;
    display(b);
    cout<<endl<<endl;
    display(c);


    return(0);
}
