#include<iostream>
using namespace std;
struct node
{
    char data;
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
NODE insert_front(NODE &head,char x)
{
    NODE temp=get_node();
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    temp->next=head;
    head=temp;
    return head;
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
NODE make_string_list(NODE &head,char a[])
{
    for(int i=0;a[i]!='\0';i++)
        head=insert_front(head,a[i]);
    return head;
}
int palin(NODE &head)
{
    NODE temp1=head,temp2=head;
    while(temp2->next!=NULL)
        temp2=temp2->next;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
            return false;
        temp1=temp1->next;
        temp2=temp2->prev;
    }
    return true;
}
int main()
{
    NODE head=NULL;
    int x;
    cout<<"Enter length of string : ";
    cin>>x;
    char a[x];
    cout<<"Enter the string : ";
    cin>>a;
    head=make_string_list(head,a);
    if(palin(head))
        cout<<"\nString is palindrome ";
    else
        cout<<"\nString is NOT palindrome";
    return 0;
}
