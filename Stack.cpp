#include<iostream>
using namespace std;
struct stack
{
    int top;
    int items[10];
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
    if(s->top==10)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int isEmpty(stack *s)
{
    if(s->top<=-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void push(stack *s,int x)
{
    s->top+=1;
    s->items[s->top]=x;
}
int pop(stack *s)
{
    int temp=s->items[s->top];
    s->top--;
    return temp;
}
int main()
{
    int ch,x,k=0;
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
                if(isFull(&s))
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
                if(isEmpty((&s)))
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
