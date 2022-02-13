#include<iostream>

using namespace std;


#define INF 10000
struct node
{
	node* prev;
	double distance;
	int v;
	node* next;
	node()
	{
		distance = INF;
	}
};
class pqueue {
public:
	node* front = NULL;
	node* rear = NULL;
	void enqueue(double d, int v)
	{
		node* temp = new node;
		temp->distance = d;
		temp->v = v;
		temp->prev = NULL;
		temp->next = NULL;
		if (front == NULL && rear == NULL)
		{
			rear = front = temp;
		}
		else if (front == rear)		//if only one element in queue
		{
			if (d >= front->distance)			//insert element after front
			{
				rear->next = temp;
				temp->prev = rear;
				rear = temp;
			}
			else
			{					//inserting element before front
				temp->next = rear;
				rear->prev = temp;
				front = temp;
			}
		}
		else
		{
			if (d >= rear->distance)		//inserting at end of queue
			{
				rear->next = temp;
				temp->prev = rear;
				rear = temp;
				return;
			}
			node* temp2 = rear;
			while (temp2 != NULL && temp2->distance > d)
			{
				temp2 = temp2->prev;		//moving back till null is reached or a node with greater value is found
			}
			if (temp2 == NULL)			//inserting at start
			{
				temp->next = front;
				front->prev = temp;
				front = temp;
			}
			else
			{								//inserting temp between temp2 and its next
				temp2->next->prev = temp;
				temp->next = temp2->next;
				temp2->next = temp;
				temp->prev = temp2;
			}
		}
	}
	void dequeue()
	{
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is EMPTY!" << endl;
			return;
		}
		node* temp = front;
		if (front == rear)
		{
			front = rear = NULL;
			delete temp;
			temp = NULL;
		}
		else
		{
			front = front->next;
			front->prev = NULL;
			delete temp;
			temp = NULL;
		}
	}
	node* getFront()
	{
		return front;
	}
	void display()
	{
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is EMPTY!" << endl;
			return;
		}
		node* temp = NULL;
		temp = front;
		while (temp != NULL)
		{
			cout << temp->distance << " " << temp->v << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	bool isEmpty()
	{
		if (front == NULL)
			return true;
		else
			return false;
	}
};

int getMoves(int* graph, int V, int source, int destination)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	visited[source] = true;
	pqueue pq;
	pq.enqueue(source, 0);
	while (!(pq.isEmpty()))
	{
		node* current = pq.getFront();
		int v = current->v;
		int d = current->distance;
		pq.dequeue();
		if (v == destination)
			return d;
		visited[v] = true;
		for (int i = v + 1; i <= v + 6; i++)		//finding adjacent (next 6 vertices to current)
		{
			if ((visited[i]))
				continue;
			if (graph[i] == -1)
				pq.enqueue(d + 1, i);
			else
				pq.enqueue(d + 1, graph[i]);
		}
	}
}

int main()
{
	int V = 30;
	int* graph = new int[V];
	for (int i = 0; i < V; i++)
	{
		graph[i] = -1;
	}
	graph[1] = 29;
	graph[4] = 7;
	graph[10] = 25;
	graph[19] = 28;
	// Snakes
	graph[26] = 0;
	graph[20] = 8;
	graph[16] = 3;
	graph[18] = 6;
	cout << getMoves(graph, V,0,29);
}