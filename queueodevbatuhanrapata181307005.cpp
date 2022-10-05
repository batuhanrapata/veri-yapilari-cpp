//batuhan rapata 181307005
#include <iostream>
#include <stdlib.h>   
using namespace std;
int queue[8], n = 8, on = -1, arka = -1;
class yigin {

public:
	void ekle();
	void sil();
	void listele();
};
void yigin::ekle()
{
	int s = (rand() % 100);;
	if (arka == (n - 1))
	{
		cout << "queue dolu..." << endl;
	}
	else
	{
		if (on == -1)
			on = 0;
		arka++;
		queue[arka] = s;
	}
}
void yigin::sil()
{
	if (on == -1 || on > arka)
	{
		cout << "queue bos" << endl;
		return;
	}
	else
	{
		cout << "queue den eleman silindi..." << queue[on] << endl;
		on++;
	}
}
void yigin::listele()
{
	if (on == -1)
	{
		cout << "queue bos.." << endl;
	}
	else
	{
		cout << "queue elemanlari..." << endl;
		for (int i = on; i <= arka; i++)
		{
			cout << queue[i] << "\t";
		}
	}
}
int main()
{
	yigin y1;
	int ch;
	cout << "1- ekle" << endl;
	cout << "2- sil" << endl;
	cout << "3- listele" << endl;
	cout << "4- cikis" << endl;
	do
	{

		cout << "seciniz ?" << "\t";
		cin >> ch;
		switch (ch)
		{
		case 1: y1.ekle();
			break;
		case 2:  y1.sil();
			break;
		case 3:  y1.listele();
			break;
		case 4:
			cout << "cikis" << endl;
			break;
		default:
			cout << " GECERSIZ " << endl;
			break;
		}

	} while (ch != 4);
};