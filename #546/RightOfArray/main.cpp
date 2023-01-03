#include <iostream>

using namespace std;

int *array_Calculation(int a[], int array_Length);

int main()
{
    int a[] = {3,4,9,6,1};
    const int a_Length = sizeof(a) / sizeof(a[0]);
    int b[a_Length];
    int* pointer = array_Calculation(a, a_Length);
    for(int i = 0; i < a_Length; i++)
    {
        cout << pointer[i] << " ";
    }
    return 0;
}

int *array_Calculation(int a[], int array_Length)
{
    int counter = 0;
    int* b = new int[array_Length];
    for(int i = 0; i < array_Length; i++)
    {
        counter = 0;
        for(int j = array_Length - 1; j != i; j--)
        {
            if(a[i] > a[j])
                counter++;
        }
        b[i] = counter;
    }
    return b;
}
