//batuhan rapata 181307005
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
typedef struct Node BTREE;
typedef struct Node BTREEtek;
typedef struct Node BTREEcift;
BTREE* new_node(int data)
{
	BTREE* p = new BTREE;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
BTREEtek* new_node2(int data)
{
	BTREEtek* p = new BTREEtek;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
BTREEcift* new_node3(int data)
{
	BTREEcift* p = new BTREEcift;
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
BTREEtek* insert2(BTREEtek* root, int data)
{
	if (root != NULL)
	{
		if (data < root->data)
		{
			root->left = insert2(root->left, data);
		}
		else
		{
			root->right = insert2(root->right, data);
		}
	}
	else
	{
		root = new_node2(data);
	}
	return root;
}
BTREEcift* insert3(BTREEcift* root, int data)
{
	if (root != NULL)
	{
		if (data < root->data)
		{
			root->left = insert3(root->left, data);
		}
		else
		{
			root->right = insert3(root->right, data);
		}
	}
	else
	{
		root = new_node3(data);
	}
	return root;
}

BTREEtek* xp = NULL;
void teksayilar(Node* root)
{
	if (root != NULL) {
		teksayilar(root->left);
		if (root->data % 2 != 0)
		{
			xp = insert2(xp, root->data);
		}
		teksayilar(root->right);
	}
}

BTREEcift* xt = NULL;
void ciftsayilar(Node* root)
{
	if (root != NULL) {
		ciftsayilar(root->left);
		if (root->data % 2 == 0)
		{
			xt = insert3(xt, root->data);
		}
		ciftsayilar(root->right);
	}
}

void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << "\t";
		inorder(root->right);
	}
}

bool tek_ekle(Node* root)
{
	if (root != NULL) {
		tek_ekle(root->left);
		if (root->data % 2 != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		tek_ekle(root->right);
	}
}//aynisi cift sayilar icin de yapilabilir daha fazla daginik olmsin diye eklemedim
int ekletek(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		ekletek(root->left);
		if (tek_ekle(root) == true)
		{
			xp = insert2(xp, root->data);
		}
		ekletek(root->right);
	}
}//aynisi cift sayilar icin de yapilabilir daha fazla daginik olmsin diye eklemedim

int carpim = 1;
bool searchTree(Node* root, int data)
{

	if (root != NULL)
	{
		if (root->data == data)
		{
			return 	carpim = carpim * root->data;
		}
		else if (root->data > data)
		{
			carpim = carpim * root->data;
			searchTree(root->left, data);

		}
		else
		{
			carpim = carpim * root->data;
			searchTree(root->right, data);
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	BTREE* p = NULL;
	int a;
	do
	{
		cout << "deger giriniz: \t";
		cin >> a;
		if (a != 1)
		{
			p = insert(p, a);
		}
	} while (a != 1);

	cout << "BTREE inorder" << endl;
	inorder(p);
	cout << endl;

	cout << "BTREEtek inorder" << endl;
	teksayilar(p);
	inorder(xp);
	cout << endl;

	cout << "BTREEcift inorder" << endl;
	ciftsayilar(p);
	inorder(xt);
	inorder(xt);
	cout << endl;

	cout << "BTREEtek boolean versiyonu inorder" << endl;
	ekletek(p);//bool ve int kullanarak true false 0 1 dondurerek calisan versiyonu
	inorder(xp);
	cout << endl;

	cout << "aranacak degeri giriniz: ";
	cin >> a;
	searchTree(p, a);
	if (a == carpim)
	{
		cout << "carpim degeri yol uzerindeki verilerin carpimina esittir deger: " << carpim << endl;
	}
	else
	{
		cout << "carpim degeri yol uzerindeki verilerin carpimina esit degildir deger: " << carpim << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}