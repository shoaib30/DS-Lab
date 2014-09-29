#include<iostream>
using namespace std;
#define MAX 5
struct queue
{
    int items[MAX];
    int front,rear;
};
void insert(queue *q,int val)
{
    if((q->front==0 && q->rear==MAX-1) || (q->rear+1==q->front))
        cout<<" Circular Queue is Full";
    else
    {
        if(q->rear==MAX-1)
            q->rear=0;
        else
            q->rear++;
        q->items[q->rear]=val;
    }
    if(q->front==-1)
        q->front=0;
}
int remove(queue *q)
{
    int k;
    if(q->front==-1)
        cout<<"Circular Queue is Empty";
    else
    {
        k=q->items[q->front];
        if(q->front==q->rear)
            q->front=q->rear=-1;
        else
        {
            if(q->front==MAX-1)
                q->front=0;
        else
            q->front++;
        }
    }
    return k;
}
void display(queue *q)
{
    int i;
    if(q->front==-1)
        cout<<"Circular Queue is Empty";
    else
    {
        if(q->rear < q->front)
        {
            for(i=q->front;i<=MAX-1;i++)
                cout<<q->items[i]<<"   ";
            for(i=0;i<=q->rear;i++)
                cout<<q->items[i]<<"   ";
        }
        else
        {
            for(i=q->front;i<=q->rear;i++)
                cout<<q->items[i]<<"   ";
            cout<<endl;
        }
    }
}
int main()
{
    queue q;
    int i,x,ch,k=0;
    q.front=-1;
    q.rear=-1;
    cout<<"Choose :\n";
    while(k==0)
    {
        cout<<"\n1.Insert\n2.Remove\n3.Display\n4.Exit";
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
            display(&q);
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
