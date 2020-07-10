#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
using namespace std;
typedef struct edge
{
	int u,v;
	int w;
		
}edge;
void merging(edge[],int, int, int);
void merge_sort(edge[],int,int);
int find(int x, int par[])
{
	while(x!=par[x])
	x=par[x];
	return x;
}
int main()
{
	int n=0,V=0,E=0,it=0;
	cout<<"enter no. of vertices";
	cin>>V;
	cout<<"Enter no. of edges";
	cin>>E;
	cout<<"Enter U,V,W";
	edge graph[E];
	int u,v,w;
	while(it<E)
	{
		
		cout<<"u";	cin>>u;
		cout<<"v";	cin>>v;
		cout<<"w";	cin>>w;
		graph[it].u=u;	graph[it].v=v;	graph[it].w=w;
		it++; 		
		cout<<"Enter next edge\n";
	}	
	it=0;
	cout<<"Display graph\n";
	while(it<E)
	{
		cout<<graph[it].u<<"\t"<<graph[it].v<<"\t"<<graph[it].w<<"\t"<<endl;
		it++; 		
	}
////Sorting graph (edges)/////////////////
	merge_sort(graph,0,E-1);
	cout<<"Display graph after sorting\n";
	for(int i=0;i<E;i++)
	{
		cout<<graph[i].u<<"\t";
		cout<<graph[i].v<<"\t";
		cout<<graph[i].w<<"\t";
		cout<<endl;
	}
///////Direct Tree implementation ////////
	int par[V],rank[V];
	for(int i=0;i<V;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
	edge mst[V-1];
	int x=0;
	for(int i=0;i<E;i++)
	{
		int r=find(graph[i].u,par);
		int s=find(graph[i].v,par);
		if(r==s)
			continue;
		else
		{
			mst[x++]=graph[i];
			if(rank[r]>rank[s])
				par[s]=r;
			else	
				par[r]=s;
			if(rank[r]==rank[s])
				rank[s]=rank[s]+1;		
		}
	}
////////////////////////////////////////////////
	cout<<"Display MST\n";
	for(int i=0;i<V-1;i++)
	{
		cout<<mst[i].u<<"\t";
		cout<<mst[i].v<<"\t";
		cout<<mst[i].w<<"\t";
		cout<<endl;
	}
	return 0;
}
/////////////////////Merge Sort Code//////
void merging(edge r[],int low, int mid, int high)
{
		int i=low,j=mid+1,k=0;
		edge b[high-low+1];

		while(i<=mid && j<=high)
		{
			if(r[i].w<=r[j].w)
			b[k++]=r[i++];
			else b[k++]=r[j++]; 
		}
		//storing extra elements left, into the array//
		while(i<=mid) b[k++]=r[i++];
		while(j<=high) b[k++]=r[j++];
		//copying back into original array//
		for(i=low,k=0;i<=high;i++,k++) r[i]=b[k];
}	
void merge_sort(edge r[], int low,int high)
{
	if (low<high)
	{
		int mid =(low+high)/2;		
		merge_sort(r,low,mid);
		merge_sort(r,mid+1,high);		
		merging(r,low,mid,high);
	}
}	
