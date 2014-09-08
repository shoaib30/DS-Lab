#include<iostream>
#include<string.h>
#define size 30
using namespace std;
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
void push(char x,stack *s)
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
int OP(char symbol,int op1,int op2)
{
    switch(symbol)
    {
    case '+':
        return (op1+op2);
    case '-':
        return (op1-op2);
    case '*':
        return (op1*op2);
    case '/':
        return (op1/op2);
    case '$':
    case '^':
        return (op1^op2);//can not use to the power of a double hence both operands are integers
    }
}
int main()
{
    int i,op1,op2,result;
    stack s;
    s.top=-1;
    char symbol,postfix[size];
    cout<<"Enter Postfix Expression : ";
    cin>>postfix;
    for(i=0;i<strlen(postfix);i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            push(symbol-'0',&s);
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            result=OP(symbol,op1,op2);
            push(result,&s);
        }
    }
    result=pop(&s);
    cout<<"\nAnswer = "<<result;
    return 0;
}
