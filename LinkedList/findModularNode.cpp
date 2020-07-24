#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class node
{

	public:
	int v;
	node *next=NULL;
    node(int data)
    {
        v=data;
    }
};
/////////////////Utility for list printing/////////////////////////////////////
void printCircular(node *head)
{
	node *ptr=head;
	if(head==NULL)
	cout<<"Empty List\n";
	do
	{
		cout<<ptr->v<<"-";
		ptr=ptr->next;
	}while(ptr!=head);
	cout<<"X"<<endl;
}
//-------------------------------------------------------------------------//
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
	cout<<"X"<<endl;
}
///////////////////////////////////////////////////////////////////////////////
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
	node *p=new node(x);
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
void makeCircular(node *start){
	node *ptr=start;
	if (start==NULL)
	return;
	while(ptr->next!=NULL)
	ptr=ptr->next;

	ptr->next=start;
}
node *splitLL(node *head)
{
	node *ptr1=head,*ptr2=head;
	do 
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	
	}while(ptr2->next!=head && ptr2->next->next!=head);
	if(ptr2->next==head)
	{
		cout<<"odd"<<endl;
		node *tmp=ptr1->next;
		ptr1->next=head;
		ptr2->next=tmp;
		return tmp;
	}	
	else if(ptr2->next->next==head)
	{
		cout<<"even"<<endl;
		node *tmp=ptr1->next;
		ptr1->next=head;
		ptr2->next->next=tmp;
		return tmp;
	}	
}
////////////////////////////////////////////////////////////////
node *reverse (node *head, int k)  
{  
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }
    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)  
    head->next = reverse(next, k);    
    /* prev is new head of the input list */
    return prev;  
}
///////////////////////////////////////////////////////////////
node *findJodephus(node *start1,int n,int m)
{
    node *head=start1;
    int count=n;
    cout<<"deleted nodes \n";
    for(count=n;count>1;count--)
    {
        for(int i=1;i<m-1;i++)
            head=head->next;          
        cout<<head->next->v<<" "; 
        head->next=head->next->next;
        head=head->next;
    }
    cout<<endl;
    return head;
}
///////////////////////////////////////////////////////////////
void splitEvenOdd(node *start)
{
    node *e=NULL,*o=start,*tmp=start,*head1,*head2;
    int c1=1,c2=1;
    while(tmp)
    {
        if(tmp->v%2==0)
            if(c1)
            {    
                e=tmp;
                head1=e;
                c1--;
            }
            else
            {
                e->next=tmp;
                e=tmp;
            }
        else
        {
            if(c2)
            {
                o=tmp;
                head2=o;
                c2--; 
            }
            else
            {
                o->next=tmp;
                o=tmp;
            }
        }              
        tmp=tmp->next;
    }
    o->next=NULL;
    e->next=NULL;
    printll(head1);
    printll(head2);
    e=head1;
    while(e->next!=NULL)
        e=e->next;
    e->next=head2;
    printll(head1);
    

}
///////////////////////////////////////////////////////////////
void findModularNode(node *start, int k)
{
    node *tmp=NULL;
    int count=0;
    while(start)
    {
        count++;
        if(count%k==0)
            tmp=start;
        start=start->next;
    }
    if(tmp)
        cout<<tmp->v<<endl;
}
///////////////////////////////////////////////////////////////
int main()
{	
	node *start1=NULL,*start2=NULL;
	std::srand(std::time(0));
//Insertion 5 elements in list
	int i;
    for (i=1;i <=12;i++)
		start1=insertEnd(start1,i);
//	for (int i=2;i<=10;i+=2) 
//Insertion 5 more elements in list
//		start1=insertEnd(start1,i);
	printll(start1);
    findModularNode(start1,5);

//	cout<<endl;
//    splitEvenOdd(start1);
//	makeCircular(start1);
//    printCircular(start1);
//    node *head=findJodephus(start1,i-1,2);
//    cout<<head->v;
//	printCircular(start1);
//    start1=reverse(start1,3);
//	printll(start1);
//	start2=splitLL(start1);
//	start1=pairwiseReverse(start1);
//	start1=mergesorted(start1,start2);
//	printInReverse(start);	
//	findLoop(start);
//	makeloop(start);
//	cout<<"By Floyd Algo"<<endl;	
//	floydFindLoop(start);
//	cout<<endl;	
//	findLoop(start);
	cout<<endl;
return 0;
}