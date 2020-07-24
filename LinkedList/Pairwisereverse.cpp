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
//////////////////////////////////////////////////////////////
void findLoop(node *start)
{
	map<node*,int> m;
	int i=0;	
	bool flag=true;
	while(start!=NULL)
	{
		
		const auto [itr,indicator]=m.insert({start,++i});
		if (indicator)
		start=start->next;
		else
		{	
			cout<<"Loop exists";
			flag=false;
			break;
		}
	}
	if (flag==true)
	{
		cout<<"Loop does not exists";
	}
	
}
////////////////////////////////////////////////////////////////
void floydFindLoop(node* start)
{
	node *ptr1=start,*ptr2=start;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1==ptr2)
		{
			cout<<"Loop Exists";
			return;
		}	
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}
	cout<<"Loop does not exists";
}
///////////////////////////////////////////////////////////////
void makeloop(node *start)
{
	node *temp=start;
	while(start->next!=NULL)
		start=start->next;
	start->next=temp->next->next->next->next;
}
///////////////////////////////////////////////////////////////
void printInReverse(node *start)
{
	if(start==NULL)
	return;
	else
	{
		printInReverse(start->next);
		cout<<start->v<<" ";		
	}
}
///////////////////////////////////////////////////////////////
node *mergesorted(node *start1,node *start2)
{
	node *result=NULL;
	if(start1==NULL)return start2;
	if(start2==NULL)return start1;
	if(start1->v<start2->v)
	{
		result=start1;
		result->next=mergesorted(start1->next,start2);
	}
	else
	{
		result=start2;
		result->next=mergesorted(start1,start2->next);
	}
	return result;
}
///////////////////////////////////////////////////////////////
node *pairwiseReverse(node *head)
{
	node *tmp;
	if(head==NULL|| head->next==NULL)
		return head;
	else
	{
		tmp=head->next;
		head->next=tmp->next;
		tmp->next=head;
		head=tmp;
		head->next->next=pairwiseReverse(head->next->next);
		return head;
	}
	

}
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
int main()
{	
	node *start1=NULL,*start2=NULL;
	std::srand(std::time(0));
//Insertion 5 elements in list
	for (int i=1;i <=11;i+=2)
		start1=insertEnd(start1,i);
//Insertion 5 more elements in list
	for (int i=2;i <=10;i+=2)
		start1=insertEnd(start1,i);
	printll(start1);
	cout<<endl;
	printll(start2);
	cout<<endl;
	//cout<<"Merged List"<<endl;	
	
	start1=pairwiseReverse(start1);
//	start1=mergesorted(start1,start2);
//	printInReverse(start);	
//	findLoop(start);
//	makeloop(start);
//	cout<<"By Floyd Algo"<<endl;	
//	floydFindLoop(start);
//	cout<<endl;	
//	findLoop(start);
	printll(start1);
	cout<<endl;
		
return 0;
}
