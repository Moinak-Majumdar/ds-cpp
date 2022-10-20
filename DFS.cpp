#include <bits/stdc++.h>
using namespace std;

class Graph2
{
public:
	map<int, bool> visited;
	map<int, list<int> > adj2;

	void addEdge_DFS(int v, int w);
	void DFS(int v);
};

void Graph2::addEdge_DFS(int v, int w)
{
	adj2[v].push_back(w); 
}

void Graph2::DFS(int v)
{

	visited[v] = true;
	cout << v << " ";

	
	list<int>::iterator i;
	for (i = adj2[v].begin(); i != adj2[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}


int main()
{
	
	Graph2 g;
	g.addEdge_DFS(0, 1);
	g.addEdge_DFS(0, 9);
	g.addEdge_DFS(1, 2);
	g.addEdge_DFS(2, 0);
	g.addEdge_DFS(2, 3);
	g.addEdge_DFS(9, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";
	g.DFS(2);

	return 0;
}
