#include<iostream>
#define size 10
using namespace std;
struct queue
{
    int items[size];
    int front,rear;
};
int isEmpty(queue *q)
{
    if(q->rear<q->front)
        return true;
    else
        return false;
}
int isFull(queue *q)
{
    if(q->rear>=(size-1))
        return true;
    else
        return false;
}
int remove(queue *q)
{
    if(!(isEmpty(q)))
        return q->items[q->front++];
    else
        cout<<"queue Empty";
        return -999;
}
void insert(queue *q,int x)
{
    int i;
    if(isEmpty(q))
    {
        q->front=0;
        q->rear=-1;
    }
    if(!(isFull(q)))
    {
        i=q->rear;
        while(i>=0&&q->items[i]>x)
        {
            q->items[i+1]=q->items[i];
            i--;
        }
        q->items[i+1]=x;
        ++q->rear;
    }
    else
        cout<<"Queue Full";
}
void disp(queue *q)
{
    if(isEmpty(q))
    {
        cout<<"queue Empty";
    }
    else
    {
        cout<<endl;
        for(int i=q->front;i<=q->rear;i++)
            cout<<q->items[i]<<"->";
        cout<<endl;
    }
}
int main()
{
    queue q;
    q.front=0;
    q.rear=-1;
    int k=0,ch,x;
    cout<<"Choose :\n";
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

