#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
typedef node* NODE;
NODE get_node()
{
    NODE x;
    x=new node;
    if(x==0)
        cout<<"\nMemory Full ";
    return x;
}
NODE insert_front(NODE &last,int x)
{
    NODE temp=get_node();
    if(last==NULL)
    {
        last=temp;
        temp->link=last;
        temp->data=x;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
    temp->data=x;
    return last;
}
NODE delete_front(NODE &last)
{
    if(last==NULL)
    {
        cout<<"\nStack Empty ";
        return last;
    }
    else if(last->link==last)
    {
        cout<<"\nDeleted :"<<last->data;
        last=NULL;
        return last;
    }
    cout<<"\nDeleted :"<<(last->link)->data;
    last->link=(last->link)->link;
    return last;
}
void disp(NODE last)
{
    if(last==NULL)
    {
        cout<<"\nStack Empty ";
        return;
    }
    NODE temp=last->link;
    while(temp!=last)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
    }
    cout<<last->data;
}
int main()
{
    NODE last=NULL;
    int ch,k=1,x;
    cout<<"Enter choice";
    while(k==1)
    {
        cout<<"\n\n\n1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            last=insert_front(last,x);
            break;
        case 2:
            last=delete_front(last);
            break;
        case 3:
            disp(last);
            break;
        case 4:
            k=0;
            break;
        default:
            cout<<"\nWrong Input.";
            break;
        }
    }
}

