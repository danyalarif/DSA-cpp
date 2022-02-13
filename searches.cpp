#include<iostream>

using namespace std;

int recursiveLinearSearch(int elements[], int size, int i, int value)
{
	if (i == size)
		return -1;
	else if (elements[i] == value)
		return value;
	else
		recursiveLinearSearch(elements, size, i + 1, value);
}
int LinearSearch(int elements[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == key)
			return i;
	}
	return -1;
}
int binarySearch(int elements[], int l, int r, int key)
{
	if (l >= r)
		return -1;
	int m = (l + r) / 2;
	if (elements[m] == key)
		return key;
	if (key > m)
		binarySearch(elements, m + 1, r, key);
	else if (key < m)
		binarySearch(elements, l, m - 1, key);
}
int main()
{
	int elements[5] = { 12, 6, 21,3, 7 };
	int size = sizeof(elements) / sizeof(elements[0]);
	for (int i = 0; i < size; i++)
	{
		cout << elements[i] << " ";
	}
	cout << endl;
	int index = LinearSearch(elements, size, 21);
	if (index == -1)
		cout << "Element not Found!" << endl;
	else
		cout << "Element found at index " << index << endl;
}

