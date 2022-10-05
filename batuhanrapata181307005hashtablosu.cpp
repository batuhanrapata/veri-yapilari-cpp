// batuhanrapata181307005
#include <iostream>
#include <cstring>
#include <list>
using namespace std;
#define max 250 
class hashtable
{
private:
	static const int hashgroup = max;
	list<pair<int, string>>table[max];
public:
	bool isEmpty()const;
	int hashfunc(int key);
	void insert(int key, string value);
	void delet(int key);
	string search(int key);
	void print();
};
bool hashtable::isEmpty() const {
	int sum{};
	for (int i{}; i < hashgroup; i++)
	{
		sum += table[i].size();
	}
	if (!sum)
	{
		return true;
	}
	return false;
}
int hashtable::hashfunc(int key)
{
	return key % hashgroup;
}
void hashtable::insert(int key, string value)
{
	int hashvalue = hashfunc(key);
	auto& hucre = table[hashvalue];
	auto iteratorbegin = begin(hucre);
	bool keyvarmi = false;
	for (; iteratorbegin != end(hucre); iteratorbegin++)
	{
		if (iteratorbegin->first == key)
		{
			keyvarmi = true;
			iteratorbegin->second = value;
			break;
		}
	}
	if (!keyvarmi)
	{
		hucre.emplace_back(key, value);
	}
}
void hashtable::delet(int key)
{
	int hashvalue = hashfunc(key);
	auto& hucre = table[hashvalue];
	auto iteratorbegin = begin(hucre);
	bool keyvarmi = false;
	for (; iteratorbegin != end(hucre); iteratorbegin++)
	{
		if (iteratorbegin->first == key)
		{
			keyvarmi = true;
			iteratorbegin = hucre.erase(iteratorbegin);
			cout << "deger silindi..." << endl;
			break;
		}
	}
	if (!keyvarmi)
	{
		cout << "deger bulunamadı... " << endl;
	}
}
void hashtable::print()
{
	for (int i{ }; i < hashgroup; i++)
	{
		if (table[i].size() == 0)
		{
			continue;
		}
		auto iteratorbegin = table[i].begin();
		for (; iteratorbegin != table[i].end(); iteratorbegin++)
		{
			cout << "key: " << iteratorbegin->first << " deger: " << iteratorbegin->second << endl;
		}
	}
}
string hashtable::search(int key) {
	int hashvalue = hashfunc(key);
	auto& hucre = table[hashvalue];
	auto iteratorbegin = begin(hucre);
	bool keyvarmi = false;
	for (; iteratorbegin != end(hucre); iteratorbegin++)
	{
		if (iteratorbegin->first == key)
		{
			keyvarmi = true;
			cout << "deger bulundu... " << iteratorbegin->second << endl;
		}
	}
	if (!keyvarmi)
	{
		cout << "deger bulunamadı... " << endl;
		return "";
	}
	return "";
}
int main()
{
	hashtable h;
	string eleman;
	int i = 1;
	int secenek = 0;
	do
	{
		cout << " 1 eleman ekle\n 2 eleman sil\n 3 tabloyu print et\n 4 bosmu dolu mu\n 5 arama yap\n 6 cikis" << endl;
		cin >> secenek;
		switch (secenek)
		{
		case 1:cout << "deger girebilirsiniz (a girilene kadar veya 250 deger girilene kadar devam eder)" << endl;
			do
			{
				cin >> eleman;
				if (eleman != "a")
					h.insert(i, eleman);
				i++;
			} while (eleman != "a" && i != max);
			break;
		case 2:cout << "silmek istediginiz degerin key numarası" << endl;
			cin >> i;
			h.delet(i);
			break;
		case 3:h.print(); break;
		case 4:if (h.isEmpty())
		{
			cout << "tablo bostur" << endl;
		}
			  else
		{
			cout << "tablo dolu" << endl;
		} break;
		case 5:
			cout << "aranacak deger key numarasi" << endl;
			cin >> i; h.search(i); break;
		default:cout << "gecersiz numara girildi" << endl; break;
		}
	} while (secenek != 6);
	cout << "cikis yapildi" << endl;
	system("pause");
	return 0;
}