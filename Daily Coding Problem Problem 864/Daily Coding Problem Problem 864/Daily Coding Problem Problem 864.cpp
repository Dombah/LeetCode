/*Good morning! Here's your coding interview problem for today.

This problem was asked by Glassdoor.

An imminent hurricane threatens the coastal town of Codeville. If at most two people can fit in a rescue boat, and the maximum weight limit for a given boat is k, determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80] and a boat limit of 200, the smallest number of boats required will be three.*/

#include <iostream>

using namespace std;

int* exclude_Index;
int exclude_Index_Count = 0;

void AddToArray(int index, int number);
bool isAllowedIndex(int index);

int main()
{
	int weights[] = { 100, 200 , 150 , 50 , 80, 20 , 130};
	int n = sizeof(weights) / sizeof(int), i,j;

	// Array of indexes we don't need to check
	exclude_Index = new int[n];
	int min_Boats = 0, sum = 0;
	
	int k = 200;
	for (i = 0; i < n; i++)
	{
		if (weights[i] == k)
		{ 
			min_Boats++;
			AddToArray(exclude_Index_Count, i);
			continue; 
		}
		for (j = i + 1; j < n; j++)
		{
			if (weights[i] + weights[j] == k)
			{ 
				min_Boats++;
				AddToArray(exclude_Index_Count, i);
				AddToArray(exclude_Index_Count, j);
				break;
			}
		}
		sum += weights[i];
	}
	for (i = 0; i < n; i++)
	{
		if (!isAllowedIndex(i)) { continue; }
		for (j = i + 1; j < n; j++)
		{
			if (!isAllowedIndex(j)) { continue; }
			if (weights[i] + weights[j] <= k)
			{
				min_Boats++;
				AddToArray(exclude_Index_Count, i);
				AddToArray(exclude_Index_Count, j);
				break;
			}

		}
	}
	cout << "Min boats are: " << min_Boats;
	delete [] exclude_Index;
	return 0;
}

void AddToArray(int index, int number)
{
	exclude_Index[index] = number;
	exclude_Index_Count++;
}
bool isAllowedIndex(int index)
{
	for(int i = 0; i < exclude_Index_Count; i++)
	{
		if (exclude_Index[i] == i) { return false; }
	}
	return true;
}
