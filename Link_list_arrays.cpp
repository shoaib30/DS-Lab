#include<iostream>
using namespace std;
#define NUMNODE 10
struct element
{
    int val,next;
}nodelist[NUMNODE];
int avail=-1;
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
    if(b==-1)
    {
        cout<<"Not Allowed";
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
    nodelist[p].next=avail;
    avail=p;
}
void display()
{

}
