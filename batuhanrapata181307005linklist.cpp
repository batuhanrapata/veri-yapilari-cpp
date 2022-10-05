//batuhan rapata 181307005
#include <iostream>
using namespace std;


struct BLISTE
{
	int bilgi;
	BLISTE* arka;
};
BLISTE* ilk = NULL;
BLISTE* son = NULL;
int ekle(BLISTE* ki)
{
	if (ilk != NULL)
	{
		son->arka = ki;
		son = ki;
		son->arka = NULL;
	}
	else
	{
		ilk = ki;
		son = ilk;
		ilk->arka = NULL;
	}
	return 0;
}
BLISTE* ara(int aranan)
{
	BLISTE* p;
	p = ilk;
	while (p)
	{
		if (p->bilgi == aranan)
			return p;
		p = p->arka;
	}
	return NULL;
}
BLISTE* sil(int silinecek)
{
	BLISTE* p, * bironceki;
	p = ilk;
	bironceki = NULL;
	while (p)
	{
		if (silinecek == p->bilgi) break;
		bironceki = p;
		p = p->arka;
	}
	if (p != NULL)
	{
		if (bironceki == NULL)
		{
			if (ilk == son)
			{
				ilk = NULL;
				son = NULL;
			}
			else ilk = ilk->arka;
		}
		else
		{
			bironceki->arka = p->arka;
			if (bironceki->arka == NULL) son = bironceki;
		}
		free(p);
		return p;
	}
	else return(NULL);
}
int main()
{
	BLISTE* s;
	BLISTE a, b, c;
	a.bilgi = 1;
	b.bilgi = 2;
	c.bilgi = 3;
	s = &a;
	ekle(s);
	a.arka = b.arka = c.arka = NULL;
	cout << a.bilgi << "\t";
	cout << b.bilgi << "\t";
	cout << c.bilgi << "\t";
	return 0;
}

