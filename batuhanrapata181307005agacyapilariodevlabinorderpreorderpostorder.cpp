// batuhan rapata 181307005
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* sol, * sag;
	Node(int eklenecek)
	{
		this->data = eklenecek;
		sol = sag = NULL;
	}
};
void postorder(struct Node* node)
{
	if (node == NULL)
		return;
	postorder(node->sol);
	postorder(node->sag);
	cout << node->data << "\t";
}
void inorder(struct Node* node)
{
	if (node == NULL)
		return;
	inorder(node->sol);
	cout << node->data << "\t";
	inorder(node->sag);
}
void preorder(struct Node* node)
{
	if (node == NULL)
		return;
	cout << node->data << "\t";
	preorder(node->sol);
	preorder(node->sag);
}
int main()
{
	struct Node* p = new Node(1);
	p->sol = new Node(2);
	p->sag = new Node(3);
	p->sol->sol = new Node(4);
	p->sol->sag = new Node(5);
	cout << "preorder" << endl;
	preorder(p);
	cout << endl;
	cout << "inorder" << endl;
	inorder(p);
	cout << endl;
	cout << "postorder" << endl;
	postorder(p);
	return 0;
}
