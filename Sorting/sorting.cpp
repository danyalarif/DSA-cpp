#include<iostream>

using namespace std;

void insertionSort(int elements[], int size);
void bubbleSort(int elements[], int size);
void selectionSort(int elements[], int size);


void swap(int* num1, int* num2);
int partition(int elements[], int l, int r);
void quickSort(int elements[], int l, int r);

void merge(int elements[], int l, int m, int r);
void mergeSort(int elements[], int l, int r);

void combSort(int elements[], int size);
int getNextGap(int total, int current);
void cockTailSort(int elements[], int size);
int main()
{
	int x[10] = { 12,9,-2,5,0,31,2,1,22,43 };
	//int x[25] = { 8,3,1,7,0,74,552,11,77,11,87,66,44,11,12,13,17,54,11,4,32,130304,32342,24342,2 };
	//int[] x = {0,3,4,11,0,10,2};
	//combSort(x, 10);
	cockTailSort(x, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << " ";
	}
}
int getNextGap(int current)
{
	return current / 1.3;
}
void combSort(int elements[], int size)
{
	bool swapped = false;
	int gap = size;
	while (gap != 1)
	{
		gap = getNextGap(gap);
		for (int i = 0; i < size - gap; i++)
		{
			if (elements[i] > elements[i + gap])
			{
				swap(elements[i], elements[i + gap]);
				swapped = true;
			}
		}
		if (!(swapped))
			break;
		swapped = false;
	}
}
void cockTailSort(int elements[], int size)
{
	int start = 0;
	int end = size - 1;
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end; i++)
		{
			if (elements[i] > elements[i + 1])
			{
				swap(elements[i], elements[i + 1]);
				swapped = true;
			}
		}
		if (!(swapped))
			break;
		swapped = false;
		end--;			//since end index contains the sorted element
		for (int i = end; i > start; i--)		//i > start to prevent out of range
		{
			if (elements[i] < elements[i - 1])
			{
				swap(elements[i], elements[i - 1]);
				swapped = true;
			}
		}
	}
}
void selectionSort(int elements[], int size)
{
	int min = 0, temp = 0;
	bool found = false;
	/*Selection sort*/
	for (int i = 0; i < size; i++)
	{
		min = elements[i];
		for (int j = i; j < size; j++)
		{
			if (elements[j] < min)
			{
				min = elements[j];
				temp = j;
				found = true;
			}
		}
		//swapping minimum if required
		if (found == true)
			elements[temp] = elements[i];
		elements[i] = min;
		found = false;
	}
}
void bubbleSort(int elements[], int size)
{
	int tmp, tmp2;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (elements[j] > elements[j + 1])
			{
				tmp = elements[j];
				tmp2 = elements[j + 1];
				elements[j + 1] = tmp;
				elements[j] = tmp2;
			}
		}
	}
}
void insertionSort(int elements[], int size)
{
	int key = 0, j = 0;
	for (int i = 1; i < size; i++)
	{
		key = elements[i];
		j = i - 1;
		while (j >= 0 && key < elements[j])
		{
			elements[j + 1] = elements[j];
			j--;
		}
		elements[j + 1] = key;	//doing j + 1 to add key before the shifted elements
	}
}
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int partition(int elements[], int l, int r)
{
	int temp = 0;
	int pivot = r;
	int i = l;
	int j = r - 1;
	while (j >= l)
	{
		if (i == pivot)
			break;
		if (elements[i] >= elements[pivot])
		{
			if (i == j)		//if i and j are pointing to the same same elements simply swap it with pivot
			{
				/*temp = elements[pivot];
				elements[pivot] = elements[j];
				elements[j] = temp;*/
				swap(elements[pivot], elements[j]);
				j--;
				pivot--;
			}
			else
			{
				/*temp = elements[pivot];
				elements[pivot] = elements[j];
				elements[j] = temp;*/
				swap(elements[pivot], elements[j]);
				/*temp = elements[i];
				elements[i] = elements[pivot];
				elements[pivot] = temp;*/
				swap(elements[pivot], elements[i]);
				pivot--;
				j--;
			}
		}
		else
		{
			i++;
		}
	}
	return pivot;
}
void quickSort(int elements[], int l, int r)
{
	if (l >= r)
		return;
	int pivot = partition(elements, l, r);
	quickSort(elements, l, pivot - 1);
	quickSort(elements, pivot + 1, r);
}
void merge(int elements[], int l, int m, int r)
{
	int size1 = (m + 1) - l;
	int	size2 = r - m;	//size of left and right elements arrays
	int* left = new int[size1];
	int* right = new int[size2];
	//copying elements to temp arrays
	for (int i = 0; i < size1; i++)
		left[i] = elements[i + l];	//doing  + l to start index from l
	for (int j = 0; j < size2; j++)
		right[j] = elements[m + j + 1];		//doing m + 1 to start index after m
	int i = 0, j = 0, k = l;
	//modifying the merged array
	while (i < size1 && j < size2)
	{
		if (left[i] <= right[j])
		{
			elements[k] = left[i];
			i++;
		}
		else
		{
			elements[k] = right[j];
			j++;
		}
		k++;
	}
	//if any elements are not copied than copying them back
	while (i < size1)
	{
		elements[k] = left[i];
		i++;
		k++;
	}
	while (j < size2)
	{
		elements[k] = right[j];
		j++;
		k++;
	}

}
void mergeSort(int elements[], int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	mergeSort(elements, l, m);
	mergeSort(elements, m + 1, r);
	merge(elements, l, m, r);
}
