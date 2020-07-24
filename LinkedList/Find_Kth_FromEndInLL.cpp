#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class node
{
	public:
	int v;
	node *next=NULL;
};
//Utility for list printing
void printll(node *head)
{
	node *ptr=head;
	if(head==NULL)
	cout<<"Empty List\n";
	while(ptr!=NULL)
	{
		cout<<ptr->v<<"-";
		ptr=ptr->next;
	}
	cout<<"X";
}
void find(node *start,int x)
{
	int p=1;
	node *temp=start;
	while(temp->v!=x and temp->next!=NULL)
	{
		p++;
		temp=temp->next;
	}
	if(temp->v==x)
		cout<<"Item found at position-> "<<p<<endl;
	else
		cout<<"Item does not found,End of list reached\n";

}


//Utility for Node creation
node * createNode(int x)
{
	node *p=new node();
	p->v=x;
	p->next=NULL;
	return p;
}
//...........Insertion Methods.........//
node *insertBeg(node *start,int x)
{
	node *ptr=createNode(x);
	if (start==NULL)
	{
		start=ptr;
		return start;
	}
	ptr->next=start;
	start=ptr;
	return start;
}
node *insertEnd(node *start,int x)
{
	node *temp=start;
	node *ptr=createNode(x);
	if (start==NULL)
	{
		start=ptr;
		return start;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=ptr;
	return start;
}
node *insertAfterX(node *start,int x,int y)
{
	node *temp=start;
	if (start==NULL)
		cout<<x<<" Not found, List is empty, Insertion failed...!!!\n";
	else
	{
		while(temp->v!=x and temp->next!=NULL)
			temp=temp->next;
		if(temp->v==x)
		{
			node *ptr=createNode(y);
			ptr->next=temp->next;
			temp->next=ptr;	
		}
		else
			cout<<x<<" Not found, Insertion failed...!!!\n";
	}
	return start;
}
////////////////////////////////////////////////////////////
//..................Deletion Methods.....................//
node *deleteStart(node *start)
{
		if(start==NULL)
		{
			cout<<"List is already empty\n";
			return start;
		}
		node *temp=start;
		start=start->next;
		delete temp;
		return start;	
}
node *deleteAMember(node *start,int x)	
{
	if(start==NULL)
	{
		cout<<"List is already empty\n";
		return start;
	}
	node *prev,*temp=start;
	while(temp->v!=x and temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	if (temp->next==NULL and temp->v!=x)
	{
		cout<<"End of the list reached,"<<x<<" not found, deletion  failed\n";
		return start;
	}
	else if(temp==start)
	{
		start=start->next;
		delete temp;
	}
	else
	{
		prev->next=temp->next;
		delete temp;
	}
	return start;
}
void findKthfromEnd(node *start,int k)
{
	map<int,node*> m;
	int i=0;
	while(start!=NULL)
	{
		
		m.insert({++i,start});
		start=start->next;
	}
	
	if (k<=i and k>0)
	{
		auto itr=m.find(i-k+1);
		cout<<itr->second->v;
	}
	else
	cout<<"length  of LL is "<<i<<" only";
	
}
int main()
{	
	node *start=NULL;
	std::srand(std::time(0));
//Insertion 5 elements in list
	for (int i=1;i <=5;i++)
		start=insertBeg(start,std::rand()%20);
//Insertion 5 more elements in list
	for (int i=1;i <=5;i++)
		start=insertEnd(start,i);
	printll(start);
	cout<<endl;	
	findKthfromEnd(start,11);
	cout<<endl;
	
	
return 0;
}
