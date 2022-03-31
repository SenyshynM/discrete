#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

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
	//TASK 1
	int n = 0;
	cout << "TASK 1:" << endl << "n = ";
	cin >> n;

	//replacements
	int* rep = new int[n];
	for (int k = 0; k < n; k++)
	{
		rep[k] = k + 1;
	}

	sort(rep, rep + n);
	cout << n << "! = " << fact(n) << " replacements from " << n << " elements:" << endl;
	do
	{
		for (int k = 0; k < n; k++)
		{
			cout << setw(2) << rep[k];
		}
		cout << endl;
	} while (next_permutation(rep, rep + n));

	//TASK 2
	int r = 0;
	cout << endl;
	cout << "TASK 2:"<< endl
		 << "with = ";
	cin >> n;
	cout << "by = ";
	cin >> r;
	cout << endl;
	r = abs(r);

	//Kombinations
	vector<bool> comb(n);

	fill(comb.begin(), comb.begin() + r, true);

	cout << "Combinations with " << n << " by " << r << ":" << endl;
	do
	{
		for (int i = 0; i < n; ++i)
		{
			if (comb[i])
			{
				cout << setw(2) << (i + 1);
			}
		}
		cout << endl;
	} while (prev_permutation(comb.begin(), comb.end()));
}