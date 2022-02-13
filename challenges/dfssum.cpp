#include<iostream>
using namespace std;
#define INF 10000
class Queue
{
private:
	int* queue;
	int queueSize;;
	int front;
	int rear;
public:
	Queue(int s)
	{
		queue = new int[s];
		queueSize = s;
		front = rear = -1;
	}
	void enqueue(int x)
	{
		if (rear == queueSize - 1)
		{
			cout << "Queue Overflow!\n" << endl;
			return;
		}
		if (front == -1)
			front++;
		rear++;
		queue[rear] = x;
	}
	int dequeue()
	{
		if (front == -1 || front > rear)
		{
			cout << "Queue Underflow!\n" << endl;
			return -1;
		}
		int temp = queue[front];
		if (front == rear)
		{
			front = rear = -1;
			return temp;
		}
		//cout << queue[front] << " is deleted!" << endl;
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
class Graph
{
private:
	int vertices;
	int** grid;
	bool* visited;
public:
	Graph()
	{
		vertices = 5;
		grid = new int* [vertices];
		for (int i = 0; i < vertices; i++)
		{
			grid[i] = new int[vertices];
		}
		visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
	}
	Graph(int v)
	{
		vertices = v;
		grid = new int* [vertices];
		for (int i = 0; i < vertices; i++)
		{
			grid[i] = new int[vertices];
		}
		visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
	}
	void fillGrid()
	{
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				grid[i][j] = 0;
			}
		}
	}
	void printGrid()
	{
		for (int i = 0; i < vertices; i++)
		{
			cout << "Row: " << i << endl;
			for (int j = 0; j < vertices; j++)
			{
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	void insertEdge(int source, int destination, int weight)
	{
		grid[source][destination] = weight;
		grid[destination][source] = weight;		//since undirected graph edge is bi directional
	}
	void printEdges()
	{
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				if (grid[i][j] != 0)
					cout << i << " -> " << j << " = " << grid[i][j] << endl;
			}
		}
	}
	void BFS(int source)
	{
		//resetting visited array
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		int current;
		Queue q(vertices * vertices);
		q.enqueue(source);
		visited[source] = true;
		while (!(q.isEmpty()))
		{
			current = q.dequeue();
			cout << current << " ";
			for (int i = 0; i < vertices; i++)		//checking edges from current node to other nodes
			{
				if (grid[current][i] != 0 && (!(visited[i])))
				{
					q.enqueue(i);
					visited[i] = true;
				}
			}
		}
		cout << endl;
		//resetting visited array
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
	}
	void DFS(int source)
	{
		cout << source << " ";
		visited[source] = true;
		for (int i = 0; i < vertices; i++)
		{
			if (grid[source][i] != 0 && (!(visited[i])))
			{
				DFS(i);
			}
		}
	}
	int removeMinEdge(int source, int maxSum, int cSum)
	{
		//cout << source << " ";
		//visited[source] = true;
		for (int i = 0; i < vertices; i++)
		{
			if (grid[source][i] != 0 && (!(visited[i])))
			{
				cSum += grid[source][i];
				int tempSum = removeMinEdge(i,maxSum,cSum);
				if (tempSum > maxSum)
					maxSum = tempSum;
				if (cSum > maxSum)
					maxSum = cSum;
				cSum -= grid[source][i];
			}
		}
		//cout << "A" << endl;
		return maxSum;
	}
};

int main()
{
	Graph g1(7);
	g1.fillGrid();
	g1.insertEdge(0, 1, 6);
	g1.insertEdge(0, 2, 5);
	g1.insertEdge(0, 3, 10);
	g1.insertEdge(2, 4, 4);
	g1.insertEdge(2, 5, 6);
	g1.insertEdge(3, 6, 8);
	//g1.insertEdge(4, 6, 30);
	cout << g1.removeMinEdge(0, 0, 0);
	//g1.printGrid();
	/*g1.insertEdge(0, 1, 10);
	g1.insertEdge(0, 4, 20);
	g1.insertEdge(1, 2, 30);
	g1.insertEdge(1, 3, 40);
	g1.insertEdge(3, 4, 70);
	g1.BFS(0);*/

	/*g1.insertEdge(0, 1, 19);
	g1.insertEdge(0, 2, 20);
	g1.insertEdge(2, 1, 30);
	g1.insertEdge(3, 1, 40);
	g1.insertEdge(1, 4, 50);
	g1.DFS(0);*/

	/*g1.insertEdge(0, 1, 1);
	g1.insertEdge(0, 2, 1);
	g1.insertEdge(1, 2, 1);
	g1.insertEdge(2, 3, 1);
	g1.insertEdge(3, 3, 1);
	g1.DFS(1);*/
/*
	g1.insertEdge(0, 1, 5);
	g1.insertEdge(1, 4, 9);
	g1.insertEdge(0, 2, 6);
	g1.insertEdge(2, 3, 4);
	g1.insertEdge(2, 1, 1);
	g1.insertEdge(2, 4, 10);
	g1.insertEdge(3, 4, 7);
	g1.prims(0);*/
}