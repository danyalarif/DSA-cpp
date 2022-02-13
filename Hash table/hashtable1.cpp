#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct name {
	string n;
	name* next;
};
int counting = 0;
struct table {
	name* names[26];
	table()
	{
		for (int i = 0; i < 26; i++)
		{
			names[i] = NULL;
		}
	}
};

int hashFunction(string name)
{
	char temp = name[0];
	if ((int)temp > 90)		//converting to uppercase
	{
		temp = char((int)temp - 32);
	}
	return (int)temp - 65;
}

void insertNode(name** head, string n)
{
	name* temp = new name;
	name* temp2 = *head;
	if (temp2 == NULL)
	{
		temp->n = n;
		temp->next = NULL;
		*head = temp;
		//cout << head->key;
	}
	else
	{
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp->n = n;
		temp->next = NULL;
		temp2->next = temp;
	}
}
table insert(table data, string name)
{
	int temp = hashFunction(name);
	insertNode(&data.names[temp], name);
	return data;
}
void display(table data)
{
	int size = sizeof(data.names) / sizeof(data.names[0]);
	for (int i = 0; i < size; i++)
	{
		if (data.names[i] != NULL)
		{
			cout << "Names starting with " << char(65 + i) << ":" << endl;
			name* temp = data.names[i];
			while (temp != NULL)
			{
				cout << temp->n << ",";
				counting++;
				temp = temp->next;
			}
			cout << "\b ";
			cout << endl;
		}
	}
}
bool search(table data, string key)
{
	int rec = 1;
	int size = sizeof(data.names) / sizeof(data.names[0]);
	for (int i = 0; i < size; i++)
	{
		if (data.names[i] != NULL)
		{
			name* temp = data.names[i];
			while (temp != NULL)
			{
				if (temp->n == key)
				{
					cout << "Entry Found!" << endl;
					cout << "Location: In table " << char(65 + i) << " ,record no: " << rec << endl;
					return true;
				}
				temp = temp->next;
				rec++;
			}
		}
		rec = 1;
	}
	cout << "Entry Not Found!" << endl;
	return false;
}
int main()
{
	string txt;
	table data;
	ifstream fin;
	fin.open("names.txt");
	while (!fin.eof())
	{
		getline(fin, txt);
		data = insert(data, txt);
	}
	fin.close();
	display(data);
	cout << "Total records: " << counting << endl;
	search(data, "John");
}