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
    if(x==0)
        cout<<"Memory Full";
    return x;
}
NODE insert_front(NODE &root, int item)
{
    NODE temp;
    temp=get_node();
    temp->data=item;
    temp->link=root;
    return temp;
}
NODE delete_front(NODE &root)
{
    NODE temp;
    if(root==NULL)
    {
        cout<<"List Empty";
        return root;
    }
    temp=root;
    cout<<"Element Removed : "<<temp->data;
    root=root->link;
    return root;
}
void insert_rear(NODE &root,int item)
{
    NODE temp1,temp2;
    temp2=get_node();
    temp2->data=item;
    temp2->link=NULL;
    temp1=root;
    while(temp1->link!=NULL)
    {
        temp1=temp1->link;
    }
    temp1->link=temp2;
}
void delete_rear(NODE &root)
{
    NODE temp;
    temp=root;
    if(root==NULL)
    {
        cout<<"List Empty";
        return;
    }
    while((temp->link)->link!=NULL)
        temp=temp->link;
    cout<<"Element Removed : "<<(temp->link)->data;
    temp->link=NULL;
}
void display(NODE &root)
{
    NODE temp=root;
    if(root==NULL)
    {
        cout<<"\nList Empty";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
    }
}
int main()
{
    NODE root=NULL;
    int ch,n=1,x;
    cout<<"Enter choice";
    while(n==1)
    {
        cout<<"\n\n\n1.Insert Front"<<endl;
        cout<<"2.Insert Rear"<<endl;
        cout<<"3.Delete Front"<<endl;
        cout<<"4.Delete Rear"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            root=insert_front(root,x);
            break;
        case 2:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            insert_rear(root,x);
            break;
        case 3:
            root=delete_front(root);
            break;
        case 4:
            delete_rear(root);
            break;
        case 5:
            cout<<"\nList:  ";
            display(root);
            break;
        case 6:
            n=0;
            break;
        default:
            cout<<"\nWrong Input.";
            break;
        }
    }
    return 0;
}
