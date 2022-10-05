// batuhan rapata 181307005
#include <iostream>
using namespace std;
#define node_sayisi 7
int in[node_sayisi], out[node_sayisi];
void createList(int arr[][node_sayisi])
{
	int i, j;
	for (i = 0; i < node_sayisi; i++)
		for (j = 0; j < node_sayisi; j++)
			arr[i][j] = 0;
}
void addEdge(int arr[][node_sayisi], int gelen, int yol)
{
	in[gelen]++;
	out[yol]++;
	arr[gelen][yol] = 1;
}
void inOutDegree(int n)
{
	cout << " \t\t    *  out in  *\n";
	for (int i = 1; i <= n; i++)
	{
		cout << "out && in degree  " << i << " : ";
		cout << "([" << in[i] << "]-[" << out[i] << "])" << endl;
	}
}
void printAdjMatris(int arr[][node_sayisi])
{
	int i, j, l = 1;
	cout << "*kardeslik (adj) matris*" << endl;
	cout << "  ";
	for (int k = 1; k <= node_sayisi; k++)
	{
		cout << " " << k;
	}
	cout << endl;
	for (i = 0; i < node_sayisi; i++)
	{
		cout << " " << l++;
		for (j = 0; j < node_sayisi; j++)
		{

			cout << " " << arr[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int adjMatris[node_sayisi][node_sayisi];
	createList(adjMatris);
	addEdge(adjMatris, 1, 2);
	addEdge(adjMatris, 1, 3);
	addEdge(adjMatris, 3, 4);
	addEdge(adjMatris, 3, 6);
	addEdge(adjMatris, 4, 1);
	addEdge(adjMatris, 5, 4);
	addEdge(adjMatris, 5, 7);
	inOutDegree(node_sayisi);
	printAdjMatris(adjMatris);
	return 0;
}

