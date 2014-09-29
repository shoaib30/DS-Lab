#include<iostream>
#include<string.h>
#define size 30
#include<math.h>
using namespace std;
struct stack
{
    int top;
    char items[size];
};
void push(char x,stack *s)
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
        return (pow(op1,op2));
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
