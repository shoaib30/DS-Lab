#include<iostream>
using namespace std;
struct node
{
    int data;
    node *prev,*next;
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
NODE insert_order(NODE head,int x)
{
    NODE temp=get_node();
    temp->data=x;
    temp->next=temp->prev=NULL;
    if(head==NULL)
        head=temp;
    else if(x<=head->data)
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else
    {
        NODE temp2=head,temp3=head;
        while(x>temp3->data&&temp2!=NULL)
        {
            temp3=temp2;
            temp2=temp2->next;
        }
        temp->prev=temp3;
        temp->next=temp2;
        temp3->next=temp;
        return head;
    }
}
void display(NODE head)
{
    NODE temp=head;
    cout<<"\nList : ";
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    NODE head=NULL;
    int ch,n=1,x,pos;
    cout<<"Enter choice";
    while(n==1)
    {
        cout<<"\n1.Insert Front"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            head=insert_order(head,x);
            break;
        case 2:
            cout<<"\nList:  ";
            display(head);
            break;
        case 3:
            n=0;
            break;
        default:
            cout<<"\nWrong Input.";
            break;
        }
    }
    return 0;
}
