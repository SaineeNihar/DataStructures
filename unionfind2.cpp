#include<iostream>
#include<list>
#include<climits>
using namespace std;
int find(int x,int par[])
{
	while(x!=par[x])
	x=par[x];
	return x;
}
void uni(int x,int y,int par[],int rank[])
{
	int r=find(x,par),s=find(y,par);
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
	int n=4,m=5;
	int g[][m]={1,1,1,1,0,
				1,1,0,1,0,
				1,1,0,0,0,
				0,0,0,0,1};
	int count=0;
	int par[n*m],rank[n*m];
	for(int i=0;i<n*m;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	
			if(g[i][j]==1)
			{
				if(j!=0&&g[i][j-1]==1)
				uni(count,count-1,par,rank);
				if(j!=m-1 && g[i][j+1]==1)
				uni(count,count+1,par,rank);
				if(i!=0&&g[i-1][j]==1)			
				uni(count,count-m,par,rank);				
				if(i!=n-1&&g[i+1][j]==1)
				uni(count,count+m,par,rank);			
			}
			else
			par[count]=-1;		
		count++;	
		}	
	}
	int ct=0;
	for(int i=0;i<n*m;i++)
	{
		if(par[i]!=-1)
		{
			int x=par[i];
			if(x!=999)
				for(int j=i+1;j<n*m;j++)
					if(x==par[j])
						par[j]=999;
		}
	}
	for(int i=0;i<n*m;i++)
	if(par[i]!=999&&par[i]!=-1)
	ct++;		
	cout<<ct<<endl;
	
	return 0;
}
