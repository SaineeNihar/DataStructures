#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;	
	public:
	Graph(int V);
	void addEdge(int u,int v);
	void bfs(int v);
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
	adj[u-1].push_back(v-1);
}
void Graph::bfs(int v)
{
	bool *visited= new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	list<int> q;
	visited[v-1]=true;
	q.push_back(v-1);
	list<int>::iterator i;
	while(!q.empty())
	{
 		int s=q.front();
		cout<<s+1<<" ";
		q.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				q.push_back(*i);
			}
		}	
	}
}
int main()
{
	Graph g(5);
	g.addEdge(1,2);
	g.addEdge(2,1);
	g.addEdge(1,3);
	g.addEdge(3,1);
	g.addEdge(5,4);
	g.addEdge(4,5);
	g.addEdge(3,5);
	g.addEdge(5,3);
	g.addEdge(2,4);
	g.addEdge(4,2);
	g.bfs(1);

}
