#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int v;
    node *next;
    node *rand;    
    node(int data)
    {   
        v=data;
        next=nullptr;
        rand=nullptr;
    }
};
node * createNode(int x)
{
	node *p=new node(x);
	p->v=x;
	p->next=NULL;
	return p;
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
void printll(node *head)
{
    node *ptr=head;
	if(head==NULL)
	cout<<"Empty List\n";
/*
    for(int i=0;i<5;i++)
    {
		cout<<"{"<<ptr->v<<","<<ptr->rand->v<<"}"<<"--";
        ptr=ptr->next;
    }
*/
	while(ptr!=NULL)
	{
		cout<<"{"<<ptr->v<<","<<ptr->rand->v<<"}"<<"--";
		ptr=ptr->next;
	}
	cout<<"X"<<endl;
}
void makeRand(node *start)
{
    node *tmp=start;
    tmp->rand=tmp->next->next;
    tmp=tmp->next;

    tmp->rand=tmp->next->next;
    tmp=tmp->next;

    tmp->rand=start;
    tmp=tmp->next;
    
    tmp->rand=start->next;
    tmp=tmp->next;

    tmp->rand=start->next->rand;
    tmp=tmp->next;
}
void makeClone(node *start)
{
    map <node*, node*> m;
    node *ptr,*tmp=start;
    while(tmp!=NULL)
    {
        ptr=createNode(tmp->v);
        m.insert({tmp,ptr});
        tmp=tmp->next;
    }
//   for (auto itr = m.begin(); itr != m.end(); itr++) 
//       cout << itr->first->v << '\t' << itr->second->v<< '\n'; 
    tmp=start;
    while(tmp!=NULL)
    {
        auto itr=m.find(tmp);
        ptr=itr->second;
        itr=m.find(tmp->next);
        ptr->next=itr->second;
        itr=m.find(tmp->rand);
        ptr->rand=itr->second;
        tmp=tmp->next;
    }
    auto p1=m.find(start);
    p1->second;
    printll(p1->second);
}
void makeClone2(node *start)
{
    node *tmp=start,*ptr=NULL;
    while(tmp!=NULL)
    {   
        ptr=createNode(tmp->v);
        ptr->next=tmp->next;
        tmp->next=ptr;
        tmp=tmp->next->next;
    }
//    printll(start);
    tmp=start;
    while(tmp!=nullptr)
    {
        tmp->next->rand=tmp->rand->next;
        tmp=tmp->next->next;
    }
    printll(start);
    node *tmp1=start;
    node *head2=start->next;
    node *tmp2=head2;
    while(tmp1!=NULL && tmp2!=NULL)
    {
            tmp1->next=tmp1->next->next;
            if(tmp2->next!=NULL)
                tmp2->next=tmp2->next->next;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
    }
    printll(start);
    printll(head2);
}
int main()
{	
	node *start1=NULL,*start2=NULL;
    for (int i=0;i <5;i++)
		start1=insertEnd(start1,i+1);
//  printll(start1);
    makeRand(start1);
    printll(start1);
//  makeClone(start1);
    makeClone2(start1);
    return 0;
}