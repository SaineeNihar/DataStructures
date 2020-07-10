#include<iostream>
#include<list>
#include<bits/stdc++.h>

using namespace std;
int cnt,cntr;
class Graph
{
	int V;
	list<int> *adj;
	list<int> *transpose;
	int *st,*end,*par;
	bool *b;
	public: 
	Graph(int V);
	void addEdge(int v,int w);
	void transposelist();
	void dfs();
	void dfsrec(int v,bool b[]);
	void print();
	void dfs2();
	void dfsrec2(int v,bool b[]);
	int isContinue();
};
////////////////////////////////////////////////////////
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
	st=new int[V];
	end=new int[V]; 
	transpose=new list<int>[V];
	b=new bool[V];
}
void Graph::transposelist()
{
	list<int>::iterator i;
	for(int v=0;v<V;v++)
	{	
		for(i=adj[v].begin();i!=adj[v].end();++i)
		{
			transpose[*i].push_back(v);
		}	
	}	
}
void Graph::addEdge(int v,int w)
{
	adj[v-1].push_back(w-1);
}
///////////////////////////////////////////////////////////////////
void Graph::dfsrec(int v,bool b[])
{
	b[v]=true;
	st[v]=++cnt;
//	cout<<v+1<<"\t";
	list<int>::iterator i; 
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!b[*i])
		{
			dfsrec(*i,b);
		}
	}
	end[v]=++cnt;
}
void Graph::dfs()
{
	bool *b=new bool[V];
	for(int i=0;i<V;i++)
		b[i]=false;
	for(int i=0;i<V;i++)
		if(!b[i])
		{	
			cntr++;
			dfsrec(i,b);
		}
//	print();
}
///////////////////////////////////////////////////////////////////
void Graph::dfsrec2(int v,bool b[])
{
	b[v]=true;
	cout<<v+1<<"\t";
	list<int>::iterator i; 
	for(i=transpose[v].begin();i!=transpose[v].end();i++)
	{
		if(!b[*i])
		{
			dfsrec2(*i,b);
		}
	}
}
int Graph::isContinue()
{
	int index=-1;
	int max=0;
	for(int i=0;i<V;i++)
	{
		if(max<end[i] && !b[i])
		{
			index=i;
			max=end[i];		
		}
	}
	
	return index;
}
void Graph::dfs2()
{
	for(int i=0;i<V;i++)
		b[i]=false;
	int i=1;
	cntr=0;
	while(i!=-1)
	{	
		i=isContinue();
		if(i!=-1)
		{	
			cout<<endl;
			cntr++;
			dfsrec2(i,b);
		}
	}
	cout<<endl<<"No of connected components\t"<<cntr<<endl;
}
void Graph::print()
{
	cout<<endl;
	cout<<"Vertex"<<"\t"<<"Start"<<"\t"<<"End"<<endl;
	for(int i=0;i<V;i++)
		cout<<i<<"	"<<st[i]<<"\t"<<end[i]<<endl;
}
int main()
{
	Graph g(12);
	g.addEdge(2,1);
	g.addEdge(3,2);
	g.addEdge(4,2);
	g.addEdge(5,2);
	g.addEdge(2,5);
	g.addEdge(3,6);
	g.addEdge(6,3);
	g.addEdge(7,5);
	g.addEdge(8,6);
	g.addEdge(11,8);
	g.addEdge(8,7);
	g.addEdge(7,9);
	g.addEdge(9,10);
	g.addEdge(10,7);
	g.addEdge(10,12);
	g.addEdge(12,11);
	cout<<endl;
	cnt=0;
	cntr=0;
	g.dfs();
	cout<<endl<<"Transpose\n";
	g.transposelist();
	g.dfs2();	
	return 0;
}
