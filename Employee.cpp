#include<iostream>
using namespace std;
float inc(float sal,int exp)
{
    if((2014-exp)>=10)
        return (sal*10/100);
    else
        return (sal*5/100);
}
struct emp
{
    int exp;
    char name[20];
    float sal;
};
int main()
{
    emp e[10];
    int i;
    cout<<"Enter Employee Details :-";
    for(i=0;i<10;i++)
    {
        cout<<"\n\nEmployee : "<<i+1;
        cout<<"\nName: ";
        cin>>e[i].name;
        cout<<"Year of joining : ";
        cin>>e[i].exp;
        cout<<"Salary : ";
        cin>>e[i].sal;
    }
    cout<<"\n\nNEW Details :-";
    for(i=0;i<10;i++)
    {
        e[i].sal+=inc(e[i].sal,e[i].exp);
        cout<<"\n\nName : "<<e[i].name;
        cout<<"\nSalary : "<<e[i].sal;
    }
    return 0;
}
