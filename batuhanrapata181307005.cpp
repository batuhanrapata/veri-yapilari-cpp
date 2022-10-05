//batuhan rapata 181307005
#include <iostream> 
using namespace std;
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void buildHeap(int arr[], int n)
{
	cout << "yigin insa ediliyor...\n";
	int startIdx = (n / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, n, i);
	}
}
void printHeap(int arr[], int n)
{
	cout << "olusan agacin inorder siralamasi\n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
	cout << "************************************\n";
}
void deleteRoot(int arr[], int& n)
{
	int lastElement = arr[n - 1];
	cout << "kok silindi;" << arr[0] << endl;
	arr[0] = lastElement;
	n = n - 1;
	heapify(arr, n, 0);
}
int main()
{
	int arr[] = { 15,7,12,28,36,1,37,13,4,25,3,9,27,2,5,16 };
	int n = sizeof(arr) / sizeof(arr[0]);
	buildHeap(arr, n);
	printHeap(arr, n);
	cout << "kok dugum " << arr[0] << endl;
	cout << "************************************\n";
	deleteRoot(arr, n);
	printHeap(arr, n);
	return 0;
}