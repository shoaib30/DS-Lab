#include<iostream>
#include<stack>
#include<string.h>
#include<math.h>
using namespace std;
struct node
{
    char data;
    node* left;
    node* right;
};
typedef node* NODE;
NODE get_node(char x)
{
    NODE n=new node;
    if(n==NULL)
        cout<<"Memory Full";
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}
stack<NODE>mstack;
NODE make_tree(char exp[])
{
    int i=0;
    NODE x=NULL;
    while(exp[i]!='\0')
    {
        x=get_node(exp[i]);
        if(isdigit(exp[i]))
            mstack.push(x);
        else
        {
            x->right=mstack.top();
            mstack.pop();
            x->left=mstack.top();
            mstack.pop();
            mstack.push(x);
        }
        i++;
    }
    x=mstack.top();
    mstack.pop();
    return x;
}
void inorder(NODE p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
void preorder(NODE p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(NODE p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
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
void eval(NODE &root)
{
    int x;
    if(root->left!=NULL&&root->right!=NULL)
    {
        if(isdigit(root->left->data)&&isdigit(root->right->data))
        {
            x=OP(root->data,(root->left->data-'0'),(root->right->data-'0'));
            delete root->left;
            delete root->right;
            root->data=x+'0';
            root->right=root->left=NULL;
        }
        else
        {
            eval(root->left);
            eval(root->right);
            eval(root);
        }
    }
}
int main()
{
    char post[20];
    cout<<"Enter postfix expression"<<endl;
    cin>>post;
    NODE root=make_tree(post);
    cout<<"\n\nInfix Expression: ";
    inorder(root);
    cout<<"\nPrefix Expression: ";
    preorder(root);
    cout<<"\nPostfix Expression: ";
    postorder(root);
    cout<<"\n\nEvaluated Answer: ";
    eval(root);
    cout<<root->data;
    return 0;
}
