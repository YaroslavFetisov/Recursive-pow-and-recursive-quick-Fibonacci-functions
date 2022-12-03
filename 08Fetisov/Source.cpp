#include <iostream>
#include <cmath>;
#include <cstdlib>;
#include "Header.h";

using namespace std;

unsigned int zetCounter = 0;
unsigned int fibCounter = 0;

void zet(double& y, double& x, unsigned int& k)
{
	if (k > 0)
	{
		if (k % 2 == 1)
		{
			y *= x; k--;
			zetCounter++;
		}
		else
		{
			x *= x; k /= 2;
			zetCounter++;
		};
		zet(y, x, k);
	}
}

double power(double x, unsigned int n)
{
	double y = 1;
	zet(y, x, n);
	return y;
}

void fib(double& f1, double& f2, unsigned int n)
{
	if (n >= 2)
	{
		fibCounter++;
		double f = f2; f2 += f1; f1 = f;
		fib(f1, f2, n - 1);
	}
};

double Fibonaci(unsigned int n)
{
	double f0 = 0, f1 = 1;
	switch (n)
	{
	case 0:
		return f0; break;
	case 1:
		return f1; break;
	default:
		fib(f0, f1, n);
		return f1;
	}
};


void main(void) {

	for (int i = 0; i < 10; i++) {
		int n = rand() % 100;
		int x = rand() % 1000 + (double)(rand() % 10) / 100;
		if (rand() % 2 == 1) {
			x *= -1;
		}
		cout << "Cmath power: \t" << pow(x, n) << endl;
		cout << "Power: \t\t" << power(x, n) << endl;
		cout << "Call's number: \t" << zetCounter << "\n" << endl;
		zetCounter = 0;
	}
	cout << "\n-------------------------------------------------------\n\n" << endl;

	for (int i = 0; i < 10; i++) {
		int n = rand() % 1000;
		cout << "Fibonacci: \t" << Fibonaci(n) << endl;
		cout << "Call's number: \t" << fibCounter << "\n" << endl;
		fibCounter = 0;
	}
	cout << "\n-------------------------------------------------------\n\n" << endl;

	for (int i = 0; i < 10; i++) {
		int n = rand() % 47;
		cout << "Quick Fib: \t" << quickFib(n) << endl;
	}
}