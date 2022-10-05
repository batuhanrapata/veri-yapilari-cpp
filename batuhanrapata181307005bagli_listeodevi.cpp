 //batuhan rapata 181307005
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* bas = NULL;
struct node* son = NULL;
struct node* temp = (struct node*)malloc(sizeof(struct node));
struct node* temp2 = (struct node*)malloc(sizeof(struct node));
void basa_ekle(int eklenecek)
{
	node* new_node;
	new_node = new node;
	new_node->data = eklenecek;
	new_node->next = bas;
	if (bas == NULL)
	{
		son = new_node;
	}
	bas = new_node;
}
void sona_ekle(int eklenecek)
{
	node* new_node;
	new_node = new node;
	new_node->data = eklenecek;
	new_node->next = NULL;
	if (bas == NULL)
	{
		bas = son = new_node;
	}
	else
	{
		son->next = new_node;
		son = new_node;
	}
}
void araya_ekle(int n, int veri)
{
	struct node* eleman;
	eleman = (struct node*)malloc(sizeof(struct node));
	eleman->data = veri;
	temp = bas;
	while (temp->next->data != n)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = eleman;
	eleman->next = temp2;
}
void listele()
{
	struct node* liste;
	liste = bas;
	while (liste != NULL)
	{
		cout << liste->data << "\t";
		liste = liste->next;
	}
}
void ara()
{
	struct node* liste;
	liste = bas;
	while (liste != NULL)
	{
		if (liste->data % 3 == 0)
		{
			cout << liste->data << "\t";
		}
		liste = liste->next;
	}
}
void bastan_sil()
{
	if (bas == NULL)
	{
		cout << "liste bos";
	}
	else {
		if (bas->next == NULL)
		{
			delete bas;
			bas = NULL;
		}
		else
		{
			temp = bas->next;
			delete bas;
			bas = temp;
		}
	}
}
void sondan_sil()
{
	if (bas == NULL)
	{
		cout << "liste bos";
	}
	else {
		if (bas->next == NULL)
		{
			delete bas;
			bas = NULL;
		}
		else
		{
			temp = bas->next;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			temp2 = temp;
			delete temp->next;
			temp2->next = NULL;
		}
	}
}
void aradan_sil(int silinecek)
{
	if (bas->data == silinecek)
	{
		bastan_sil();
	}
	struct node* onceki = NULL;
	struct node* sonraki = NULL;
	temp = bas;
	while (temp->next->data != silinecek)
	{
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		sondan_sil();
	}
	onceki = temp;
	sonraki = temp->next->next;
	free(temp->next);
	onceki->next = sonraki;
}
int main()
{
	node* p;
	p = new node();
	cout << "basa ekleme" << endl;
	basa_ekle(9);
	basa_ekle(19);
	basa_ekle(29);
	basa_ekle(39);
	basa_ekle(49);
	listele();
	cout << endl;

	cout << "sona ekleme" << endl;
	sona_ekle(1);
	sona_ekle(21);
	sona_ekle(31);
	sona_ekle(41);
	sona_ekle(51);

	listele();
	cout << endl;

	cout << "araya ekleme" << endl;
	araya_ekle(1, 5);
	araya_ekle(1, 15);
	araya_ekle(1, 25);
	araya_ekle(1, 35);
	araya_ekle(1, 45);

	listele();
	cout << endl;
	cout << "ucun katlari olan elemanlar" << endl;
	ara();
	cout << endl;

	bastan_sil();
	bastan_sil();
	bastan_sil();
	cout << "bastan 3 eleman silindi" << endl;
	listele();
	cout << endl;

	sondan_sil();
	sondan_sil();
	sondan_sil();
	cout << "sondan 3 eleman silindi" << endl;
	listele();
	cout << endl;
	
	aradan_sil(25);
	aradan_sil(35);
	aradan_sil(45);
	cout << "aradan 3 eleman silindi" << endl;
	listele();

	return 0;
}
