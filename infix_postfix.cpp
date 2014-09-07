#include<iostream>
#include<string.h>
using namespace std;
#define size 30
int G(char sy)
{
    switch(sy)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default :
        return 7;
    }
}
int F(char sy)
{
    switch(sy)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default :
        return 8;
    }
}
struct stack
{
    int top;
    char items[size];
};
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
    if(!(isFull(s)))
    {
        s->top+=1;
        s->items[s->top]=x;
    }
}
char pop(stack *s)
{
    if(!(isEmpty(s)))
    {
        char temp=s->items[s->top];
        s->top--;
        return temp;
    }
    else
        return 'n';
}
void infix_postfix(char infix[size],char postfix[size])
{

    stack s;
    s.top=-1;
    int i,j=0;
    char sym,ch;
    push(&s,'#');
    for(i=0;i<strlen(infix);i++)
    {
        sym=infix[i];
        while(F(s.items[s.top])>G(sym))
        {
            ch=pop(&s);
            if(ch!='n')
                postfix[j++]=ch;
        }
        if(F(s.items[s.top])!=G(sym))
        {
            push(&s,sym);
        }
        else
        {
            ch=pop(&s);
        }
    }
    while(s.items[s.top]!='#')
    {
        postfix[j++]=pop(&s);
    }
    postfix[j]='\0';
}
int main()
{
    char infix[size],postfix[size];
    cout<<"Enter the INFIX expression (without spaces) : ";
    cin>>infix;
    infix_postfix(infix,postfix);
    cout<<"\n\nPOSTFIX Expression : "<<postfix;
    return 0;
}
