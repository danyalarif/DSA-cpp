#pragma once
#include<iostream>

using namespace std;

struct letter		//struct for holding an edge
{
	int count;
	char ch;
};
class HashTable
{
private:
	int total;
	int* table;
public:
	HashTable()
	{
		total = 26;
		table = new int[total];
		for (int i = 0; i < total; i++)
		{
			table[i] = 0;
		}
	}
	int hashKey(char ch)		//hash value
	{
		char temp = ch;
		if ((int)temp <= 90 && (int)temp >= 65)		//converting to uppercase
		{
			temp = char((int)temp + 32);
		}
		return (int)temp - 97;
	}
	void insert(char value)
	{
		int key = hashKey(value);
		table[key] = table[key] + 1;
	}
	bool isCellEmpty(int index)
	{
		if (table[index] == -1)
			return true;
		else
			return false;
	}
	void deleteValue(char value)
	{
		int key = hashKey(value);
		if (table[key] == 0)
			return;
		else
			table[key] = table[key] - 1;
	}
	int searchValue(char value)
	{
		int key = hashKey(value);
		return table[key];
	}
};
class MaxHeap
{
private:
	letter* heap;		//heap array
	int nodes;		//total size
	int last;		//pointer to last element
public:
	MaxHeap()
	{
		nodes = 5;
		heap = new letter[nodes];		//creating an array of edges
		last = -1;
	}
	MaxHeap(int size)
	{
		nodes = size;
		heap = new letter[nodes];
		last = -1;
	}
	void swap(int index1, int index2)		//swapping two edges by deep copy
	{
		letter temp;
		temp.count = heap[index1].count;
		temp.ch = heap[index1].ch;
		heap[index1].count = heap[index2].count;
		heap[index1].ch = heap[index2].ch;
		heap[index2].count = temp.count;
		heap[index2].ch = temp.ch;
	}
	void insert(int count, char ch)
	{
		letter temp;		//initilazing an edge
		temp.count = count;
		temp.ch = ch;
		//if heap empty
		if (last == -1)
		{
			last++;
			heap[last] = temp;
		}
		else if (last == nodes - 1)
		{
			cout << "No space" << endl;
		}
		else
		{
			last++;
			heap[last] = temp;
			int key = last;
			int parent = (key - 1) / 2;		//getting parent
			while (parent >= 0 && heap[key].count > heap[parent].count)		//placing at correct positions
			{
				swap(parent, key);
				key = parent;
				parent = (key - 1) / 2;
			}
		}
	}
	bool isEmpty()
	{
		if (last == -1)
			return true;
		else
			return false;
	}
	int getMax(int a, int b)
	{
		if (heap[a].count > heap[b].count)
			return a;
		else
			return b;
	}
	letter getTop()
	{
		return heap[0];
	}
	void deleteMax()
	{
		heap[0] = heap[last];
		last--;
		int current = 0;
		int leftChild = (2 * current) + 1;		//index of left child
		int rightChild = (2 * current) + 2;		//index of right child
		int maxChild = getMax(leftChild, rightChild);		//index of Max child 
		//Heapify
		while (current < last && heap[maxChild].count > heap[current].count)
		{
			swap(current, maxChild);
			current = maxChild;		//updating the current; Current moves to the position of the node that was swapped
			leftChild = (2 * current) + 1;
			rightChild = (2 * current) + 2;
			if (leftChild < last && rightChild < last)		//if both children exist
			{
				maxChild = getMax(leftChild, rightChild);
			}
			else if (leftChild < last)		//if only left child exists
			{
				maxChild = leftChild;
			}
			else if (rightChild < last)		//if only right child exists
			{
				maxChild = rightChild;
			}
			else
			{
				break;		//if no children exist
			}
		}
	}
	void printHeap()
	{
		for (int i = 0; i <= last; i++)
		{
			cout << heap[i].ch << " " << heap[i].count << endl;
		}
	}
};
void rearrangeString(string text)
{
	HashTable table;
	MaxHeap h;
	//inserting in hash table
	for (int i = 0; i < text.length(); i++)
	{
		table.insert(text[i]);
	}
	//inserting in heap from table
	//This technique does not preserve order
	/*for (char ch = 'a'; ch <= 'z'; ch++)
	{
		int value = table.searchValue(ch);
		if (value != 0)
		{
			h.insert(value, ch);
		}
	}*/
	bool visited[26];
	for (int i = 0; i < 26; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < text.length(); i++)
	{
		int index = table.hashKey(text[i]);
		if (!(visited[index]))
		{
			int value = table.searchValue(text[i]);
			h.insert(value, text[i]);
			visited[index] = true;
		}
	}
	string newString = "";
	while (!(h.isEmpty()))
	{
		//cout << "A";
		letter tmp1 = h.getTop();
		newString += tmp1.ch;
		//cout << tmp1.ch << endl;
		h.deleteMax();
		if (h.isEmpty() && tmp1.count > 1)
		{
			cout << "Invalid!" << endl;
			return;
		}
		if (h.isEmpty())
			break;
		letter tmp2 = h.getTop();
		newString += tmp2.ch;
		h.deleteMax();
		if (tmp1.count > 1)
			h.insert(tmp1.count - 1, tmp1.ch);
		if (tmp2.count > 1)
			h.insert(tmp2.count - 1, tmp2.ch);
	}
	cout << newString << endl;
}
int main()
{
	//string str = "amamooeaeb";
	string str = "aaaabc";
	rearrangeString(str);
	//build max heap
	//get max from heap
	//remove max and decrease its frequency
	//Get the new max from heap
	//add back the removed max if frequency > 0
}