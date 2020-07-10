#include<iostream>
#include<list>
#include<climits>

using namespace std;
int count;

typedef struct node
{
	int v,w;
}node;
class Graph
{
	int V,c;
	list<node> *adj;
	int *st,*end,*par,*tps,*d,*pr;
	public: 
	Graph(int V);
	void addEdge(int u,int v,int w);
	void dfs(int v);
	void dfsrec(int v,bool b[]);
	void relex(int u,int v,int w);
	void print();
	void nameEdges();
	void printPath(int pr[],int j);
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<node>[V];
	st=new int[V];
	end=new int[V];
	par=new int[V];
	tps=new int[V];
	d=new int[V];
	d[0]=0;
	for(int i=1;i<V;i++)
	{
		d[i]=INT_MAX;
	} 	
	pr=new int[V];
	pr[0]=0;
	c=V-1;
	par[0]=-1;
}

void Graph::addEdge(int u,int v,int w)
{
	node n;
	n.v=v-1;
	n.w=w;
	adj[u-1].push_back(n);
}

void Graph::dfsrec(int v,bool b[])
{
	b[v]=true;
	st[v]=++count;

	list<node>::iterator i; 
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!b[(*i).v])
		{
			par[(*i).v]=v;
			dfsrec((*i).v,b);
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
void Graph::relex(int u,int v,int w)
{
	if(d[v]>d[u]+w)
	{
		d[v]=d[u]+w;
		pr[v]=u;
	}
}
void Graph::print()
{
	for(int i=0;i<V;i++)
	{
		cout<<tps[i]<<"\t";
	}
	cout<<endl;
	for(int u=0;u<V;u++)
	{
		list<node>::iterator i; 
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			relex(u,(*i).v,(*i).w);
		}
	}
	cout<<"Distance\n";
	for(int i=0;i<V;i++)
	{
		cout<<d[i]<<"\t";
	}
	cout<<"\nParent\n";
	for(int i=0;i<V;i++)
	{
		cout<<pr[i]<<"\t";
	}
	cout<<endl<<"Path"<<endl;
	for(int i=1;i<V;i++)
	{
		cout<<"1"<<" ";
		printPath(pr,i);
		cout<<"("<<d[i]<<")"<<endl;
	}	
}
void Graph:: printPath(int pr[],int j)
{
	if(pr[j]==0)
		return;
	printPath(pr,pr[j]);	
	cout<<j+1<<" ";
}
int main()
{
	Graph g(7);
	g.addEdge(1,2,5);
	g.addEdge(1,3,2);
	g.addEdge(4,6,1);
	g.addEdge(5,6,2);
	g.addEdge(6,7,1);
	g.addEdge(5,7,4);
	g.addEdge(2,7,8);
	g.addEdge(2,4,1);
	g.addEdge(3,5,1);
	count=0;
	g.dfs(0);
	
	return 0;
}
