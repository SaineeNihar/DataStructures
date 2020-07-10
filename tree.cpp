#include<iostream>
using namespace std;
int index=0;
typedef struct node
{
	 int data;
	 node *lc,*rc;
}node;
node* makenode(int d)
{
	node *t=new node();
	t->data=d;
	t->lc=NULL;
	t->rc=NULL;
}
int find(int in[],int l,int h,int data)
{
	for(int i=l;i<h;i++)
		if(in[i]==data)
		return i;
}
node* buildtree(int in[],int pre[],int l,int h)
{
	
	if(l>h)
		return NULL;
	node *nd=makenode(pre[index++]);
	if(l==h)
		return nd;
	else
	{
		int i=find(in,l,h,nd->data);
		nd->lc=buildtree(in,pre,l,i-1);
		nd->rc=buildtree(in,pre,i+1,h);
	}
	return nd;
}
void postorder(node* root)
{
	if(root->lc!=NULL)	
		postorder(root->lc);
	if(root->rc!=NULL)
		postorder(root->rc);	
	cout<<root->data<<"\t";
}
int main()
{
	int in[]= {3,5,4,7,2,1};
	int pre[]={7,5,3,4,2,1};
	int size=sizeof(in)/sizeof(in[0]);
	node *root= buildtree(in,pre,0,size-1);
	postorder(root);	
return 0;	
}	
