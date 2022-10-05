//batuhan rapata 181307005 ..
#include <iostream>
using namespace std;



double ort(int* dizi, int eleman)
{
	double toplam = 0;
	for (int j = 0; j < 7; j++)
	{
		toplam = *dizi + toplam;
		dizi++;
	}
	double ort = toplam / eleman;
	cout << ort;
	return ort;
}
int main()
{

	int dizi[7] = { 5,7,2,12,4,4,7 };
	int* p;
	p = dizi;
	int sayac = 7;
	ort(p, sayac);
	return 1907;
}

