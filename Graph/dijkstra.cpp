#include<iostream>
using namespace std;
#define INF 10000
/*struct node
{
	int x;
	int y;
	int distance;
	bool visited;
};*/
struct node
{
	node* prev;
	int distance;
	int x;
	int y;
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
	void enqueue(int d, int x, int y)
	{
		node* temp = new node;
		temp->distance = d;
		temp->x = x;
		temp->y = y;
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
		int tempData = front->distance;
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
			cout << temp->distance << " " << temp->x << " " << temp->y << endl;
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
class Graph
{
private:
	int nodes;
	int** grid;
public:
	Graph()
	{
		nodes = 5;
		grid = new int* [nodes];
		for (int i = 0; i < nodes; i++)
		{
			grid[i] = new int[nodes];
		}
	}
	Graph(int s)
	{
		nodes = s;
		grid = new int* [nodes];
		for (int i = 0; i < nodes; i++)
		{
			grid[i] = new int[nodes];
		}
	}
	int getNodes()
	{
		return nodes;
	}
	int** getGrid()
	{
		return grid;
	}
	void fillGrid()
	{
		for (int i = 0; i < nodes; i++)
		{
			for (int j = 0; j < nodes; j++)
			{
				grid[i][j] = 1;
			}
		}
	}
	void printGrid()
	{
		for (int i = 0; i < nodes; i++)
		{
			cout << "Row: " << i << endl;
			for (int j = 0; j < nodes; j++)
			{
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	void insertEdge(int source, int destination, int weight)
	{
		grid[source][destination] = weight;
		//optional
		grid[destination][source] = weight;		//since undirected graph edge is bi directional
	}
	void printEdges()
	{
		for (int i = 0; i < nodes; i++)
		{
			for (int j = 0; j < nodes; j++)
			{
				if (grid[i][j] != 0)
					cout << i << " -> " << j << " = " << grid[i][j] << endl;
			}
		}
	}
};
bool isValid(int i, int size)
{
	if (i >= 0 && i < size)
		return true;
	else
		return false;
}
void dijkstra(Graph g, int sourceX, int sourceY, int destinationX, int destinationY)
{
	//i can use two priority queues one for keeping distances one for keeping pointers to that distance
	//a priority queue with 3 items can be used and only the first item that is distance should be compared for sorting it
	int vertices = g.getNodes();
	int** grid = g.getGrid();
	pqueue pq;
	int** distances = new int* [vertices];		//implement with priority queue to save time
	for (int i = 0; i < vertices; i++)
	{
		distances[i] = new int[vertices];
	}
	//for storing distances of source nodes to others
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
				distances[i][j] = 10000;
		}
	}
	distances[sourceX][sourceY] = 0;
	bool** visited = new bool* [vertices];
	for (int i = 0; i < vertices; i++)
	{
		visited[i] = new bool[vertices];
	}
	//for storing nodes that have been visisted
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
				visited[i][j] = false;
		}
	}
	visited[sourceX][sourceY] = true;
	int** prev = new int* [vertices];
	for (int i = 0; i < vertices; i++)
	{
		prev[i] = new int[vertices];
	}
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			prev[i][j] = -1;
		}
	}
	int i = 0;
	int j = 0;
	pq.enqueue(0, sourceX, sourceY);
	while (!(pq.isEmpty()))
	{
		int min1 = 0, min2 = 0;
		/*if (i == destinationX && j == destinationY)
			break;*/
		node* current = NULL;
		current = pq.getFront();
		i = current->x;
		j = current->y;
		pq.dequeue();
		if (i == destinationX && j == destinationY)
			break;
		//cout << distances[i + 1][j];
		if (isValid(i - 1, vertices) && (!visited[i - 1][j]) && (distances[i - 1][j] > distances[i][j] + 1))
		{
			//cout << i << " " << j << endl;
			//cout << i << " A" << j << endl;
			distances[i - 1][j] = distances[i][j] + 1;
			prev[i - 1][j] = (i * 10) + j;
			pq.enqueue(distances[i - 1][j], i - 1, j);
			//cout << distances[i ][j] << endl;
		}
		if (isValid(i + 1, vertices) && (!visited[i + 1][j]) && (distances[i + 1][j] > distances[i][j] + 1))
		{
			//cout << i << " " << j << endl;
			//cout << i +1<< " " << j << " " << distances[i][j] << endl;
			//cout << i << " B" << j << endl;
			distances[i + 1][j] = distances[i][j] + 1;
			prev[i + 1][j] = (i * 10) + j;
			pq.enqueue(distances[i + 1][j], i + 1, j);
			//cout << distances[i][j] << endl;

		}
		if (isValid(j - 1, vertices) && (!visited[i][j - 1]) && (distances[i][j - 1] > distances[i][j] + 1))
		{
			//cout << i << " " << j  << endl;
			//cout << i << " " << j - 1<< " " << distances[i][j] << endl;
			//cout << i << " C" << j << endl;
			distances[i][j - 1] = distances[i][j] + 1;
			prev[i][j-1] = (i * 10) + j;
			pq.enqueue(distances[i][j - 1], i, j - 1);
			//cout << distances[i][j] << endl;
		}
		if (isValid(j + 1, vertices) && (!visited[i][j + 1]) && (distances[i][j + 1] > distances[i][j] + 1))
		{
			//cout << i << " " << j << endl;
			//cout << i << " " << j +1<< " " << distances[i][j] << endl;
			//cout << i << " D" << j << endl;
			distances[i][j + 1] = distances[i][j] + 1;
			prev[i][j+1] = (i * 10) + j;
			pq.enqueue(distances[i][j + 1], i, j + 1);
			//cout << distances[i][j] << endl;
		}
		//pq.display();
		//cout << i << " " << j << " " << distances[i][j] << endl;
		visited[i][j] = true;
		//cout << i << " " << j << endl;
		//pq.display();
		//cout << "DONE" << endl;
	}
	i = 0, j = 0;
	int u = (destinationX * 10) + destinationY;
	while (u != -1)
	{
		cout << u << endl;
		int num1 = u % 10;
		int num2 = u / 10;
		u = prev[num2][num1];
	}

}
int main()
{
	Graph g1(10);
	g1.fillGrid();
	//g1.printGrid();
	/*g1.insertEdge(0, 1, 10);
	g1.insertEdge(0, 4, 20);
	g1.insertEdge(1, 2, 30);
	g1.insertEdge(1, 3, 40);
	g1.insertEdge(1, 4, 50);
	g1.insertEdge(2, 3, 60);
	g1.insertEdge(3, 4, 70);
	g1.printEdges();*/
	dijkstra(g1, 5, 8, 5, 9);
}