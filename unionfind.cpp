#include<iostream>
using namespace std;
int find(int x,int par[],int rank[])
{
	while(x!=par[x])
	x=par[x];
	return x;
}
void uni(int x,int y,int par[],int rank[])
{
	int r=find(x,par,rank),s=find(y,par,rank);
	if(r==s)
		return;
	if(rank[r]>rank[s])
		par[s]=r;
	else 
		par[r]=s; 
	if(rank[r]==rank[s])
	rank[s]=rank[s]+1;
}
int main()
{
	int n=3;
	int par[n],rank[n];
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
	int g[][n]={1,1,0,1,1,0,0,0,1};
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g[i][j])
				uni(i,j,par,rank);			
				
	for(int i=0;i<n;i++)
	cout<<par[i]<<" ";
	cout<<endl;
	int count=0;
	for(int i=0;i<n;i++)
	{
		int x=par[i];
		if(x!=999)
			for(int j=i+1;j<n;j++)
				if(x==par[j])
					par[j]=999;
	}
	for(int i=0;i<n;i++)
	if(par[i]!=999)
	count++;		
	cout<<count<<endl;
return 0;
}
