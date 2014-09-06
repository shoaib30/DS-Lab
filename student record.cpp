#include<iostream>
#include<stdio.h>
using namespace std;
struct stud
{
    char name[20];
    int age,marks[3];
};
int main()
{
    int i,j;
    stud s[10];
    cout<<"Enter details of students:-\n";
    for(i=0;i<10;i++)
    {
        cout<<"Student : "<<i+1<<"\n";
        cout<<"Name:";
        cin>>(s[i].name);
        cout<<"Age:";
        cin>>s[i].age;
        cout<<"Marks:\n";
        for(j=0;j<3;j++)
        {
            cout<<"Subject "<<j+1<<" : ";
            cin>>s[i].marks[j];
        }
        cout<<"\n";
    }
    cout<<"\n\n\nDetails of all students";
    for(i=0;i<10;i++)
    {
        cout<<"\nName : "<<s[i].name;
        cout<<"\nAge : "<<s[i].age;
        cout<<"\nMarks :- ";
        for(j=0;j<3;j++)
        {
            cout<<"\nSubject "<<j+1<<" : "<<s[i].marks[j];
        }
        cout<<"\n\n";
    }
    return 0;
}
