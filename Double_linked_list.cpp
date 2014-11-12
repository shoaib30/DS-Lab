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
NODE insert_front(NODE &head,int x)
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
NODE insert_rear(NODE &head,int x)
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
    NODE temp2=head;
    while(temp2->next!=NULL)
        temp2=temp2->next;
    temp->prev=temp2;
    temp2->next=temp;
    return head;
}
NODE delete_front(NODE &head)
{
    if(head==NULL)
    {
        cout<<"\nList Empty\n";
        return head;
    }
    cout<<"\nElement Removed : "<<head->data;
    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        return head;
    }
    NODE temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
}
NODE delete_rear(NODE &head)
{
    NODE temp=head;
    if(head==NULL)
    {
        cout<<"List Empty";
        return head;
    }
    else if(head->next==NULL)
    {
        cout<<"\nElement Removed : "<<head->data;
        delete head;
        head=NULL;
        return head;
    }
    while(temp->next->next!=NULL)
        temp=temp->next;
    cout<<"\nElement Removed : "<<temp->next->data;
    delete temp->next;
    temp->next=NULL;
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
NODE insert_position(NODE &head,int x,int pos)
{
    NODE temp=head;
    int i;
    NODE new_node=get_node();
    new_node->data=x;
    if(pos==1)
        return insert_front(head,x);
    for(i=1;i<pos-1&&temp->next!=NULL;i++)
        temp=temp->next;
    if(i<pos-1)
    {
        cout<<"\nInvalid Position\n";
        return head;
    }
    else if(temp->next==NULL)
        return insert_rear(head,x);
    new_node->next=temp->next;
    new_node->prev=temp;
    new_node->next->prev=new_node;
    temp->next=new_node;
    return head;
}
NODE delete_position(NODE &head,int pos)
{
    NODE temp=head;
    int i;
    if(head==NULL)
    {
        cout<<"List empty";
        return head;
    }
    if(pos==1)
    {
        return delete_front(head);
    }
    for(i=1;i<pos-1&&temp->next!=NULL;i++)
        temp=temp->next;
    if(i<pos-1)
    {
        cout<<"\nInvalid Position\n";
        return head;
    }
    else if(temp->next==NULL)
        return delete_rear(head);
    cout<<"\nElement removed : "<<temp->next->data;
    delete temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    return head;
}
int search_list(NODE head,int x)
{
    NODE temp=head;
    int pos=1;
    while(temp!=NULL)
    {
        if(temp->data==x)
            return pos;
        pos++;
        temp=temp->next;
    }
    return 0;
}
NODE delete_all_x(NODE &head,int x)
{
    int pos=1;
    while(pos)
    {
        pos=search_list(head,x);
        if(pos)
            head=delete_position(head,pos);
    }
    return head;
}
int main()
{
    NODE head=NULL;
    int ch,n=1,x,pos;
    cout<<"Enter choice";
    while(n==1)
    {
        cout<<"\n\n\n1.Insert Front"<<endl;
        cout<<"2.Insert Rear"<<endl;
        cout<<"3.Delete Front"<<endl;
        cout<<"4.Delete Rear"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Search"<<endl;
        cout<<"7.Insert at position"<<endl;
        cout<<"8.Delete at position"<<endl;
        cout<<"9.Delete all instances of"<<endl;
        cout<<"10.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            head=insert_front(head,x);
            break;
        case 2:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            insert_rear(head,x);
            break;
        case 3:
            head=delete_front(head);
            break;
        case 4:
            head=delete_rear(head);
            break;
        case 5:
            cout<<"\nList:  ";
            display(head);
            break;
        case 6:
            cout<<"\nEnter element to search : ";
            cin>>x;
            x=search_list(head,x);
            if(x!=0)
                cout<<"\nFound at : "<<x;
            else
                cout<<"\nNot Found ";
            break;
        case 7:
            cout<<"\nEnter Position to Insert at : ";
            cin>>pos;
            cout<<"\nEnter the element to insert : ";
            cin>>x;
            head=insert_position(head,x,pos);
            break;
        case 8:
            cout<<"\nEnter Position to Delete at : ";
            cin>>pos;
            head=delete_position(head,pos);
            break;
        case 9:
            cout<<"\nEnter the Element to delete : ";
            cin>>x;
            head=delete_all_x(head,x);
            break;
        case 10:
            n=0;
            break;
        default:
            cout<<"\nWrong Input.";
            break;
        }
    }
    return 0;
}

