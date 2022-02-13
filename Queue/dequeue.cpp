#include<iostream>

using namespace std;

class DEqueue {
private:
	int* queuee;
	int size;
	int front;
	int rear;
public:
	DEqueue(int s)
	{
		s = size;
		queuee = new int[s];
		front = rear = -1;
	}
	void insertAtFront(int x)
	{
		if (front == -1 && rear == -1)
		{
			front = rear = 0;
			queuee[front] = x;
		}
		else if ((front == 0 && rear == size - 1) || (front == rear + 1))
		{
			cout << "FULL" << endl;
		}
		else if (front == 0)
		{
			front = size - 1;
			queuee[front] = x;
		}
		else
		{
			front--;
			queuee[front] = x;
		}
	}
	void insertAtRear(int x)
	{
		if (front == -1 && rear == -1)
		{
			front = rear = 0;
			queuee[front] = x;
		}
		else if ((front == 0 && rear == size - 1) || (front == rear + 1))
		{
			cout << "FULL" << endl;
		}
		else if (rear == -1)
		{
			rear = 0;
			queuee[rear] = x;
		}
		else
		{
			rear++;
			queuee[rear] = x;
		}
	}
	void deleteFromFront()
	{
		if (front == -1 && rear == -1)
		{
			cout << "EMPTY" << endl;
		}
		else if (front == rear)
		{
			front = rear = -1;
		}
		else if (front == size - 1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
	}
	void deleteFromRear()
	{
		if (front == -1 && rear == -1)
		{
			cout << "EMPTY" << endl;
		}
		else if (front == rear)
		{
			front = rear = -1;
		}
		else if (rear == 0)
		{
			rear = size - 1;
		}
		else
		{
			rear--;
		}
	}
};