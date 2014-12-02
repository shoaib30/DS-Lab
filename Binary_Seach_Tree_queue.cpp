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
        else if(parent->data<x)
            parent->right=insert_node(parent->right,x);
    }
    return parent;
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
NODE delete_node(NODE root)
{
    if(root==NULL)
    {
        cout<<"Queue Empty";
        return root;
    }
    NODE temp1=root,temp2=root;
    while(temp1->left!=NULL)
    {
        temp2=temp1;
        temp1=temp1->left;
    }
    if(temp1==root)
        root=root->right;
    else
        temp2->left=temp1->right;
    cout<<"\nRemoved : "<<temp1->data;
    delete temp1;
    return root;
}
int main()
{
    NODE root=NULL;
    int x,k=1,ch;
    while(k)
    {
        cout<<"\n1.Insert\n2.Remove\n3.Display\n4.Exit";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter Element : ";
            cin>>x;
            root=insert_node(root,x);
            break;
        case 2:
            root=delete_node(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            k=0;
            break;
        default:
            cout<<"\nWrong option";
            break;
        }
    }
}
