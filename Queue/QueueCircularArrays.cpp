#include<iostream>

using namespace std;

int queue[5];
int queueSize = sizeof(queue) / sizeof(queue[0]);
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void qdisplay();
void menu();
int main()
{
	int choice;
	do
	{
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			enqueue();
		}
		else if (choice == 2)
		{
			dequeue();
		}
		else if (choice == 3)
		{
			qdisplay();
		}
		else if (choice == 4)
		{
			break;
			//exit(0);
		}
		else
		{
			cout << "Invalid input!" << endl;
		}
	} while (choice != 4);
}
void enqueue()
{
	if (front == (rear + 1) % queueSize)
	{
		cout << "Queue Overflow!\n" << endl;
		return;
	}
	int x;
	cout << "Enter a value: ";
	cin >> x;
	if (front == -1)	//if queue is empty
	{
		front = rear = 0;
		queue[rear] = x;
	}
	else
	{
		rear = (rear + 1) % queueSize;
		queue[rear] = x;
	}
}
void dequeue()
{
	if (front == -1)
	{
		cout << "Queue Underflow!\n" << endl;
		return;
	}
	if (front == rear)	//if only a single value is left
	{
		cout << queue[front] << " is deleted!" << endl;
		front = rear = -1;
	}
	else
	{
		cout << queue[front] << " is deleted!" << endl;
		front = (front + 1) % queueSize;
	}
}
void qdisplay()
{
	int i = front;
	if (front == -1)
	{
		cout << "Queue is Empty!\n" << endl;
		return;
	}
	while (i != rear)
	{
		cout << queue[i] << " ";
		i = (i + 1) % queueSize;	//to stay in bounds of array
	}
	cout << queue[rear] << " ";
	cout << endl;
}
void menu()
{
	cout << "\n\nCIRCULAR QUEUE FUNCTIONS WITH ARRAY" << endl;
	cout << "1. ENQUEUE" << endl;
	cout << "2. DEQUEU" << endl;
	cout << "3. DISPLAY" << endl;
	cout << "4. EXIT\n" << endl;
}