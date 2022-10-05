//batuhan rapata 181307005
#include<iostream>
using namespace std;
#define V 6 
string harf[] = { "A","B", "C", "D", "E", "Z" };
int nearest(int dist[], bool visited[])
{
	int min = INT_MAX, minVal;
	for (int v = 0; v < V; v++)
		if (visited[v] == false && dist[v] <= min)
			min = dist[v], minVal = v;
	return minVal;
}
void yolPrint(int parent[], int j)
{
	if (parent[j] == -1)
		return;
	yolPrint(parent, parent[j]);
	cout << "->" << harf[j];
}
void print(int dist[], int n, int parent[])
{
	int src = 0;
	cout << "Hedef\t\tUzaklik\t\tYol";
	for (int i = 1; i < V; i++)
	{
		cout << "\n" << harf[0] << "->" << harf[i] << "\t\t" << dist[i] << "\t\t" << harf[0];
		yolPrint(parent, i);
	}
}
void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool visited[V];
	int parent[V];
	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
	{
		int u = nearest(dist, visited);
		visited[u] = true;
		for (int v = 0; v < V; v++)
			if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	print(dist, V, parent);
}
int main()
{
	int graph[V][V] = {
			{0,4,2,0,0,0},
			{4,0,1,5,0,0},
			{2,1,0,8,10,0},
			{0,3,8,0,2,6},
			{0,0,10,2,0,3},
			{0,0,0,6,3,0} };
	dijkstra(graph, 0);
	return 0;
}