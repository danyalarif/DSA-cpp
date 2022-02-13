#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct node
{
	node* prev;
	int num;
	string name;
	node* next;
};
int displayMenu()
{
	int choice;
	cout << "\n\n\n";
	cout << "******************MAIN MENU*******************" << endl;
	cout << "**********************************************" << endl;
	cout << "1. DISPLAY PAGES" << endl;
	cout << "2. DELETE PAGE" << endl;
	cout << "3. UPDATE PAGE" << endl;
	cout << "4. INSERT PAGE" << endl;
	cout << "5. SEARCH PAGE" << endl;
	cout << "6. EXIT" << endl;
	cout << "***********************************************" << endl;
	cout << "\n\n\n";
	cout << "Your Choice: ";
	cin >> choice;
	return choice;
}
void printPages(node* tail)
{
	if (tail == NULL)
	{
		cout<<"No Pages Found!\n\n" << endl;
		return;
	}
	int count = 1;
	system("CLS");
	node* head = tail->next;
	cout << "Page Number" << "\t\tPage Name\t" << setw(17) << "Number Of Images"  << endl;
	do
	{
		cout << count << setw(27) << head->name << setw(18) << head->num <<endl;
		head = head->next;
		count++;
	} while (head != tail->next);
}
node* createPage(node* tail, int num, string name)	//use to create a new list
{
	node* temp = new node;
	tail = temp;
	tail->prev = tail;
	tail->next = tail;
	tail->num = num;
	tail->name = name;
	return tail;
}
node* addAtEnd(node* tail, int num, string name)
{
	if (tail == NULL)
	{
		cout << "No Pages Found!\n\n" << endl;
		return tail;
	}
	node* temp = new node;
	node* head = tail->next;
	tail->next = temp;
	temp->prev = tail;
	temp->next = head;
	head->prev = temp;
	temp->num = num;
	temp->name = name;
	return temp;
}
node* addAtBeginning(node* tail, int num,string name)
{
	if (tail == NULL)
	{
		cout << "No Pages Found!\n\n" << endl;
		return tail;
	}
	node* temp = new node;
	node* head = tail->next;
	tail->next = temp;
	temp->prev = tail;
	temp->next = head;
	head->prev = temp;
	temp->num = num;
	temp->name = name;
	return tail;
}

