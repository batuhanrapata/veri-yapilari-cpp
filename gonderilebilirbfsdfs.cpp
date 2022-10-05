// batuhan rapata 181307005

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
using namespace std;
string vertex[] = { "A","B", "C", "D", "E", "F" };
class Graph
{
	int V;
	list<int>* adjList;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);
	void DFS(int s);
};
Graph::Graph(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
	adjList[v].push_back(w);
}
void Graph::BFS(int s)
{
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
		visited[i] = false;
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
	while (!queue.empty())
	{
		s = queue.front();
		cout << vertex[s] << " ";
		queue.pop_front();
		for (i = adjList[s].begin(); i != adjList[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}
void Graph::DFS(int s)
{
	vector<bool> visited(V, false);
	stack<int> stack;
	stack.push(s);
	while (!stack.empty())
	{
		s = stack.top();
		stack.pop();
		if (!visited[s])
		{
			cout << vertex[s] << " " << s;
			visited[s] = true;
		}
		for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i)
			if (!visited[*i])
				stack.push(*i);
	}
}
int main()
{
	Graph g(6);
	 g.addEdge(0, 1);
	  g.addEdge(0, 4);
	 g.addEdge(0, 3);
	  g.addEdge(1, 0);
	 g.addEdge(1, 2);
	g.addEdge(2, 1);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);
	g.addEdge(5, 4);
	g.addEdge(5, 2);
	cout << "BFS" << endl;
	g.BFS(0);
	cout << endl;
	cout << "DFS" << endl;
	g.DFS(0);
	cout << endl;
	system("pause");
	return 0;
}
