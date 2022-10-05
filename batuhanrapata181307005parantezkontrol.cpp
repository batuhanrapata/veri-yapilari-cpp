//batuhan rapata 181307005
#include <iostream>
using namespace std;
#define MAX 1000 
int top;
char a[MAX];
class Stack {

public:
	Stack() { top = -1; }
	bool push(int x);
	int pop();
	bool isEmpty();
};
bool Stack::push(int x)
{
	if (top >= (MAX - 1))
	{
		cout << "stack is full..." << endl;
		return false;
	}
	else
	{
		a[++top] = x;
		return true;
	}
}
int Stack::pop()
{
	if (top < 0)
	{
		cout << "stack is empty..." << endl;
		return 0;
	}
	else
	{
		int x = a[top--];
		return x;
	}
}
bool Stack::isEmpty()
{
	return (top < 0);
}
char parantez(string ifade)
{
	Stack S;
	for (int i = 0; i < ifade.length(); i++)
	{
		switch (ifade[i])
		{
		case '(':
		case '[':
			S.push(ifade[i]);
			break;
		case ')':
			if (a[top] != '(')
				return ')';
			else
				S.pop();
			break;
		case ']':
			if (a[top] != '[')
				return ']';
			else
				S.pop();
			break;
		}
	}
	return a[top];
}
int main()
{
	string ifade = "";
	cout << "ifadenizi giriniz: ";
	cin >> ifade;
	switch (parantez(ifade))
	{
	case '(':
		cout << "ifade icerisinde () parantezi kapatilmamis." << endl;
		break;
	case '[':
		cout << "ifade icerisinde [] parantezi kapatilmamis." << endl;
		break;
	case ')':
		cout << "ifade icerisinde () parantezi acilmamis." << endl;
		break;
	case ']':
		cout << "ifade icerisinde [] parantezi acilmamis." << endl;
		break;
	default:
		cout << "ifadede parantez hatası yoktur.";
		break;
	}
	return 0;
}

