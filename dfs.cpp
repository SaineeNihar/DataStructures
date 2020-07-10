#include<iostream>
#include<list>
using namespace std;
int count;
class Graph
{
	int V;
	list<int> *adj;
	int *st,*end,*par;
	public: 
	Graph(int V);
	void addEdge(int v,int w);
	void dfs();
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
}

void Graph::addEdge(int v,int w)
{
	adj[v-1].push_back(w-1);
}

void Graph::dfsrec(int v,bool b[])
{
	par[0]=-1;
	b[v]=true;
	st[v]=++count;
	cout<<v<<"\t";
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
}


void Graph::dfs()
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
	nameEdges();
}

void Graph::print()
{
	cout<<endl;
	cout<<"Vertex"<<"\t"<<"Start"<<"\t"<<"End"<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<i<<"	"<<st[i]<<"\t"<<end[i]<<endl;
	}
	cout<<"parents\n";
	for(int i=0;i<V;i++)
	{
		cout<<i<<"	"<<par[i]<<endl;
	}
	
}
void Graph::nameEdges()
{
	list<int>::iterator i;

	for(int u=0;u<V;u++)
	{		
		for(i=adj[u].begin();i!=adj[u].end();++i)
		{
			if(u==par[*i])	
			else if((st[*i]<st[u])&& (st[*i]<end[u])&&(st[*i]< end[*i])&& (st[u]<end[u])&&(st[u]< end[*i]) &&(end[u]< end[*i]))
			cout<<u+1<<","<<*i+1<<"\t Back edge"<<endl;	
			else if((st[*i]<end[*i]) && (st[*i]< st[u])&& (st[*i]< end[u]) && (end[*i]< st[u])&& (end[*i]< end[u])&& (st[u]< end[u]))
			cout<<u+1<<","<<*i+1<<"\t cross edge"<<endl;	
			else 
			cout<<u+1<<","<<*i+1<<"\t Forward  edge"<<endl;	
		
		}

	}
}


int main()
{
	Graph g(5);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(3,1);
	g.addEdge(1,4);
	g.addEdge(5,4);
	g.addEdge(1,5);
	cout<<endl;
	count=0;
	g.dfs();
	cout<<endl;
	
	return 0;
}
