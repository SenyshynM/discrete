#include <iostream>
#include <iomanip>

using namespace std;

int fact(int x)
{
	int res = 1;
	for (int i = 1; i <= x; i++)
	{
		res = res * i;
	}
	return res;
}

int main()
{
	// task1
	int n = 10;
	int r = 8;
	int first = fact(n);
	int sec = fact(n - r);
	int a = first / sec;
	cout << "Task 1: " <<
		endl << "n = " << n <<
		endl << "r = " << r <<
		endl << "a = " << a <<
		endl <<
		endl;

	// task2
	int i = 10;
	n = i + 5;
	int** F = new int* [n];
	for (int j = 0; j < n; j++)
		F[j] = new int[n];

	int* B = new int[n];

	cout << "Task 2:" << endl;

	// stirling
	for (int j = 0; j < n; j++)
	{
		F[j][0] = 1;
		F[j][j] = 1;
	}

	for (int j = 2; j < n; j++)
		for (int k = 1; k < j; k++)
		{
			F[j][k] = F[j - 1][k - 1] + (k + 1) * F[j - 1][k];
		}
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			if (F[j][k] < 0)
				F[j][k] = 0;

	// bell
	for (int j = 0; j < n; j++)
		B[j] = 0;

	for (int j = 0; j < n; j++)
		for (int k = 0; k < j; k++)
		{
			B[j] = B[j] + F[j][k];
		}


	// print
	cout << "i = " << i << endl << "n = " << n << endl;
	cout << "   |";
	for (int i = 0; i < n; i++)
		cout << setw(10) << i + 1 << "|";
	cout << setw(10) << "BELL" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << setw(3) <<i + 1 << "|";
		for (int j = 0; j < n; j++)
		{
			if (F[i][j] == 0)
				cout << setw(10) << "" << "|";

			else cout << setw(10) << F[i][j] << "|";
		}
		cout << setw(10) << B[i];
		cout << endl;
	}
	cout << endl;
}