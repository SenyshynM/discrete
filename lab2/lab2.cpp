#include <iostream>

using namespace std;

void op_pq(int* p, int* q, int* pq, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i] != 1 || q[i] == 1)
			pq[i] = 1;
		else pq[i] = 0;
	}
}

void op_pr(int* p, int* r, int* pr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i] != 1 || r[i] == 1)
			pr[i] = 1;
		else pr[i] = 0;
	}
}

void op_pqr(int* pq, int* pr, int* pqr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (pq[i] == 1 && pr[i] == 1)
			pqr[i] = 1;
		else
			pqr[i] = 0;
	}
}

int main()
{
	const int n = 8;
	int p[n] = { 0,0,0,0,1,1,1,1 };
	int q[n] = { 0,1,0,1,0,1,0,1 };
	int r[n] = { 0,0,1,1,0,0,1,1 };
	int pq[n];
	int pr[n];
	int pqr[n];
	op_pq(p, q, pq, n);
	op_pr(p, r, pr, n);
	op_pqr(pq, pr, pqr, n);
	cout << "           (p -> q) ^ (p -> r)" << endl << endl;;
	cout << "----------------------------------------------------" << endl;
	cout << "| p | q | r | p -> q | p - r | (p -> q) ^ (p -> r) | " << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "| " << p[i] << " | " << q[i] << " | " << r[i] << " |    " << pq[i] << "   |   " << pr[i] << "   |          " << pqr[i] << "          |" << endl;
	}
	cout << "----------------------------------------------------" << endl;
}