//batuhan rapata 181307005
#include <iostream>
using namespace std;
int main()
{
	int sayi = 34;
	int* ptr1;
	int* ptr2;
	int* ptr3;
	int* ptr4;

	cout << &ptr1 << " " << &ptr2 << " " << &ptr3 << " " << &ptr4 << " " << sayi<<endl;
	ptr1 = &sayi; 
	
	cout << *ptr1 << " " << &ptr2 << " " << &ptr3 << " " << &ptr4 << " " << sayi<<endl;
	ptr2 = *&ptr1;
	
	cout << *ptr1 << " " << *ptr2 << " " << &ptr3 << " " << &ptr4 << " " << sayi<<endl;
	ptr3 = *&ptr2;
	
	cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << " " << &ptr4 << " " << sayi << endl;
	ptr4 = *&ptr3;
	
	cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << " " << *ptr4 << " " << sayi << endl;

	cout << &ptr4;
	
	return 1907;
}

