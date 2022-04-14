#include <iostream>

using namespace std;

void printch(int* x)
{
	for (int i = 0; i < 8; i++)
		cout << x[i];
	cout << endl;
}

void oper_or(int* fir, int* sec, int* operation)
{
	for (int i = 0; i < 8; i++)
	{
		if (fir[i] == 1 || sec[i] == 1)
			operation[i] = 1;
		else
			operation[i] = 0;
	}
}

void oper_and(int* fir, int* sec, int* operation)
{
	for (int i = 0; i < 8; i++)
	{
		if (fir[i] == 1 && sec[i] == 1)
			operation[i] = 1;
		else
			operation[i] = 0;
	}
}

void oper_xor(int* fir, int* sec, int* operation)
{
	for (int i = 0; i < 8; i++)
	{
		if (fir[i] == 1 && sec[i] == 1 || fir[i] == 0 && sec[i] == 0)
			operation[i] = 0;
		else
			operation[i] = 1;
	}
}

void zavd2()
{
	cout << endl << endl << "Zavd 2" << endl;
	const int n = 8;
	int fir[n] = { 1, 1, 1, 0, 0, 0, 1, 0 };
	int sec[n] = { 1, 0, 1, 0, 1, 0, 1, 0 };
	int operation[n];
	printch(fir);
	printch(sec);
	cout << endl << "or:" << endl;
	oper_or(fir, sec, operation);
	printch(operation);
	cout << endl << "and:" << endl;
	oper_and(fir, sec, operation);
	printch(operation);
	cout << endl << "xor:" << endl;
	oper_xor(fir, sec, operation);
	printch(operation);
}

void zavd1()
{
	cout << "Zavd 1" << endl;
	bool p, q;
	cout << "p: "; cin >> p;
	cout << "q: ";  cin >> q;
	cout << endl;
	if (p == true && q == true) // кон’юнкції
		cout << "p and q: true" << endl;
	else cout << "p and q: false" << endl;

	if (p == true || q == true) // диз’юнкції
		cout << "p or q: true" << endl;
	else cout << "p or q: false" << endl;

	if (p == true ^ q == true) // альтернативного або
		cout << "p xor q: true" << endl;
	else cout << "p xor q: false" << endl;

	if (p == true && q == false) // імплікації p -> q
		cout << "p -> q: true" << endl;
	else cout << "p -> q: false" << endl;

	if (p == false && q == true) // імплікації q -> p
		cout << "q -> p: true" << endl;
	else cout << "q -> p: false" << endl;

	if ((!p == true || q == true) && (p == true || !q == true)) //еквіваллентності p ~ q
		cout << "p ~ q: true" << endl;
	else cout << "p ~ q: false" << endl;
}

int main()
{	
	zavd1(); // завдання 1
	zavd2(); // завдання 2
}