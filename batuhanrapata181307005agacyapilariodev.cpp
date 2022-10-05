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
void mirroring(struct Node* node)
{
	if (node == NULL)
		return;
	else
	{
		struct Node* temp;
		mirroring(node->sol);
		mirroring(node->sag);
		temp = node->sol;
		node->sol = node->sag;
		node->sag = temp;
	}
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
	cout << endl;
	mirroring(p);
	cout << "preorder mirror" << endl;
	preorder(p);
	cout << endl;
	cout << "inorder mirror" << endl;
	inorder(p);
	cout << endl;
	cout << "postorder mirror" << endl;
	postorder(p);
	return 0;
}
