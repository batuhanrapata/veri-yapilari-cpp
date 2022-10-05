//batuhan rapata 181307005
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
typedef struct Node BTREE;
BTREE* new_node(int data)
{
	BTREE* p = new BTREE;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
BTREE* insert(BTREE* root, int data)
{
	if (root != NULL)
	{
		if (data < root->data)
		{
			root->left = insert(root->left, data);
		}
		else
		{
			root->right = insert(root->right, data);
		}
	}
	else
	{
		root = new_node(data);
	}
	return root;
}
BTREE* searchTree(BTREE* root, int data)
{
	if (root != NULL)
	{
		if (root->data == data)
		{
			return root;
		}
		else if (root->data > data)
		{
			searchTree(root->left, data);
		}
		else
		{
			searchTree(root->right, data);
		}
	}
	else
	{
		cout << "aranan deger bulunanmadi ";
		return NULL;
	}
}
void preorder(BTREE* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}

}
BTREE* delete_node(BTREE* root, int data)
{
	BTREE* p, * q;
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		if (root->left == root->right)
		{
			free(root);
			return NULL;
		}
		else
		{
			if (root->left == NULL)
			{
				p = root->right;
				free(root);
				return p;
			}
			else if (root->right == NULL)
			{
				p = root->left;
				free(root);
				return p;
			}
			else
			{
				p = q = root->right;
				while (p->left != NULL)
				{
					p = p->left;
				}
				p->left = root->left;
				free(root);
				return q;
			}
		}
	}
	else if (root->data < data)
	{
		root->right = delete_node(root->right, data);
	}
	else
	{
		root->left = delete_node(root->left, data);
	}
	return root;
}
queue<int> b;
int size(BTREE* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return size(root->left) + 1 + size(root->right);
	}
}
int getCount(Node* root, int min, int max)
{
	if (!root)
	{
		return 0;
	}
	if (root->data == max && root->data == min)
	{
		return 1;
	}
	if (root->data <= max && root->data >= min)
	{
		b.push(root->data);
		return 1 + getCount(root->left, min, max) + getCount(root->right, min, max);
	}
	else if (root->data < min)
	{
		return getCount(root->right, min, max);
	}
	else
	{
		return getCount(root->left, min, max);
	}
}
struct Node* clonetree(struct Node* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	struct Node* newNode1 = new_node(root->data);
	newNode1->left = clonetree(root->left);
	newNode1->right = clonetree(root->right);
	return newNode1;
}
void sortQueue(queue<int>& queue) {
	int n = queue.size();
	for (int i = 0; i < n; i++) {
		int minIndex = -1;
		int minValue = INT_MAX;
		for (int j = 0; j < n; j++) {
			int currValue = queue.front();
			queue.pop();
			if (currValue < minValue && j < (n - i)) {
				minValue = currValue;
				minIndex = j;
			}
			queue.push(currValue);
		}
		for (int j = 0; j < n; j++) {
			int currValue = queue.front();
			queue.pop();
			if (j != minIndex) {
				queue.push(currValue);
			}
		}
		queue.push(minValue);
	}
}
int main()
{
	BTREE* p = NULL, * q = NULL, * w = NULL;
	p = insert(p, 50);
	p = insert(p, 28);
	p = insert(p, 46);
	p = insert(p, 80);
	p = insert(p, 47);
	p = insert(p, 96);
	p = insert(p, 14);
	p = insert(p, 10);
	p = insert(p, 68);
	p = insert(p, 20);
	p = insert(p, 34);
	p = insert(p, 71);
	p = insert(p, 61);
	p = insert(p, 41);
	p = insert(p, 82);
	p = insert(p, 64);
	p = insert(p, 13);
	p = insert(p, 18);
	p = insert(p, 27);
	p = insert(p, 95);
	p = insert(p, 74);
	p = insert(p, 81);
	p = insert(p, 11);
	p = insert(p, 36);
	preorder(p);
	cout << endl;
	int a;
	cout << "aramak istediginiz deger:\t";
	cin >> a;
	q = searchTree(p, a);
	cout << "aranan degerin adresi:\t" << q << endl;
	int min = 60, max = 70;
	getCount(p, min, max);
	sortQueue(b);
	int deger = b.front();
	cout << "60-70 arasindaki ilk deger:\t" << deger << endl;
	q = clonetree(p);
	delete_node(p, deger);
	cout << "deger silindi:\t" << deger << endl;
	preorder(p);
	cout << endl;
	cout << "silinen degerin kok olarak kopyasi" << endl;
	w = searchTree(q, deger);
	q = clonetree(w);
	preorder(q);
	cout << endl;
	cout << endl << system("pause");
}

