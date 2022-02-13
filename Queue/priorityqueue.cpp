class PQueue
{
	int* queue;
	int queueSize;
	int front;
	int rear;
public:
	PQueue(int s)
	{
		queue = new int[s];
		front = rear = -1;
	}
	void enqueue(int x)
	{
		if (front == -1 && rear == -1)
		{
			rear = front = 0;
			queue[rear] = x;
		}
		else if (front == rear)		//if only one element in queue
		{
			if (x > queue[front])			//insert element after front
			{
				rear++;
				queue[rear] = x;
			}
			else
			{					//inserting element before front
				rear++;
				queue[rear] = queue[front];
				queue[front] = x;
			}
		}
		else
		{
			if (x > queue[rear])		//inserting at end of queue
			{
				rear++;
				queue[rear] = x;
				return;
			}
			int temp2 = rear;
			while (temp2 >= 0 && queue[temp2] > x)
			{
				queue[temp2 + 1] = queue[temp2];
				temp2--;
			}
			queue[temp2 + 1] = x;
			rear++;
		}
	}
	int dequeue()
	{
		if (front == -1 || front > rear)
		{
			cout << "Queue Underflow!\n" << endl;
			return -1;
		}
		int temp = queue[front];
		front++;
		return temp;
	}
	void qdisplay()
	{
		if (front == -1 || front > rear)
		{
			cout << "Queue is Empty!\n" << endl;
			return;
		}
		for (int i = front; i <= rear; i++)
		{
			cout << queue[i] << " ";
		}
		cout << endl;
	}
	bool isEmpty()
	{
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}
};