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
NODE insert_front(NODE root, int item,int &n)
{
    NODE temp;
    temp=get_node();
    temp->data=item;
    temp->link=root;
    n++;
    return temp;
}
NODE delete_front(NODE root,int &n)
{
    NODE temp;
    if(root==NULL)
    {
        cout<<"List Empty";
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
void insert_rear(NODE &root,int item,int &n)
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
    n++;
}
NODE delete_rear(NODE &root,int &n)
{
    NODE temp;
    temp=root;
    if(root==NULL)
    {
        cout<<"List Empty";
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
    while((temp->link)->link!=NULL)
        temp=temp->link;
    cout<<"Element Removed : "<<(temp->link)->data;
    delete temp->link;
    temp->link=NULL;
    n--;
    return root;
}
int search_list(NODE &root,int key)
{
    int pos=1;
    NODE temp=root;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return pos;
        }
        pos++;
        temp=temp->link;
    }
    return 0;
}
void display(NODE root,int &n)
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
    cout<<"\nTotal:"<<n;
}
NODE insert_position(NODE &root,int x,int pos,int &n)
{
    NODE temp=root,temp2;
    temp2=get_node();
    temp2->data=x;
    for(int i=1;i<pos-1;i++)
        temp=temp->link;
    temp2->link=temp->link;
    temp->link=temp2;
    n++;
    return root;
}
NODE delete_position(NODE &root,int pos,int &n)
{
    NODE temp=root;
    if(root==NULL)
    {
        cout<<"\nList Empty";
        return root;
    }
    else if(temp->link==NULL)
    {
        root=NULL;
        cout<<"\nElement Removed : "<<temp->data;
        return root;
    }
    else if(pos==1)
    {
        root=delete_front(root,n);
        return root;
    }
    for(int i=1;i<pos-1;i++)
        temp=temp->link;
    cout<<"\nElement Removed : "<<(temp->link)->data;
    temp->link=(temp->link)->link;
    n--;
    return root;
}
NODE delete_all_x(NODE &root,int x, int &n)
{
    NODE temp;
    int i=-1;
    while(i)
    {
        i=search_list(root,x);
        if(i>0)
            root=delete_position(root,i,n);
    }
    return root;
}
int main()
{
    NODE root=NULL;
    int ch,n=1,x,nodes=0,pos;
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
            root=insert_front(root,x,nodes);
            break;
        case 2:
            cout<<"\nEnter the element to enter : ";
            cin>>x;
            insert_rear(root,x,nodes);
            break;
        case 3:
            root=delete_front(root,nodes);
            break;
        case 4:
            root=delete_rear(root,nodes);
            break;
        case 5:
            cout<<"\nList:  ";
            display(root,nodes);
            break;
        case 6:
            cout<<"\nEnter element to search : ";
            cin>>x;
            x=search_list(root,x);
            if(x!=0)
                cout<<"\nFound at : "<<x;
            else
                cout<<"\nNot Found ";
            break;
        case 7:
            cout<<"\nEnter Position to Insert at : ";
            cin>>pos;
            if(pos>nodes)
            {
                cout<<"\nWrong Position";
                break;
            }
            cout<<"\nEnter the element to insert : ";
            cin>>x;
            root=insert_position(root,x,pos,nodes);
            break;
        case 8:
            cout<<"\nEnter Position to Delete at : ";
            cin>>pos;
            if(pos>nodes&&pos!=0)
            {
                cout<<"\nWrong Position";
                break;
            }
            root=delete_position(root,pos,nodes);
            break;
        case 9:
            cout<<"\nEnter the Element to delete : ";
            cin>>x;
            root=delete_all_x(root,x,nodes);
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
