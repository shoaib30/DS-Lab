#include<iostream>
#include<stack>
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
void make_tree(char exp[])
{
    int i=0;
    NODE x=NULL;
    while(exp[i++]!='\0')
    {
        x=get_node(exp[i]);
        if(isdigit(x->data))
            mstack.push(x);
        else
        {
            x->right=mstack.pop();
            x->left=mstack.pop();
            mstack.push(x);
        }
    }
    x=mstack.pop();
    return x;
}
void inorder(NODE p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<"->";
        inorder(p->right);
    }
}
void preorder(NODE p)
{
    if(p!=NULL)
    {
        cout<<p->data<<"->";
        preorder(p->left);
        preorder(p->right);
    }
}
