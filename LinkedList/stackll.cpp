#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int v;
	node *next=NULL;

};

void push(node **tos,int v)
{
	node *temp=new node();
	temp->v=v; 

	if (*tos==NULL)
		*tos=temp;
	else
	{
		temp->next=*tos;
		*tos=temp;
	}
}
int main()
{
	node *tos=NULL;
	push(&tos,10);
	cout<<tos->v<<endl;
	push(&tos,20);
	cout<<tos->v<<endl;
	push(&tos,30);
	cout<<tos->v<<endl;
	push(&tos,40);
	cout<<tos->v<<endl;
//	int x=pop(&tos);		
return 0;
}
