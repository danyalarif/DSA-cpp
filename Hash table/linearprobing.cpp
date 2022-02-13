#include<iostream>

using namespace std;

class HashTable
{
private:
	int total;
	int* table;
public:
	HashTable()
	{
		total = 10;
		table = new int[total];
		for (int i = 0; i < total; i++)
		{
			table[i] = -1;
		}
	}
	HashTable(int s)
	{
		total = s;
		table = new int[total];
	}
	int hashKey(int value)		//hash value
	{
		return value % total;
	}
	int hashKeyByLinearProbing(int value)
	{
		int start = hashKey(value);
		int i = (start + 1) % total;
		while (table[i] != -1)
		{
			i = (i + 1) % total;
			if (i == start)
				return -1;
		}
		return i;
	}
	void insert(int value)
	{
		int key = hashKey(value);
		if (isCellEmpty(key))
		{
			table[key] = value;
		}
		else
		{		//linear probing
			key = hashKeyByLinearProbing(value);
			if (key == -1)
				cout << "Table full!" << endl;
			else
				table[key] = value;
		}
	}
	bool isCellEmpty(int index)
	{
		if (table[index] == -1)
			return true;
		else
			return false;
	}
	void printTable()
	{
		cout << "Location:\t";
		for (int i = 0; i < total; i++)
		{
			cout << i << "\t";
		}
		cout << endl;
		cout << "Value:\t\t";
		for (int i = 0; i < total; i++)
		{
			cout << table[i] << "\t";
		}
		cout << endl;
		cout << "Empty Values = -1\tDeleted Values = -2" << endl << endl;
	}
	void deleteValue(int value)
	{
		int key = hashKey(value);
		if (key == -1)		//this key was never used hence its value does not exist
		{
			cout << "Value does not exist!" << endl;
			return;
		}
		if (table[key] == value)
		{
			table[key] = -2;		//different value for deletion (other than -1) for time complexity reasons
		}
		else
		{
			int i = (key + 1) % total;
			while (table[i] != value)
			{
				i = (i + 1) % total;
				if (i == key)
				{
					cout << "Value does not exist!" << endl;
					break;
				}
			}
			if (i != key)
			{
				table[i] = -2;
			}
		}
	}
	int searchValue(int value)
	{
		int key = hashKey(value);
		if (key == -1)		//this key was never used hence its value does not exist
		{
			cout << "Value does not exist!" << endl;
			return -1;
		}
		if (table[key] == value)
		{
			return key;		//different value for deletion (other than -1) for time complexity reasons
		}
		int i = (key + 1) % total;
		while (table[i] != value)
		{
			i = (i + 1) % total;
			if (i == key)
			{
				cout << "Value does not exist!" << endl;
				break;
			}
		}
		if (i != key)
		{
			return i;
		}
	}
};
int main()
{
	HashTable h1;
	h1.insert(43);
	h1.insert(135);
	h1.insert(72);
	h1.insert(23);
	h1.insert(99);
	h1.insert(19);
	h1.insert(82);
	h1.printTable();
	h1.deleteValue(19);
	h1.printTable();
	int key = h1.searchValue(23);
	if (key != -1)
	{
		cout << "Value is at location " << key << endl;
	}
}