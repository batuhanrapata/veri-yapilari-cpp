//batuhan rapata 181307005
#include<iostream>
using namespace std;
#define V 7 
string harf[] = { "Uskudar","Kadikoy", "Umraniye","Atasehir" , "Samandira", "Bostanci", "Maltepe" };
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
	cout << "Hedef\t\t\t\t\t\tUzaklik\t\t\t\t\t\tYol";
	for (int i = 1; i < V; i++)
	{
		cout << "\n" << harf[0] << "->" << harf[i] << "\t\t\t\t" << dist[i] << "\t\t\t\t" << harf[0];
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
		/*Uskudar*/     {0,5,4,0,0,0,0},
		/*Kadikoy*/	    {5,0,10,7,0,0,0},
		/*Umraniye*/	{4,10,0,6,15,0,0},
		/*Atasehir*/	{0,7,6,0,8,11,0},
		/*Samandira*/	{0,0,15,8,0,3,12},
		/*Bostanci*/    {0,13,0,11,0,0,18},
		/*Maltepe*/     {0,0,13,0,12,18,0} };
	dijkstra(graph, 0);
	cout << endl;
	system("pause");
	return 0;
}