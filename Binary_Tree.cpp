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
NODE search_node(NODE root,int x)
{
    if(root==NULL)
        return NULL;
    else if(root->data==x)
        return root;
    else
    {
        if(root->data>x)
            return search_node(root->left,x);
        else
            return search_node(root->right,x);
    }
}
NODE largest(NODE root)
{
    if(root==NULL)
        return root;
    else if(root->right==NULL)
        return root;
    else
        return largest(root->right);
}
NODE smallest(NODE root)
{
    if(root==NULL)
        return root;
    if(root->left==NULL)
        return root;
    else
        return smallest(root->left);
}
int no_of_leaves(NODE root,int &i)
{
    if(root==NULL)
        return i;
    else if(root->right==NULL&&root->left==NULL)
        i++;
    else
    {
        i=no_of_leaves(root->left,i);
        i=no_of_leaves(root->right,i);
    }
    return i;
}
int total_nodes(NODE root,int &i)
{
    if(root==NULL)
        return i;
    else
    {
        i=total_nodes(root->left,i);
        i++;
        i=total_nodes(root->right,i);
    }
    return i;
}
int main()
{
    int flag=1,ch,x;
    NODE root=NULL,y;
    while(flag)
    {
        cout<<"\n1.Insert";
        cout<<"\n2.Preorder";
        cout<<"\n3.Inorder";
        cout<<"\n4.Postorder";
        cout<<"\n5.Search";
        cout<<"\n6.Largest Element";
        cout<<"\n7.Smallest Element";
        cout<<"\n8.Number of leaves";
        cout<<"\n9.Number of Nodes";
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
        case 5:
            cout<<"\nEnter the element to search : ";
            cin>>x;
            if(search_node(root,x)!=NULL)
                cout<<"\nElement Found ";
            else
                cout<<"\nElement not found";
            break;
        case 6:
            y=largest(root);
            if(y!=NULL)
                cout<<endl<<y->data<<" is the largest element ";
            else
                cout<<"List empty";
            break;
        case 7:
            y=smallest(root);
            if(y!=NULL)
                cout<<endl<<y->data<<" is the smallest element ";
            else
                cout<<"List empty";
            break;
        case 8:
            x=0;
            cout<<"\nNumber of leaves = "<<no_of_leaves(root,x);
            break;
        case 9:
            x=0;
            cout<<"\nTotal Number of Nodes = "<<total_nodes(root,x);
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
