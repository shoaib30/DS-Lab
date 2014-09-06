#include<iostream>
using namespace std;
float avg(float na[])
{
	int i;
	float a,s=0;
	for(i=0;i<10;i++)
	{
		s+=na[i];
	}
	a=s/10;
	return a;
}
int main()
{
	float nos[10];
	float av;
	cout<<"Enter 10 Floating numbers :\n";
	for(int i=0;i<10;i++)
    {
        cin>>nos[i];
    }
	av=avg(nos);
	cout<<"Avg = "<<av;
	return 0;
}
