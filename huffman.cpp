#include<iostream>
#include<cstring>
using namespace std;

typedef struct hp
{
	char c;
	int freq;
	struct hp *l=NULL;
	struct hp *m=NULL;
	struct hp *r=NULL;
	
}hp;
typedef struct cde
{
	char ch=' ';
	string s=" ";
}cde;

cde arr[8];
void movedown( hp* a[],int n,int i)
{
	int min=i;
	int l=3*i+1,m=3*i+2,r=3*i+3;
	if(l<n && a[l]->freq<a[min]->freq){ min=l;}
	if(r<n && a[m]->freq<a[min]->freq){	min=m;}
	if(r<n && a[r]->freq<a[min]->freq){	min=r;}
	if(min!=i)
	{
		hp* temp=a[i];
		a[i]=a[min];
		a[min]=temp;
		movedown(a,n,min);
		}
}
void buildheap(hp* a[],int n)
{
	int start=(n-2)/3;
	for(int i=start;i>=0;i--)
	{
		movedown(a,n,i);
	}
}
/////////////////////////////////////////////
hp* getmin(hp* a[],int **p)
{
	if(**p<=0)
	{
		cout<<"Empty heap!!!";		
	}
	hp* min=a[0];
	a[0]=a[**p-1];
	(**p)--;
	movedown(a,**p,0);
	return min;
}
//////////////////////////////////////////////
void moveup(hp* a[], int n,int i)
{
	int p=(i-1)/3;
	if(p>=0 && a[i]->freq<a[p]->freq)
	{
		hp* temp=a[i];
		a[i]=a[p];
		a[p]=temp;
		moveup(a,n,p);
	}
}
void insert( hp* a[], int **p,hp* temp)
{
	if((**p)>=50)
	{
		cout<<"Heap Full can't store!!!";
	}
	else
	{			
		(**p)++;
		a[**p-1]=temp;
		moveup(a,**p,(**p-1));
	}
}
//////////////////////////////////////////////////
void huffman(hp* a[],int *x)
{
	if(*x>1)
	{
		hp* temp=new(hp);
		int s=0;
		hp* t=new(hp);
		t=getmin(a,&x);
		s=s+(t->freq);
		temp->l=t;
		hp* t1=new(hp);
		
		t1=getmin(a,&x);
		s=s+(t1->freq);
		temp->m=t1;	
					
		hp* t2=new(hp);
		if(*x>1)
		{
			hp* t2=new(hp);
			t2=getmin(a,&x);
			s=s+(t2->freq);
			temp->r=t2;
		}
		temp->freq=s;
		temp->c=' ';
		insert(a,&x,temp);
		if(*x>1){huffman(a,x);}
	}	
		
}
/////////////Print Code////////////////
void code(hp* root,char c[],int index)
{	
	
    if (root->l) 
    { 
        c[index] = '0'; 
        code(root->l,c,index+1); 
    }
   	if (root->m) 
    { 
		c[index]='1';
        code(root->m,c, index+1); 
    } 
    if (root->r) 
    { 
		c[index]='2';
        code(root->r,c, index+1); 
    } 
    if (root->l==NULL && root->m==NULL && root->r==NULL)
    { 
    	static int ind=0;
        cout<<root->c<<"\t"; 
        arr[ind].ch=root->c;
        for(int i=0;i<index;i++)
        {cout<<c[i]<<"\t";
        arr[ind].s+=c[i];
        }
        ind++;
        cout<<endl;
    }
}
/////////////////////////////////////////////
int  main()
{
	hp *a[50];
	int n;
	char ch;
	cout<<"No of elements";
	cin>>n;
	int f;
	cout<<endl<<"Insert array elements\n";
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		cin>>f;
		hp* temp=new(hp);
		temp->freq=f;
		temp->c=ch;
		a[i]=temp;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]->c<<"\t";
		cout<<a[i]->freq<<endl;
	}	
	buildheap(a,n);	
	huffman(a,&n);
	hp* root=a[0];
	char c[10];
	code(root,c,0);
	cout<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<arr[i].ch<<"\t";
		cout<<arr[i].s<<endl;
	}	
/////////////////////////////////////////////////////////
	string str,ostr;
	cout<<"Enter the string for encoding : ";
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		for(int j=0;j<8;j++)
		{
			if(str[i]==arr[j].ch)
			{
				ostr+=arr[j].s;
				break;
			}		
		}
	}
	cout<<ostr;
return 0;
}
