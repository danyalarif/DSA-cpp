#include<iostream>

using namespace std;

class MinHeap
{
private:
	int* heap;
	int nodes;
	int last;
public:
	MinHeap()
	{
		nodes = 5;
		heap = new int[nodes];
		last = -1;
	}
	MinHeap(int size)
	{
		nodes = size;
		heap = new int[nodes];
		last = -1;
	}
	void swap(int index1, int index2)
	{
		int temp = heap[index1];
		heap[index1] = heap[index2];
		heap[index2] = temp;
	}
	void insert(int data)
	{
		if (last == -1)
		{
			last++;
			heap[last] = data;
		}
		else if (last == nodes - 1)
		{
			cout << "No space" << endl;
		}
		else
		{
			last++;
			heap[last] = data;
			int key = last;
			int parent = (key - 1) / 2;
			while (parent >= 0 && heap[key] < heap[parent])
			{
				swap(parent, key);
				key = parent;
				parent = (key - 1) / 2;
			}
		}
	}
	void printHeap()
	{
		for (int i = 0; i <= last; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
	int getMinimumOfTwo(int a, int b)
	{
		if (heap[a] < heap[b])
			return a;
		else
			return b;
	}
	void deleteMin()
	{
		heap[0] = heap[last];
		last--;
		int current = 0;
		int leftChild = (2 * current) + 1;		//index of left child
		int rightChild = (2 * current) + 2;		//index of right child
		int minChild = getMinimumOfTwo(leftChild, rightChild);		//index of Min child 
		while (current < last && heap[minChild] < heap[current])
		{
			swap(current, minChild);
			current = minChild;		//updating the current; Current moves to the position of the node that was swapped
			leftChild = (2 * current) + 1;
			rightChild = (2 * current) + 2;
			if (leftChild < last && rightChild < last)
			{
				minChild = getMinimumOfTwo(leftChild, rightChild);
			}
			else if (leftChild < last)
			{
				minChild = leftChild;
			}
			else if (rightChild < last)
			{
				minChild = rightChild;
			}
			else
			{
				break;		//if no children exist
			}
		}
	}
	int getMin()
	{
		return heap[0];
	}
	bool isEmpty()
	{
		if (last == -1)
			return true;
		else
			return false;
	}
	void arrayToHeap(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			insert(arr[i]);
		}
	}
	int getMinSum()
	{
		int num1 = 0, num2 = 0;
		/*for (int i = 0; i <= last; i++)
		{
			if (i % 2 == 0)
				num1 = (num1 * 10) + heap[i];
			else
				num2 = (num2 * 10) + heap[i];
		}*/
		while (!(isEmpty()))
		{
			num1 = (num1 * 10) + getMin();
			deleteMin();
			if ((isEmpty()))
				break;
			num2 = (num2 * 10) + getMin();
			deleteMin();
		}
		return num1 + num2;
	}
};

int main()
{
	//int arr[] = { 6, 8, 4, 5, 2, 3 };
	int arr[] = { 5, 3, 0, 7, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MinHeap h(size);
	h.arrayToHeap(arr, size);
	h.printHeap();
	cout << h.getMinSum() << endl;
	/*h.insert(3);
	h.insert(9);
	h.insert(5);
	h.insert(37);
	h.insert(16);
	h.insert(12);
	h.insert(22);
	h.insert(41);
	h.insert(44);
	h.insert(32);
	h.insert(19);
	h.insert(50);
	h.insert(47);
	h.printHeap();
	h.deleteMin();
	h.printHeap();*/
}