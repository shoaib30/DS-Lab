#include<iostream>
#include<math.h>
#include<string.h>
#define parts 2550
#define size 30
using namespace std;
class integ
{
    protected:
    double ar,h;
    double ax[parts],ay[parts];
    double area()
    {
        double su=0.00;
        for(int i=1;i<parts-1;i++)
            su+=ay[i];
        ar=(h/2)*(ay[0]+ay[parts-1]+(2*su));
        return ar;
    }
    double area1()
    {
        double sue=0.00,suo=0.0;
        for(int i=1;i<parts-1;i+=2)
        {
                suo+=ay[i];
                sue+=ay[i+1];
        }
        sue-=ay[parts-1];
        ar=(h/3)*(ay[0]+ay[parts-1]+(4*suo)+(2*sue));
        return ar;
    }
};
class circle:public integ
{
    double r,j;
    public:
    void get_radius()
    {
        cout<<"Enter Radius : ";
        cin>>r;
    }
    void calc_x_y()
    {
        h=r/double(parts);
        j=0.0;
        for(int i=0;i<parts;i++)
        {
            ax[i]=j;
            j+=h;
        }
        for(int i=0;i<parts;i++)
            ay[i]=sqrt(r*r-ax[i]*ax[i]);
    }
    void display()
    {
        calc_x_y();
        cout<<"area : "<<area()*4<<endl;
        cout<<"area : "<<area1()*4<<endl;
        cout<<"area nor :"<<r*r*3.14<<endl;
    }
};
class rect:public integ
{
    double l,b,j;
    public:
    void get_side()
    {
        cout<<"Enter length : ";
        cin>>l;
        cout<<"Enter breath : ";
        cin>>b;
    }
    void calc_x_y()
    {
        h=b/double(parts);
        j=0.0;
        for(int i=0;i<parts;i++)
        {
            ax[i]=j;
            j+=h;
        }
        for(int i=0;i<parts;i++)
            ay[i]=(l/b)*ax[i];
    }
    void display()
    {
        calc_x_y();
        cout<<"area : "<<area()*2<<endl;
        cout<<"area : "<<area1()*2<<endl;
        cout<<"area nor :"<<l*b<<endl;
    }

};
/*class infi_post
{
    public:
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
};
class post_eval
{
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
    public:

};
class irregular:public integ,private infi_post
{
    char infix[size],postfix[size];
    public:
    void get_data()
    {
        cout<<"infix : ";
        cin>>infix;
    }
    void convert()
    {
        infix_postfix(infix,postfix);
        cout<<"\npost: "<<postfix;
    }

};*/
int main()
{
    circle c1;
    c1.get_radius();
    c1.display();
    rect r1;
    r1.get_side();
    r1.display();
    //irregular i1;
    //i1.get_data();
    //i1.convert();
    return (0);
}
