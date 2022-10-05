//batuhan rapata 181307005
#include <iostream>
using namespace std;
#define size 8
#include <stdlib.h>     
class kuyruk
{
	int dizi[size];
	int tos;
public:
	kuyruk();
	void push(int sy);
	int pop();
	void listele();
};
kuyruk::kuyruk()
{
	cout << "stack is constructing..." << endl;
	tos = 0;
}
void kuyruk::push(int sy)
{
	if (tos == 8)
	{
		cout << "stack is full..." << endl;
	}
	else
	{
		dizi[tos] = sy;
		cout << dizi[tos] << " eklendi " << endl;
		tos++;
	}
}
int kuyruk::pop()
{
	if (tos == 0)
	{
		cout << "stack is empty..." << endl;
	}
	else
	{
		tos--;
		cout << dizi[tos] << " cikarildi " << endl;
		return dizi[tos];
	}
}
void kuyruk::listele()
{
	for (int i = 0; i < tos; i++)
	{
		cout << dizi[i] << endl;
	}
}
int main()
{
	int secenek;
	kuyruk k1;
	cout << "secenek seciniz\n	1-Kuyruga eleman ekle\n 2-Kuyruktan eleman cikar\n 3-Elemanlari listele\n 4-Cikis" << endl;
	do
	{
		cout << "seceneginiz...";
		cin >> secenek;
		if (secenek == 1)
		{
			int s = (rand() % 100);
			k1.push(s);
		}
		else if (secenek == 2)
		{
			k1.pop();
		}
		else if (secenek == 3)
		{
			cout << "elemanlar listeleniyor" << endl;
			k1.listele();
		}
		else if (secenek != 1 && secenek != 2 && secenek != 3 && secenek != 4)
		{
			cout << "gecersiz giris tekrar deneyin" << endl;
		}
	} while (secenek != 4);
	cout << "programdan cikis yapildi" << endl;
	return 0;
}

