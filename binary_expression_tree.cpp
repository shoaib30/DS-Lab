#include<iostream>
#include<stack>
#include<string.h>
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
//NODE set_left(NODE root,NODE x)
//{
//    if(root->left!=NULL)
//        return root;
//    root->left=x;
//    return root;
//}
//NODE set_right(NODE root,NODE x)
//{
//    if(root->right!=NULL)
//        return root;
//    root->right=x;
//    return root;
//}
stack<NODE>mstack;
NODE make_tree(char exp[])
{
    int i=0;
    NODE x=NULL;
    cout<<"check1";
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
int OP(char symbol,double op1,double op2)
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
void eval(NODE root)
{
    int x;
    if(isdigit(root->left->data)&&isdigit(root->right->data))
    {
        x=OP(root->data,root->left->data-'0',root->right->data-'0');
        delete root->left;
        delete root->right;
        root->data=x;
        root->right=root->left=NULL;
    }
    else()
    {
        root=root->left;
    }
}
int main()
{
    char post[20];
    cout<<"entr postfix expre"<<endl;
    cin>>post;
    cout<<"check2";
    NODE root=make_tree(post);
    cout<<"\n\n";
    inorder(root);
    cout<<"\n\n";
    preorder(root);
    return 0;
}
