//batuhan rapata 181307005
#include <iostream>
using namespace std;
struct Node
{
	string isim;
	int kimlik;
	string cinsiyet;
	struct Node* next;
	struct Node* prev;
};
struct Node* head = NULL;
struct Node* tail = NULL;
void ekle(string isim, int kimlik, string cinsiyet)
{
	cout << "eleman eklendi" << endl;
	struct Node* p = new Node;
	p->isim = isim;
	if (head == NULL)
	{
		head = tail = p;
		head->prev = NULL;
		tail->next = NULL;
	}
	else
	{
		tail->next = p;
		p->prev = tail;
		tail = p;
		tail->next = NULL;
	}


	p->kimlik = kimlik;
	if (head == NULL)
	{
		head = tail = p;
		head->prev = NULL;
		tail->next = NULL;
	}
	else
	{
		tail->next = p;
		p->prev = tail;
		tail = p;
		tail->next = NULL;
	}


	p->cinsiyet = cinsiyet;
	if (head == NULL)
	{
		head = tail = p;
		head->prev = NULL;
		tail->next = NULL;
	}
	else
	{
		tail->next = p;
		p->prev = tail;
		tail = p;
		tail->next = NULL;
	}
}
void listele()
{
	cout << "[elemanlar...]" << endl;
	struct Node* p = new Node;
	p = head;
	while (p != NULL)
	{
		cout << p->isim << "\t" << p->kimlik << "\t" << p->cinsiyet << "\t" << endl;
		p = p->next;
	}
}
void siralama()//soruyu yanlis anladim basta o yuzden siralama yaptim bosa gitmesin diye silmedim
{
	cout << "kimlik no siralanan ";
	struct Node* a = new Node;
	struct Node* b = new Node;
	a = NULL;
	b = NULL;
	int temp;
	string isimt, cinsiyett;
	if (head == NULL)
	{
		return;
	}
	else
	{
		for (a = head; a->next != NULL; a = a->next)
		{
			for (b = a->next; b != NULL; b = b->next)
			{
				if (a->kimlik > b->kimlik)
				{
					temp = a->kimlik;
					a->kimlik = b->kimlik;
					b->kimlik = temp;
					isimt = a->isim;
					a->isim = b->isim;
					b->isim = isimt;
					cinsiyett = a->cinsiyet;
					a->cinsiyet = b->cinsiyet;
					b->cinsiyet = cinsiyett;
				}
			}
		}
	}
}
void arayaekle(string isim, int kimlik, string cinsiyet, int n)
{
	cout << "[araya eleman ekleniyor] " << endl;
	Node* p, * temp;
	temp = new Node;
	p = head;
	while (p->kimlik != n)
	{
		p = p->next;
	}
	temp->isim = isim;
	temp->kimlik = kimlik;
	temp->cinsiyet = cinsiyet;
	if (p->next == NULL)
	{
		p->next = temp;
		temp->next = NULL;
		temp->prev = p;
	}
	else
	{
		temp->next = p->next;
		temp->next->prev = temp;
		p->next = temp;
		temp->prev = p;
	}
	cout << "eklenen kimlik no " << temp->kimlik << endl << endl;
}
void sil(int silinecek)
{
	struct Node* temp = new Node;
	struct Node* temp2 = new Node;
	struct Node* onceki = NULL;
	struct Node* sonraki = NULL;
	if (head->kimlik == silinecek)
	{
		if (head == NULL)
		{
			cout << "liste bos";
		}
		else {
			if (head->next == NULL)
			{
				delete head;
				head = NULL;
			}
			else
			{
				head = head->next;
				delete head;
				head = temp;
			}
		}
	}
	temp = head;
	while (temp->next->kimlik != silinecek)
	{
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		if (head == NULL)
		{
			cout << "liste bos...";
		}
		else {
			if (head->next == NULL)
			{
				delete head;
				head = NULL;
			}
			else
			{
				temp = head->next;
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
	onceki = temp;
	sonraki = temp->next->next;
	free(temp->next);
	onceki->next = sonraki;
	cout << "silinen kimlik no " << silinecek << endl;;
}
int main()
{
	ekle("batuhan", 1, "erkek");
	ekle("ali", 3, "erkek");
	ekle("fatma", 2, "kiz");
	ekle("mehmet", 4, "erkek");
	arayaekle("selim", 9, "erkek", 2);
	
	listele();
	cout << endl;
	
	arayaekle("ayse", 5, "kiz", 2);
	
	listele();
	cout << endl;
	
	arayaekle("merve", 7, "kiz", 5);
	
	listele();
	cout << endl;
	
	listele();
	cout << endl;
	
	sil(7);
	sil(9);
	
	listele();
	return 0;
}
