//batuhan rapata 181307005
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
struct queue {
	node* on, * arka;
	queue()
	{
		on = arka = NULL;
	}
	void ekle(int eklenecek)
	{
		node* temp = new node(eklenecek);
		if (arka == NULL)
		{
			on = arka = temp;
			return;
		}
		arka->next = temp;
		arka = temp;
	}
	void sil()
	{
		if (on == NULL)
		{
			return;
		}
		node* temp = on;
		on = on->next;
		if (on == NULL)
		{
			arka = NULL;
		}
		cout << "cikarildi... " << temp->data << endl;
		delete(temp);
	}
	void listele()
	{
		cout << "elemanlar" << endl;
		node* temp = (struct node*)malloc(sizeof(struct node));
		temp = on;
		while (temp != NULL)
		{
			cout << " ->> " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	queue q1;
	q1.ekle(10);
	q1.ekle(20);
	q1.ekle(30);
	q1.ekle(40);
	q1.ekle(50);
	for (int i = 0; i < 10; i++)
	{
		q1.ekle(i * 10);
	}
	q1.listele();
	cout << "queue on eleman... " << q1.on->data << endl;
	cout << "queue arka eleman... " << q1.arka->data << endl;
	for (int i = 0; i < 5; i++)
	{
		q1.sil();
	}
	q1.listele();
	cout << "queue on eleman... " << q1.on->data << endl;
	cout << "queue arka eleman... " << q1.arka->data << endl;
	system("pause");
	return 0;
}
