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
NODE insert_pos(NODE &last,int x,int pos,int &n)
{
    NODE temp=get_node();
    NODE curr;
    int i=1;
    temp->data=x;
    temp->link=NULL;
    if(last==NULL)
        return temp;
    curr=last->link;
    if(pos==1)
        return insert_front(last,x,n);
    while(i<pos-1&&curr!=NULL)
    {
        curr=curr->link;
        i++;
    }
    if(pos==n+1)
    {
        return insert_rear(last,x,n);
    }
    temp->link=curr->link;
    curr->link=temp;
    n++;
    return last;
}
NODE delete_pos(NODE &last,int pos,int &n)
{
    NODE temp;
    int i=1;
    if(last==NULL)
    {
        cout<<"\nList Empty\n";
        return last;
    }
    else if(last->link==NULL)
    {
        last=NULL;
        return last;
    }
    if(pos==1)
    {
        return delete_front(last,n);
    }
    temp=last->link;
    while(i<pos-1&&temp!=NULL)
    {
        temp=temp->link;
        i++;
    }
    if(temp->link==last)
    {
        return delete_rear(last,n);
    }
    cout<<"\nDeleted :"<<temp->link->data;
    temp->link=temp->link->link;
    n--;
    return last;
}
int search(NODE &last,int x,int &n)
{
    int f=0;
    if(last==NULL)
        return f;
    NODE temp=last->link;
    while(temp!=last)
    {
        f++;
        if(temp->data==x)
            return f;
        temp=temp->link;
    }
    if(last->data==x)
        return ++f;
    return 0;
}
NODE insert_after_key(NODE &last,int x,int key,int &n)
{
    int pos=search(last,key,n);
    if(pos)
    {
        return insert_pos(last,x,pos+1,n);
    }
    else
    {
        cout<<"\nElement not found "<<endl;
        return last;
    }
}
NODE delete_after_key(NODE &last,int key,int &n)
{
    int pos=search(last,key,n);
    if(pos)
    {
        return delete_pos(last,pos+1,n);
    }
    else
    {
        cout<<"\nElement not found "<<endl;
        return last;
    }
}
void disp(NODE last,int n)
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
    cout<<"\nNodes :"<<n<<endl;
}
int main()
{
    NODE last=NULL;
    int ch,k=1,x,nodes=0,pos;
    cout<<"Enter choice";
    while(k==1)
    {
        cout<<"\n\n\n1.Insert Front"<<endl;
        cout<<"2.Insert Rear"<<endl;
        cout<<"3.Delete Front"<<endl;
        cout<<"4.Delete Rear"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Insert At Position"<<endl;
        cout<<"7.Delete at Position"<<endl;
        cout<<"8.Search"<<endl;
        cout<<"9.Insert after key "<<endl;
        cout<<"10.Delete after key "<<endl;
        cout<<"11.Exit"<<endl;
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
            disp(last,nodes);
            break;
        case 6:
            cout<<"\nEnter Position to insert : ";
            cin>>pos;
            if(pos<=nodes+1)
            {
                cout<<"\nEnter element to enter : ";
                cin>>x;
                last=insert_pos(last,x,pos,nodes);
            }
            else
                cout<<"\nWrong position"<<endl;
            break;
        case 7:
            cout<<"\nEnter position to Delete : ";
            cin>>pos;
            if(pos<=nodes)
            {
                last=delete_pos(last,pos,nodes);
            }
            else
                cout<<"\nWrong Position"<<endl;
            break;
        case 8:
            cout<<"\nEnter element to search : ";
            cin>>x;
            cout<<x<<" found at "<<search(last,x,nodes)<<endl;
        case 9:
            cout<<"\nEnter the Key :" ;
            cin>>pos;
            cout<<"\nEnter Element to enter : ";
            cin>>x;
            last=insert_after_key(last,x,pos,nodes);
            break;
        case 11:
            k=0;
            break;
        default:
            cout<<"\nWrong Input.";
            break;
        }
    }
}
