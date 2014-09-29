#include<iostream>
#define size 6
using namespace std;
struct queue
{
    int items[size];
    int front,rear;
};
int isFull(queue *q)
{
    if((q->rear-q->front)==(size-1))
        return true;
    else
        return false;
}
int isEmpty(queue *q)
{
    if((q->rear-q->front)==-1)
        return true;
    else
        return false;
}
void insert(queue *q,int y)
{
    int x;
    if(!(isFull(q)))
    {
        q->rear++;
        x=q->rear%size;
        q->items[x]=y;
    }
    else
        cout<<"\nQueue Overflow";
}
int remove(queue *q)
{
    int x;
    if(!(isEmpty(q)))
    {
        x=q->front%size;
        q->front++;
        return q->items[x];
    }
    else
        cout<<"\nQueue underflow ";
    return -999;
}
void disp(queue *q)
{
    int x,y;
    if(!(isEmpty(q)))
    {
        x=q->front%size;
        y=q->rear%size;
        cout<<endl;
        if(y<x)
        {
            for(int i=x;i<=size-1;i++)
                cout<<q->items[i]<<"->";
            for(int i=0;i<=y;i++)
                cout<<q->items[i]<<"->";
        }
        else
        {
            for(int i=x;i<=y;i++)
                cout<<q->items[i]<<"->";
        }
        cout<<endl;
    }
    else
        cout<<"\nQueue Empty\n ";
}
int main()
{
    queue q;
    int i,x,ch,k=0;
    q.front=0;
    q.rear=-1;
    cout<<"Choose :";
    while(k==0)
    {
        cout<<"\n\n1.Insert\n2.Remove\n3.Display\n4.Exit";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter Value to insert :";
            cin>>x;
            insert(&q,x);
            break;
        case 2:
            x=remove(&q);
            if(x!=-999)
                cout<<"\nElement removed : "<<x;
            cout<<endl;
            break;
        case 3:
            disp(&q);
            break;
        case 4:
            cout<<"\nEnd";
            k=1;
            break;
        default:
            cout<<"wrong input";
            break;
        }
    }
    cout<<"END";
}
