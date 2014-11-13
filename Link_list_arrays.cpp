#include<iostream>
using namespace std;
#define NUMNODE 10
struct element
{
    int val,next;
}nodelist[NUMNODE];
int avail=0;
int get_node()
{
    int p;
    if(avail==-1)
        cout<<"Overflow";
    else
    {
        p=avail;
        avail=nodelist[avail].next;
    }
    return p;
}
void insert_after(int b,int x)
{
    if(b==-1)//@shrey if u insert at a pos already taken its all mixed up
    {
        cout<<"Not Allowed";//@shoaib that's why we cannot have insert at pos... we can only have insert after pos... this function won't jumble it up
        return;
    }
    int q=get_node();
    nodelist[q].val=x;
    nodelist[q].next=nodelist[b].next;
    nodelist[b].next=q;
    return;
}
void free_node(int p)
{
    nodelist[p].next=avail; //shreyansh here: what if the node being deleted is in the middle of the list... then the element pointing to this deleted element will be pointing to avail and the next one wont be pointed by anyone 
    avail=p;
}
//int find_first()
//{
//    int i=
//
//}
void display()
{
    for(int i=0;i<NUMNODE;i++)
    {
        cout<<i<<". data :"<<nodelist[i].val;
        cout<<" -> next :"<<nodelist[i].next<<endl;
    }
}
void make_list()
{
    for(int i=0;i<NUMNODE-1;i++)
        nodelist[i].next=i+1;
    nodelist[NUMNODE-1].next=-1;
}
int main()
{
    make_list();
    int flag=1,x,pos,ch;
    while(flag)
    {
        cout<<"\n1.insert after";
        cout<<"\n2.Delete";
        cout<<"\n3.display";
        cout<<"\n4.exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter position to insert after :";
            cin>>pos;
            cout<<"Enter element to insert :";
            cin>>x;
            insert_after(pos,x);
            break;
        case 2:
            cout<<"Enter position to free :";
            cin>>pos;
            free_node(pos);
            break;
        case 3:
            cout<<"\nList: \n";
            display();
            break;
        case 4:
            flag=0;
            break;
        default:
            cout<<"Wrong input";
            break;
        }
    }
}
