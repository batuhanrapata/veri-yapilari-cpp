//batuhan rapata 181307005
#include <iostream>
using namespace std;
struct Node
{
	int data;
	int height;
	struct Node* left;
	struct Node* right;
};
typedef struct Node AVLTREE;
int height(AVLTREE* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}
int dengele(AVLTREE* root)
{
	if (root == NULL)
		return 0;
	return(height(root->left) - height(root->right));
}
AVLTREE* newNode(int data)
{
	AVLTREE* p = new AVLTREE;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return (p);
}
//sagsoldonme islemi avl
AVLTREE* sagdonme(AVLTREE* a)
{
	AVLTREE* p = a->left;
	AVLTREE* q = p->right;
	p->right = a;
	a->left = q;
	a->height = max(height(a->left), height(a->right)) + 1;
	p->height = max(height(p->left), height(p->right)) + 1;
	return p;
}
AVLTREE* soldonme(AVLTREE* a)
{
	AVLTREE* p = a->right;
	AVLTREE* q = p->left;
	p->left = a;
	a->right = q;
	a->height = max(height(a->left), height(a->right)) + 1;
	p->height = max(height(p->left), height(p->right)) + 1;
	return p;
}
AVLTREE* insert(AVLTREE* root, int data)
{
	if (root == NULL)
	{
		return(newNode(data));
	}
	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = insert(root->right, data);
	}
	else
	{
		return root;
	}
	root->height = 1 + max(height(root->left), height(root->right));
	int denge = dengele(root);
	if (denge > 1 && data < root->left->data)
	{
		return sagdonme(root);
	}
	if (denge<-1 && data>root->right->data)
	{
		return soldonme(root);
	}
	if (denge > 1 && data > root->left->data)
	{
		root->left = soldonme(root->left);
		return sagdonme(root);
	}
	if (denge < -1 && data < root->right->data)
	{
		root->right = sagdonme(root->right);
		return soldonme(root);
	}
	return root;
}
AVLTREE* min(AVLTREE* root)
{
	AVLTREE* p = root;
	while (p->left != NULL)
	{
		p = p->left;
	}
	return p;
}
AVLTREE* delet(AVLTREE* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	if (data < root->data)
	{
		root->left = delet(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = delet(root->right, data);
	}
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			AVLTREE* p = root->left ? root->left : root->right;
			if (p == NULL)
			{
				p = root;
				root = NULL;
			}
			else
			{
				*root = *p;
			}
			free(p);
		}
		else
		{
			AVLTREE* p = min(root->right);
			root->data = p->data;
			root->right = delet(root->right, p->data);
		}
	}
	if (root == NULL)
	{
		return root;
	}
	root->height = 1 + max(height(root->left), height(root->right));
	int denge = dengele(root);
	if (denge > 1 && dengele(root->left) >= 0)
	{
		return sagdonme(root);
	}
	if (denge < -1 && dengele(root->right) <= 0)
	{
		return soldonme(root);
	}
	if (denge < -1 && dengele(root->right) > 0)
	{
		root->right = sagdonme(root->right);
		return soldonme(root);
	}
	return root;
}
AVLTREE* arama(AVLTREE* root, int key)
{
	if (root == NULL || root->data == key)
	{
		return root;
	}
	if (root->data < key)
	{
		return arama(root->right, key);
	}
	return arama(root->left, key);
}
void preorder(AVLTREE* root)
{
	if (root != NULL)
	{
		cout << root->data << "\t";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	cout << "islemlerden cikis icin degeri -1 giriniz" << endl;
	AVLTREE* p = NULL;
	int a;
	do
	{
		cout << "eklenecek deger giriniz: ";
		cin >> a;
		if (a != -1)
		{
			p = insert(p, a);
		}
	} while (a != -1);
	cout << "preorder siralanmis hali" << endl;
	preorder(p);

	do
	{
		cout << endl;
		cout << "silmek istediginiz deger: ";
		cin >> a;
		if (a != -1)
		{
			p = delet(p, a);
			cout << "preorder siralanmis hali" << endl;
			preorder(p);
		}

	} while (a != -1);

	do
	{
		cout << endl;
		cout << "aramak istediginiz deger: ";
		cin >> a;
		if (a != -1)
		{
			cout << "degerin adresi: " << arama(p, a);
		}

	} while (a != -1);
	return 0;
}
