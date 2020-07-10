#include<iostream>
#include<list>
using namespace std;
int count;
class Graph
{
	int V,c;
	list<int> *adj;
	int *st,*end,*par,*tps;
	public: 
	Graph(int V);
	void addEdge(int v,int w);
	void dfs(int v);
	void dfsrec(int v,bool b[]);
	void print();
	void nameEdges();
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
	st=new int[V];
	end=new int[V];
	par=new int[V];
	tps=new int[V];
	c=V-1;
	par[0]=-1;
}

void Graph::addEdge(int v,int w)
{
	adj[v-1].push_back(w-1);
}

void Graph::dfsrec(int v,bool b[])
{
	b[v]=true;
	st[v]=++count;
	//cout<<v<<"\t";
	list<int>::iterator i; 
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!b[*i])
		{
			par[*i]=v;
			dfsrec(*i,b);
		}
	}
	end[v]=++count;
	tps[c--]=v+1;
}


void Graph::dfs(int v)
{
	bool *b=new bool[V];
	for(int i=0;i<V;i++)
	b[i]=false;
	for(int i=0;i<V;i++)
	{
		if(!b[i])
		dfsrec(i,b);
	}
	print();
}

void Graph::print()
{
	for(int i=0;i<V;i++)
	{
		cout<<tps[i]<<"\t";
	}
	cout<<endl;
}


int main()
{
	Graph g(7);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(4,6);
	g.addEdge(5,6);
	g.addEdge(6,7);
	g.addEdge(5,7);
	g.addEdge(2,7);
	g.addEdge(2,4);
	g.addEdge(3,5);
	cout<<endl;
	count=0;
	g.dfs(0);
	cout<<endl;
	
	return 0;
}
