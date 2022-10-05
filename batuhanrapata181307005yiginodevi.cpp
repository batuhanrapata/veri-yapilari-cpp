//batuhan rapata 181307005
#include <iostream>
using namespace std;
#define size 10
class stack
{
	char dizi[size];
	int tos;

public:
	stack();
	void push(char ch);
	char pop();
};
stack::stack()
{
	cout << "yigin olusturuldu..." << endl;
	tos = 0;
}
void stack::push(char ch)
{
	if (tos == 10)
	{
		cout << "yigin doludur..." << endl;
	}
	else
	{
		dizi[tos] = ch;
		tos++;
	}
}
char stack::pop()
{
	if (tos == 0)
	{
		cout << "yigin bostur..." << endl;
	}
	else
	{
		tos--;
		return dizi[tos];
	}
}
int main()
{
	stack s1, s2;

	string isim = "";
	cout << "isim gir: ";
	cin >> isim;

	for (int i = 0; i < isim.length(); i++)
	{
		s1.push(isim[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << s1.pop()<<"\t"; //yigindan cikardigigimda isim ters yazar cunku stackte ilk giren son cikar 
	}
	cout << endl;
	for (int i = 0; i < 11; i++)
	{
		s2.push('a'); //yigini tasirmak icin 11 eleman ekledim ve dolu mesaji aldim
	}
	cout << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << s2.pop();//yiginin bos oldugunu kanitlamak icin 11 eleman cikarip bos mesaji aldim
	}
	return 1;
}