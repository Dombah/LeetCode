/*Good morning! Here's your coding interview problem for today.
This problem was asked by Microsoft.

Compute the running median of a sequence of numbers. That is, given a stream of numbers,
print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.
For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2				->				[2]
1.5				->				[1,2] 
2				->				[1, 2, 5]
3.5				->				[1, 2, 5, 7]
2				->				[1, 2, 2, 5, 7]
2				->				[0, 1, 2, 2, 5, 7]
2				->				[0, 1, 2, 2, 5, 5, 7] */

#include <iostream>

using namespace std;

double averageInArray(int* V, int lower, int upper);
void inputArray(int* V, int n);
void printArray(int* V, int n);
int* allocate(int n);
void Swap(int* a, int* b);
void quickSort(int* V, int lower, int upper);
int partition(int* V, int lower, int upper);

int main()
{
	int n;
	int* V;
	cout << "Enter the number of elements: ";
	cin >> n;
	V = allocate(n);
	inputArray(V, n);
	cout << endl;
	cout << V[0] << endl;
	for (int i = 1; i < n; i++)
	{
		quickSort(V, 0, i);
		if (i % 2 == 0)
		{
			cout << V[i / 2] << endl;
		}
		else
		{
			cout << averageInArray(V, (i/2), (i/2)+1) << endl;
		}
	}
}

double averageInArray(int* V, int lower, int upper)
{
	double sum = 0.0;
	for (int i = lower; i <= upper; i++)
	{
		sum += V[i];
	}
	return sum / 2;
}

void inputArray(int* V, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> *(V + i);
	}
}

void printArray(int* V, int n)
{
	cout << "[";
	for (int i = 0; i < n; i++)
	{
		
		if (!(i == n - 1))
		{
			cout << V[i] << ",";
		}
		else
		{
			cout << V[i] << "]";
		}
	}
	cout << endl;
}

int* allocate(int n)
{
	int* array_ = new int[n];
	return array_;
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int* V, int lower, int upper)
{
	if (lower < upper)
	{
		int p = partition(V, lower, upper);
		quickSort(V, lower, p - 1);
		quickSort(V, p + 1, upper);
	}
}

int partition(int* V, int lower, int upper)
{
	int pivot = V[upper];
	int i = lower;
	for (int j = lower; j < upper; j++)
	{
		if (V[j] <= pivot)
		{
			Swap(&V[j], &V[i]);
			i++;
		}	
	}
	Swap(&V[i], &V[upper]);
	return i;
}


