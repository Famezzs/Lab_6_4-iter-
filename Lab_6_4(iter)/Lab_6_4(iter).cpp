// Lab_6_4(iter).cpp
// Козубенко Андрій
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів.
// Варіант 10
// Ітераційний спосіб
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;
using std::endl;

void CreateArr(int *a, const int size);
void PrintArr(int *a, const int size);
int Min(int *a, const int size);
int SearchZero(int *a, const int size);
int AbsSum(int *a, const int size, int Number);
void SortArr(int *a, const int size);

int main()
{
	int n;
	int numzero;

	cout << "How many elements should a new array consist of?\n";
	cout << "n = "; cin >> n;

	if (n <= 0)
	{
		std::cerr << "n must be > 0";
		return -1;
	}
	
	int *a = new int[n];

	CreateArr(a, n);
	PrintArr(a, n);

	cout << "Minimal absolute value in the array = " << Min(a, n) << endl;

	numzero = SearchZero(a, n);
	if (numzero != -1)
		cout << "Sum of absolute values of all elements after first zero encountered = " << AbsSum(a, n, numzero) << endl;
	else
		cout << "No zeros encountered" << endl;

	SortArr(a, n);
	PrintArr(a, n);

	delete[] a;
	return 0;
}

void CreateArr(int *a, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i << "] = "; cin >> a[i];
	}
}

void PrintArr(int *a, const int size)
{
	cout << "a = { ";
	
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << a[i];
		
		if (i < size - 1)
			cout << ", ";
	}

	cout << " }" << endl;
}

int Min(int *a, const int size)
{
	int min = a[0];

	for (int i = 1; i < size; i++)
	{
		if (abs(a[i]) < abs(min))
			min = a[i];
	}

	return min;
}

int SearchZero(int *a, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 0)
			return i;
	}

	return -1;
}

int AbsSum(int *a, const int size, int Number)
{
	if (Number == (size - 1))
		return 0;
	else
	{
		int S = 0;

		for (int i = Number + 1; i < size; i++)
		{
			S += abs(a[i]);
		}

		return S;
	}
}

void SortArr(int *a, const int size)
{
	for (int z = 0; z < size / 2.0; z++)
	{
		for (int i = 0; i < size - z - 1; i++)
		{
			int tmp = a[i + z];
			a[i + z] = a[i + z + 1];
			a[i + z + 1] = tmp;
		}
	}
}