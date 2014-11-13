#include<iostream>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
typedef node* NODE;
NODE get_node(int x)
{
    NODE n=new node;
    if(n==NULL)
        cout<<"Memory Full";
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}
NODE insert_node(NODE &parent,int x)
{
    if(parent==NULL)
        parent=get_node(x);
    else
    {
        if(parent->data>x)
            parent->left=insert_node(parent->left,x);
        else
            parent->right=insert_node(parent->right,x);
    }
    return parent;
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
void inorder(NODE p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<"->";
        inorder(p->right);
    }
}
void postorder(NODE p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<"->";
    }
}
int main()
{
    int flag=1,ch,x;
    NODE root=NULL;
    while(flag)
    {
        cout<<"\n1.Insert";
        cout<<"\n2.Preorder";
        cout<<"\n3.Inorder";
        cout<<"\n4.Postorder";
        cout<<"\n10.Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\n\nEnter element : ";
            cin>>x;
            root=insert_node(root,x);
            break;
        case 2:
            cout<<"\nPreorder :";
            preorder(root);
            break;
        case 3:
            cout<<"\nInorder :";
            inorder(root);
            break;
        case 4:
            cout<<"\nPostorder :";
            postorder(root);
            break;
        case 10:
            flag=0;
            break;
        default:
            cout<<"Wrong option";
            break;
        }
    }
}
