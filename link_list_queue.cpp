#include<iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};
typedef node* NODE;
NODE get_node()
{
    NODE x;
    x=new node;
    if(x==NULL)
        cout<<"Memory Full";
    return x;
}
NODE delete_front(NODE &root,int &n)
{
    NODE temp;
    if(root==NULL)
    {
        cout<<"Queue Empty";
        return root;
    }
    else if(root->link==NULL)
    {
        cout<<"Element Removed : "<<root->data;
        delete root;
        root=NULL;
        n--;
        return root;
    }
    temp=root;
    cout<<"Element Removed : "<<temp->data;
    delete temp;
    root=root->link;
    n--;
    return root;
}
NODE insert_rear(NODE root,int item)
{
    NODE temps,temp2;
    temp2=get_node();
    temp2->data=item;
    temp2->link=NULL;
    cout<<"test : "<<temp2;
    if(root==NULL)
    {
        root=temp2;
        return root;
    }
    temps=root;
    while(temps->link!=NULL)
    {
        temps=temps->link;
    }
    temps->link=temp2;
    return root;
}
void display(NODE root,int &n)
{
    NODE temp=root;
    if(root==NULL)
    {
        cout<<"\nQueue Empty";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<"\nTotal:"<<n;
}
int main()
{
    NODE root=NULL;
    int ch,n=1,x,nodes=0,pos;
    cout<<"Enter choice";
    while(n==1)
    {
        cout<<"\n1.Insert"<<endl;
        cout<<"2.Remove"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            cout<<"BLAF0";
            root=insert_rear(root,x);
            break;
        case 2:
            root=delete_front(root,nodes);
            break;
        case 3:
            cout<<"\nQueue:  ";
            display(root,nodes);
            break;
        case 4:
            n=0;
            break;
        default:
            cout<<"\nWrong Input.";
            break;
        }
    }
    return 0;
}
