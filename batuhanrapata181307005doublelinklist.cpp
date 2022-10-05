//batuhan rapata 181307005
#include <iostream>
using namespace std;
typedef struct topluluk
{
	int bilgi;
	struct topluluk* on;
	struct topluluk* arka;
}BLISTE2;
BLISTE2* ilk2 = NULL, * son2 = NULL;
int ekle(int eklenecek)
{
	BLISTE2* ki;
	ki = new BLISTE2;
	ki->bilgi = eklenecek;
	if (ilk2 != NULL)
	{
		son2->arka = ki;
		ki->on = son2;
		son2 = ki;
		son2->arka = NULL;
	}
	else
	{
		ilk2 = ki;
		son2 = ki;
		ilk2->arka = NULL;
		ilk2->on = NULL;
	}
	return 0;
}
int listele()
{
	BLISTE2* p;
	p = ilk2;
	if (p == NULL)
	{
		return -1;
	}
	while (p)
	{
		cout << p->bilgi << endl;
		p = p->arka;
	}
	return 0;
}
BLISTE2* arama(int aranan)
{
	BLISTE2* p;
	p = ilk2;
	while (p != NULL)
	{
		if (aranan == p->bilgi)
		{
			return p;
		}
		p = p->arka;
	}
	return NULL;
}
BLISTE2* silme(int silinecek)
{
	BLISTE2* p;
	p = arama(silinecek);
	if (p == NULL)
	{
		return NULL;
	}
	if (ilk2 == p)
	{
		if (ilk2->arka != NULL)
		{
			ilk2 = p->arka;
			ilk2->on = NULL;
		}
		else
		{
			ilk2 = NULL;
			son2 = NULL;
		}
	}
	else
	{
		p->on->arka = p->arka;
		if (p == son2)
		{
			son2 = son2->on;
		}
		else
		{
			p->arka->on = p->on;
		}
	}
	free(p);
	return p;
}
int main()
{
	BLISTE2* p;
	p = new BLISTE2;
	int i = 0;
	int veri = 0;
	cout << "1-ekleme" << endl;
	cout << "2-silme" << endl;
	cout << "3-listeleme" << endl;
	cout << "4-arama" << endl;
	cout << "5-cikis" << endl;
	topluluk* toplulukk;
	toplulukk = new topluluk;
	do
	{
		cout << "seciniz... ";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "Eklenecek deger: ";
			cin >> veri;
			ekle(veri);
			cout << "eklendi" << endl;
			break;
		case 2:
			cout << "Silinecek deger: " ;
			cin >> veri;
			silme(veri);
			cout << "silindi" << endl;
			break;
		case 3:
			listele();
			cout << "listeleme" << endl;
			break;
		case 4:
			cout << "Aranacak deger: " ;
			cin >> veri;
			arama(veri);
			cout <<"adresi :" <<arama(veri) << endl;
			break;
		default:
			break;
		}
	} while (i != 5);
	cout << "cikis yapildi";
	return 0;
}

