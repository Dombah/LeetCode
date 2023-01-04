/*Good morning! Here's your coding interview problem for today.
This problem was asked by Google.
Given an array of elements, return the length of the longest subarray where all its elements are distinct.
For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].*/ 

#include <iostream>

using namespace std;

int* allocate(int);
void printArray(int*, int , int);
void inputArray(int*, int);

int main()
{
    int n, first_Index, compareValue, currentValue;
    int i, j;
    cout << "Enter number of elements: ";
    cin >> n;

    int* V = allocate(n);
    if (V == NULL) { return -1; }
    cout << "Enter elements in the array: \n";
    inputArray(V, n);
    for (i = 0; i < n; i++)
    {
        first_Index = i;
        for (j = i + 1; j < n; j++)
        {
            if (V[i] == V[j]) { break; }    
        }
        if (j == n) { break; }
    }
    printArray(V, first_Index, n);
    cout << "Longest array has: " << n - first_Index << " elements. " << endl;
    return 0;
}

int* allocate(int n)
{
    int* array_ = new int[n];
    return array_;
}

void printArray(int* array_,int lowerBound,int upperBound)
{
    for (int i = lowerBound; i < upperBound; i++)
    {
        if (i == lowerBound) { cout << "["; }
        if (i == upperBound - 1)
        {
            cout << array_[i] << "]";
        }
        else
        {
            cout << array_[i] << ", ";
        }    
    }
    cout << endl;
}

void inputArray(int* array_, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> array_[i];
    }
}