#include<iostream>
using namespace std;
#define size 10
struct stack
{
    int top;
    char items[size];
};
void disp(stack *s)
{
    int i;
    cout<<"\nDisplaying Stack: ";
    for(i=0;i<=s->top;i++)
    {
        cout<<s->items[i]<<",";
    }
}
int isFull(stack *s)
{
    if(s->top==size)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int isEmpty(stack *s)
{
    if(s->top<=-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void push(stack *s,char x)
{
    s->top+=1;
    s->items[s->top]=x;
}
char pop(stack *s)
{
    char temp=s->items[s->top];
    s->top--;
    return temp;
}
int main()
{
    int ch,k=0;
    char x;
    stack s;
    s.top=-1;
    cout<<"STACK\n\n Choose the option\n";
    while(k==0)
    {
        cout<<"\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                if(!(isFull(&s)))
                {
                    cout<<"\nEnter the number to push : ";
                    cin>>x;
                    push(&s,x);
                }
                else
                {
                    cout<<"Stack Overflow";
                }
                break;
            case 2:
                if(!(isEmpty((&s))))
                {
                    cout<<"popped : "<<pop(&s);
                }
                else
                {
                    cout<<"Stack Underflow";
                }
                break;
            case 3:
                disp(&s);
                break;
            case 4:
                k=5;
                break;
            default:
                cout<<"Wrong input";
                break;
        }
    }
    cout<<"\n\n\n\nEND!";
    return 0;
}