node* addAtPos(node* tail, int num,string name, int pos)
{
	if (tail == NULL)
	{
		cout << "No Pages Found!\n\n" << endl;
		return tail;
	}
	if (pos == 1)
	{
		tail = addAtBeginning(tail, num,name);
		return tail;
	}
	int count = 1;
	node* temp = new node;
	node* before = tail->next;
	node* after = tail->next;
	while (count < pos)
	{
		if (count != 1)
		{
			if (after == tail->next->next)	//if the pos > number of nodes
			{
				cout << "Out of Range!" << endl;
				return tail;
			}
		}
		before = after;
		after = after->next;
		count++;
	}
	if (after == tail->next)
	{
		tail = addAtEnd(tail, num,name);
		return tail;
	}
	before->next = temp;
	temp->prev = before;
	temp->num = num;
	temp->name = name;
	temp->next = after;
	after->prev = temp;
	return tail;
}
node* deletePage(node* tail, string name)
{
	if (tail == NULL)
	{
		cout << "No Pages Found!\n\n" << endl;
		return tail;
	}
	node* head = tail->next;
	node* temp = head;
	bool found = false;
	if (head == tail)	///if there is only a single node in the list
	{
		if (head->name == name)
		{
			delete tail;
			tail = NULL;
			found = true;
		}
	}
	else if (head->name == name)	//if page is on first node
	{
		head = head->next;	//making 2nd node head
		head->prev = tail;		//linking head with tail
		tail->next = head;	//same
		delete temp;	//deleting first node
		temp = NULL;
		found = true;
	}
	else if (tail->name == name)	//if page is on last node
	{
		temp = tail;
		tail = tail->prev;	//making 2nd last node tail 
		tail->next = head;
		head->prev = tail;
		delete temp;
		temp = NULL;
		found = true;
	}
	else
	{
		while (temp != tail)
		{
			if (temp->name == name)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		if (found == true)
		{
			temp->prev->next = temp->next;	//pointing node at pos - 1 to pos + 1
			temp->next->prev = temp->prev;
			delete temp;
			temp = NULL;
		}
	}
	if (found == true)
		cout << "Page Deleted Successfully\n" << endl;
	else
		cout << "Page NOT found!\n" << endl;
	return tail;
}
node* updatePage(node* tail, string name)
{
	if (tail == NULL)
	{
		cout << "No Pages Found!\n\n" << endl;
		return tail;
	}
	int num;
	node* head = tail->next;
	node* temp = head;
	bool found = false;
	do
	{
		if (temp->name == name)
		{
			found = true;
			do {
				cout << "Enter number of images: ";
				cin >> num;
				if (num < 0)
					cout << "No of Images can't be negative!" << endl;
			} while (num < 0);
			cin.ignore();
			cout << "Enter page name: ";
			getline(cin, name);
			temp->name = name;
			temp->num = num;
			break;
		}
		temp = temp->next;
	} while (temp != tail->next);
	if (found == true)
		cout << "Page Updated Successfully\n" << endl;
	else
		cout << "Page NOT found!\n" << endl;
	return tail;
}
node* searchPage(node* tail, string name)
{
	if (tail == NULL)
	{
		cout << "No Pages Found!\n\n" << endl;
		return tail;
	}
	int count = 1;
	node* head = tail->next;
	node* temp = head;
	bool found = false;
	do
	{
		if (temp->name == name)
		{
			found = true;
			break;
		}
		temp = temp->next;
		count++;
	} while (temp != tail->next);
	if (found == true)
	{
		cout << "Page Found Successfully\n" << endl;
		cout << "Page Number: " << count << endl;
		cout << "Page Name: " << temp->name << endl;
		cout << "Number of Images: " << temp->num << endl;
	}
	else
		cout << "Page NOT found!\n" << endl;
	return tail;
}
int main()
{
	system("Color 9");	//Since ma'am once told me she likes blue
	int n,count = 0,num,choice,pos;
	string name;
	node* tail = new node;
	do {
		cout << "Enter number of pages to be inserted now: ";
		cin >> n;
		if (n <= 0)
			cout << "Pages must be greater than zero" << endl;
	} while (n <= 0);
	cout << endl;
	while (count < n)
	{
		do {
			cout << "Enter number of images: ";
			cin >> num;
			if (num < 0)
				cout << "No of Images can't be negative!" << endl;
		} while (num < 0);
		cin.ignore();
		cout << "Enter page name: ";
		getline(cin, name);
		if (count == 0)
		{
			tail = createPage(tail, num, name);
		}
		else
		{
			tail = addAtEnd(tail, num, name);
		}
		count++;
		cout << endl;
	}
	//displaying main menu
	do {
		choice = displayMenu();
		if (choice == 1)
		{
			printPages(tail);
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Enter page name: ";
			getline(cin, name);
			tail = deletePage(tail, name);
		}
		else if (choice == 3)
		{
			cin.ignore();
			cout << "Enter page name: ";
			getline(cin, name);
			tail = updatePage(tail, name);
		}
		else if (choice == 4)
		{
			system("CLS");
			cout << "1. INSERT AT START" << endl;
			cout << "2. INSERT AT END" << endl;
			cout << "3. INSERT AT POSITION" << endl;
			cout << "\nYour Choice: ";
			cin >> choice;
			cout << endl;
			system("CLS");
			do {
				cout << "Enter number of images: ";
				cin >> num;
				if (num < 0)
					cout << "No of Images can't be negative!" << endl;
			} while (num < 0);
			cin.ignore();
			cout << "Enter page name: ";
			getline(cin, name);
			if (choice == 1)
			{
				tail = addAtBeginning(tail, num, name);
			}
			else if (choice == 2)
			{
				tail = addAtEnd(tail, num, name);
			}
			else if (choice == 3)
			{
				do {
					cout << "Enter position: ";
					cin >> pos;
					if (pos <= 0)
						cout << "Incorrect Position!" << endl;
				} while (pos <= 0);
				tail = addAtPos(tail, num, name, pos);
			}
		}
		else if (choice == 5)
		{
			cin.ignore();
			cout << "Enter page name: ";
			getline(cin, name);
			tail = searchPage(tail, name);
		}
		else if (choice == 6)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid Input!Try again!" << endl;
			continue;
		}
	} while (choice != 6);
}