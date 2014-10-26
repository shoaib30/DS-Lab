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
NODE delete_front(NODE &root,int &n)
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
    if(root==NULL)
    {
        root=temp2;
        temp2->link=NULL;
        n++;
        return root;
    }
    else if(pos==1)
    {
        temp2->link=root;
        root=temp2;
        n++;
        return root;
    }
    for(int i=1;i<pos-1;i++)
        temp=temp->link;
    temp2->link=temp->link;
    temp->link=temp2;
    n++;
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
int get_pos(NODE root,int x)
{
    int c=1;
    NODE temp=root;
    if(root==NULL)
        return c;
    else if(temp->data==x)
        return x;
    c++;
    while(temp->link!=NULL)
    {
        if(temp->link->data>=x)
            return c;
        temp=temp->link;
        c++;
    }
    return c;
}
NODE insert_order(NODE root,int x,int &n)
{
    NODE temp;
    int pos=get_pos(root,x);
    root=insert_position(root,x,pos,n);
    return root;
}
NODE merge_list(NODE root1,NODE root2,int &n)
{
    NODE temp1=root1,temp2=root2;
    int pos,x;
    while(temp2!=NULL)
    {
        x=temp2->data;
        pos=get_pos(root1,x);
        root1=insert_position(root1,x,pos,n);
        temp2=temp2->link;
    }
    return root1;
}
int main()
{
    NODE root1=NULL,root2=NULL,root3=NULL;
    int ch,ch1,n=1,x,nodes1=0,nodes2=0,pos;
    cout<<"Enter choice";
    while(n==1)
    {
        cout<<"\n1.LIST ONE"<<endl;
        cout<<"2.LIST TWO"<<endl;
        cout<<"3.MERGE LISTS into LIST ONE"<<endl;
        cout<<"4.EXIT"<<endl;
        cin>>ch1;
        if(ch1==1||ch1==2)
        {
            cout<<"\n\n\n1.Insert"<<endl;
            cout<<"3.Delete Front"<<endl;
            cout<<"4.Delete Rear"<<endl;
            cout<<"5.Display"<<endl;
            cout<<"15.Exit"<<endl;
            cin>>ch;
            switch(ch)
            {
            case 1:
                cout<<"\nEnter the element to enter : ";
                cin>>x;
                if(ch1==1)
                    root1=insert_order(root1,x,nodes1);
                else
                    root2=insert_order(root2,x,nodes2);
                break;
            case 3:
                if(ch1==1)
                    root1=delete_front(root1,nodes1);
                else
                    root2=delete_front(root2,nodes2);
                break;
            case 4:
                if(ch1==1)
                    root1=delete_rear(root1,nodes1);
                else
                    root2=delete_rear(root2,nodes2);
                break;
            case 5:
                cout<<"\nList:  ";
                if(ch1==1)
                    display(root1,nodes1);
                else
                    display(root2,nodes2);
                break;
            case 15:
                n=0;
                break;
            default:
                cout<<"\nWrong Input.";
                break;
            }
        }
        else if(ch1==3)
        {
            cout<<"1.Merge list one & two"<<endl;
            cout<<"2.Display Merged List"<<endl;
            cout<<"3.Exit"<<endl;
            cin>>ch;
            switch(ch)
            {
            case 1:
                root3=merge_list(root1,root3,nodes1);
                break;
            case 2:
                cout<<"\n\nMerged list : ";
                display(root3,nodes1);
                break;
            case 3:
                n=0;
                break;
            default:
                cout<<"\nWrong Input";
                break;
            }
        }
        else if(ch1==4)
            n=0;
    }
    return 0;
}

