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
void removeByValue(name** head, string n)		//core function
{
	name* h = *head;
	if (h == NULL)
	{
		cout << "Value does not exist!" << endl;
		return;
	}
	if (h->n == n)
	{
		name* temp = NULL;
		temp = *head;
		h = h->next;
		delete temp;
		temp = NULL;
		return;
	}
	name* temp = h;
	name* temp2 = h;
	while (temp2 != NULL && temp2->n != n)
	{
		temp = temp2;	//node at pos - 1
		temp2 = temp2->next;	//node at pos
	}
	if (temp2 == NULL)
	{
		cout << "Value not found!" << endl;
		return;
	}
	temp->next = temp2->next;	//pointing node at pos-1 to pos+1
	delete temp2;	//deleting pos node
	temp2 = NULL;
}
table insert(table data, string name)
{
	int temp = hashFunction(name);
	insertNode(&data.names[temp], name);
	return data;
}
table deleteValue(table data, string n)
{
	int temp = hashFunction(n);
	removeByValue(&data.names[temp], n);
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
bool search(table data, string n)
{
	int rec = 1;
	int key = hashFunction(n);
	name* temp = data.names[key];
	while (temp != NULL)
	{
		if (temp->n == n)
		{
			cout << "Entry Found!" << endl;
			cout << "Location: In record " << char(65 + key) << " ,record no: " << rec << endl;
			return true;
		}
		temp = temp->next;
		rec++;
	}
	cout << "Entry Not Found!" << endl;
	return false;
}
int main()
{
	table data;
	data = insert(data, "Ahmed");
	data = insert(data, "Ali");
	data = insert(data, "Bob");
	data = insert(data, "Cahir");
	display(data);
	search(data, "Ali");
	data = deleteValue(data, "Ali");
	display(data);
}