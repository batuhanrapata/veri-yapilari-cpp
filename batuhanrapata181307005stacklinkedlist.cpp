//batuhan rapata 181307005
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* baglanti;
};
struct node* top = NULL;
void push(int eklenecek)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if (!temp)
	{
		cout << "stack dolu...";
		exit(1);
	}
	temp->data = eklenecek;
	temp->baglanti = top;
	top = temp;
}
int bosmu()
{
	return top == NULL;
}
int topreturn()
{
	if (!bosmu())
	{
		return top->data;
	}
	else
	{
		exit(1);
	}
}
void pop()
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if (top == NULL)
	{
		cout << "stack bostur...";
	}
	else
	{
		temp = top;
		top = top->baglanti;
		temp->baglanti = NULL;
		cout << "cikarildi... " << temp->data << endl;
		free(temp);
	}
}
void listele()
{
	if (top == NULL)
	{
		cout << "stack bostur...";
		exit(1);
	}
	else
	{
		cout << "elemanlar" << endl;
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp = top;
		while (temp != NULL)
		{
			cout << " ->> " << temp->data ;
			temp = temp->baglanti;
		}
	}
}
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	for (int i = 0; i < 10; i++)
	{
		push(i * 10);
	}
	listele();
	cout << endl;
	cout << "stack top eleman... " << topreturn();
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		pop();
	}
	listele();
	cout << endl;
	cout << "stack top eleman... " << topreturn();
	cout << endl;
	system("pause");
	return 0;
}

