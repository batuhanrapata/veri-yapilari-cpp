// batuhanrapata181307005odev1.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

// batuhanrapata181307005odev1
#include <iostream>
#include <math.h>
using namespace std;
int vizeort(int a, int b)
{
	int ortalama = (a + b) / 2;
	return ortalama;
}
int cevre(int c, int d)
{
	int cevre = (2 * c) + (2 * d);
	return cevre;
}
int alan(int e, int f)
{
	int alan = e * f;
	return alan;
}
int main()
{
	/* batuhanrapata181307005odev1

	1 - Kullanıcının seçimine göre toplama veya çıkarma işlemi yapan programı yazınız	*/

	string islem;
	int sayi1, sayi2, topla, cikar;
	cout << "SAYI 1 GIRIN \n";
	cin >> sayi1;
	cout << "SAYI 2 GIRIN \n";
	cin >> sayi2;
	cout << "ISLEM SECINIZ (+\-)\n";
	cin >> islem;
	if (islem == "+")
	{
		topla = sayi1 + sayi2;
		cout << "\n" << topla << "\n";
	}
	else if (islem == "-")
	{
		cikar = sayi1 - sayi2;
		cout << "\n" << cikar << "\n";
	}
	else
	{
		cout << "YANLIS DEGER GIRILDI";
	}



	//2-Klavyeden girilen sayıya ve seçime göre matemtiksel işlemleri yapan programı yazınız.1:Karekok, 2:Kare, 3:Mutlak Deger

	int girilensayi, karekok = 0, kare = 0, mutlak = 0, secim = 0;
	cout << "\n SAYI GIR \n";
	cin >> girilensayi;
	cout << "\n SECIM YAP 1:Karekok, 2:Kare, 3:Mutlak Deger \n";
	cin >> secim;
	if (secim == 1)
	{
		karekok = sqrt(girilensayi);
		cout << karekok << "\n";
	}
	else if (secim == 2)
	{
		kare = pow(girilensayi, 2);
		cout << kare << "\n";
	}
	else if (secim == 3)
	{
		if (girilensayi < 0)
		{
			mutlak = girilensayi * -1;
			cout << mutlak << "\n";
		}

	}
	else
	{
		cout << "YANLIS DEGER GIRILDI";
	}



	//3- Klavyeden -1 girilene kadar, girilen sayıların ortalamalarını gösteren programı yazınız

	int girilensayi2, sayac = 0, toplam = 0;
	float ort = 0;
	cout << "-1 GIRILENE KADAR DEVAM EDECEKTIR \n";
	do
	{
		girilensayi2 = 0;
		cin >> girilensayi2;
		sayac++;
		toplam = toplam + girilensayi2;
	} while (girilensayi2 != -1);
	ort = (toplam + 1) / (sayac - 1);
	cout << ort << "\n";


	//4-Klavyeden girilen rakamlari farkli 4 basamakli sayinin basamaklarini bulan programı C++ ile yazınız. Sayi 4 basamakli olmazsa hata verecek! Sayının rakamlari farkli olmazsa hata verecek!
	int basamaklisayi, birler, onlar, yuzler, binler, i = 0, tempsayi;
	cout << "RAKAMLARI FARKLI DORT BASAMAKLI SAYI GIRINIZ \n";
	cin >> basamaklisayi;
	tempsayi = basamaklisayi;
	while (tempsayi > 0)
	{
		tempsayi = tempsayi / 10;
		i++;
	}
	if (i == 4)
	{
		binler = basamaklisayi / 1000;
		basamaklisayi = basamaklisayi - (binler * 1000);
		yuzler = basamaklisayi / 100;
		basamaklisayi = basamaklisayi - (yuzler * 100);
		onlar = basamaklisayi / 10;
		basamaklisayi = basamaklisayi - (onlar * 10);
		birler = basamaklisayi % 10;
		if (binler != birler && binler != onlar && binler != yuzler && yuzler != birler && yuzler != onlar && onlar != birler)
		{
			cout << binler << "\n" << yuzler << "\n" << onlar << "\n" << birler << "\n";
		}
		else
		{
			cout << "BASAMAKLAR AYNI";
		}
	}
	else
	{
		cout << "SAYI 4 BASAMAKLI DEGIL";
	}



	//5-C++ ile Fonksiyon kullanarak Vize ve Final notu girilen öğrencinin ortalamasını hesaplayınız.
	int vize, final;
	cout << "VIZE NOTU GIR ";
	cin >> vize;
	cout << "FINAL NOTU GIR ";
	cin >> final;
	cout << vizeort(vize, final) << "\n";



	//6 - C++ ile Fonksiyon kullanarak dikdörtgen alan ve çevre hesaplayan örneği oluşturunuz
	int akenar, bkenar;
	cout << "A KENARI ";
	cin >> akenar;
	cout << "b KENARI ";
	cin >> bkenar;
	cout << "CEVRE " << cevre(akenar, bkenar) << "\nALAN " << alan(akenar, bkenar);

	return 0;
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
