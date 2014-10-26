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
NODE insert_front(NODE &last,int x,int &n)
{
    NODE temp=get_node();
    if(last==NULL)
    {
        last=temp;
        temp->link=last;
        temp->data=x;
        n++;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
    temp->data=x;
    n++;
    return last;
}
NODE insert_rear(NODE &last,int x,int &n)
{
    NODE temp;
    temp=get_node();
    if(last==NULL)
    {
        last=temp;
        temp->link=last;
        temp->data=x;
        n++;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
    temp->data=x;
    last=temp;
    n++;
    return last;
}
NODE delete_front(NODE &last,int &n)
{
    if(last==NULL)
    {
        cout<<"\nList Empty ";
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
    n--;
    return last;
}
NODE delete_rear(NODE &last,int &n)
{
    if(last==NULL)
    {
        cout<<"\nList Empty ";
        return last;
    }
    else if(last->link==last)
    {
        cout<<"\nDeleted :"<<last->data;
        last=NULL;
        return last;
    }
    NODE temp=last->link;
    cout<<"\nDeleted :"<<last->data;
    while(temp->link!=last)
        temp=temp->link;
    temp->link=(temp->link)->link;
    n--;
    return temp;
}
void disp(NODE last)
{
    if(last==NULL)
    {
        cout<<"\nList Empty ";
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
    int ch,n=1,x,nodes=0,pos;
    cout<<"Enter choice";
    while(n==1)
    {
        cout<<"\n\n\n1.Insert Front"<<endl;
        cout<<"2.Insert Rear"<<endl;
        cout<<"3.Delete Front"<<endl;
        cout<<"4.Delete Rear"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"10.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            last=insert_front(last,x,nodes);
            break;
        case 2:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            last=insert_rear(last,x,nodes);
            break;
        case 3:
            last=delete_front(last,nodes);
            break;
        case 4:
            last=delete_rear(last,nodes);
            break;
        case 5:
            disp(last);
            break;
        case 10:
            n=0;
            break;
        default:
            cout<<"\nWrong Input.";
            break;
        }
    }
}
