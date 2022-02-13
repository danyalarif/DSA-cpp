

#include<iostream>

using namespace std;
#define INF 10000
struct Edge
{
	int source;
	int destination;
	int weight;
};
class MinHeap
{
private:
	Edge* heap;
	int nodes;
	int last;
public:
	MinHeap()
	{
		nodes = 5;
		heap = new Edge[nodes];
		last = -1;
	}
	MinHeap(int size)
	{
		nodes = size;
		heap = new Edge[nodes];
		last = -1;
	}
	void swap(int index1, int index2)
	{
		Edge temp;
		temp.source = heap[index1].source;
		temp.destination = heap[index1].destination;
		temp.weight = heap[index1].weight;
		heap[index1].source = heap[index2].source;
		heap[index1].destination = heap[index2].destination;
		heap[index1].weight = heap[index2].weight;
		heap[index2].source = temp.source;
		heap[index2].destination = temp.destination;
		heap[index2].weight = temp.weight;
	}
	void insert(int source, int destination, int weight)
	{
		Edge temp;
		temp.source = source;
		temp.destination = destination;
		temp.weight = weight;
		if (last == -1)
		{
			last++;
			heap[last] = temp;
		}
		else if (last == nodes - 1)
		{
			cout << "No space" << endl;
		}
		else
		{
			last++;
			heap[last] = temp;
			int key = last;
			int parent = (key - 1) / 2;
			while (parent >= 0 && heap[key].weight < heap[parent].weight)
			{
				swap(parent, key);
				key = parent;
				parent = (key - 1) / 2;
			}
		}
	}
	void printTop()
	{
		cout << heap[0].source << " " << heap[0].destination << " " << heap[0].weight << endl;
	}
	bool isEmpty()
	{
		if (last == -1)
			return true;
		else
			return false;
	}
	int getMin(int a, int b)
	{
		if (heap[a].weight < heap[b].weight)
			return a;
		else
			return b;
	}
	Edge getTop()
	{
		return heap[0];
	}
	void deleteMin()
	{
		heap[0] = heap[last];
		last--;
		int current = 0;
		int leftChild = (2 * current) + 1;		//index of left child
		int rightChild = (2 * current) + 2;		//index of right child
		int minChild = getMin(leftChild, rightChild);		//index of Min child 
		while (current < last && heap[minChild].weight < heap[current].weight)
		{
			swap(current, minChild);
			current = minChild;		//updating the current; Current moves to the position of the node that was swapped
			leftChild = (2 * current) + 1;
			rightChild = (2 * current) + 2;
			if (leftChild < last && rightChild < last)
			{
				minChild = getMin(leftChild, rightChild);
			}
			else if (leftChild < last)
			{
				minChild = leftChild;
			}
			else if (rightChild < last)
			{
				minChild = rightChild;
			}
			else
			{
				break;		//if no children exist
			}
		}
	}
	bool exists(int source, int destination, int weight)
	{
		for (int i = 0; i < nodes; i++)
		{
			if (heap[i].source == source && heap[i].destination == destination && heap[i].weight == weight)		//since undirected edges need to check both cases
				return true;
			else if (heap[i].source == destination && heap[i].destination == source && heap[i].weight == weight)
				return true;
		}
		return false;
	}
};

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
		//optional
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
	int getEdges()
	{
		int count = 0;
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				if (grid[i][j] != 0)
				{
					count++;
				}
			}
		}
		return count / 2;
	}
	int getMinVertex(int distances[])
	{
		int min = INF, index = 0;
		for (int i = 0; i < vertices; i++)
		{
			if ((!visited[i]) && distances[i] < min)
			{
				min = distances[i];
				index = i;
			}
		}
		return index;
	}
	void prims(int source)
	{
		//resetting visited array
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		int temp = 0;
		int* distances = new int[vertices];
		int* parents = new int[vertices];
		for (int i = 0; i < vertices; i++)
		{
			distances[i] = INF;
			parents[i] = -1;
		}
		distances[source] = 0;
		visited[source] = true;
		for (int i = 0; i < vertices; i++)
		{
			int current = getMinVertex(distances);
			visited[current] = true;
			for (int j = 0; j < vertices; j++)
			{
				if (grid[current][j] != 0 && (!(visited[j])) && grid[current][j] < distances[j])
				{
				
					distances[j] = grid[current][j];
					parents[j] = current;
				}
			}
		}
		for (int i = 0; i < vertices; i++)
		{
			if (i != source)
				cout << parents[i] << " -> " << i << " = " << grid[i][parents[i]] << endl;
		}
		/*int v = temp;
		/*while (parents[v] != -1)
		{
			cout << parents[v] << " <- " << v << " = " << grid[v][parents[v]] << endl;
			v = parents[v];
		}
		printMST(parents, v);*/
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}


	}
	/*void printMST(int parents[], int v)
	{
		if (parents[v] == -1)
			return;
		printMST(parents, parents[v]);
		cout << parents[v] << " -> " << v << " = " << grid[v][parents[v]] << endl;
	}*/
	bool checkCycle(int** graph, int current, int parent)
	{
		visited[current] = true;
		for (int i = 0; i < vertices; i++)
		{
			if (graph[current][i] != 0)
			{
				if ((!(visited[i])))
				{
					bool res = checkCycle(graph, i, current);
					if (res)
						return true;
				}
				else if (i != parent)		//if a back edge exists
				{
					return true;
				}
			}
		}
		return false;
	}
	bool isCyclic(int** graph)
	{
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < vertices; i++)
		{
			if ((!visited[i]))
			{
				bool res = checkCycle(graph, i, -1);
				if (res)
					return true;
			}
		}
		return false;
	}
	void kruskal()
	{
		MinHeap h(getEdges());
		int** tempGraph = new int*[vertices];
		for (int i = 0; i < vertices; i++)
		{
			tempGraph[i] = new int[vertices];
		}
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				tempGraph[i][j] = 0;
			}
		}
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				if (grid[i][j] != 0)
				{
					if (!(h.exists(i, j, grid[i][j])))
					{
						h.insert(i, j, grid[i][j]);
					}
				}
			}
		}
		//int* MST = new int[vertices];
		/*while (!(h.isEmpty()))
		{
			h.printTop();
			h.deleteMin();
		}*/
		int count = 0;
		while (count < vertices - 1)
		{
			Edge current = h.getTop();
			h.deleteMin();
			tempGraph[current.source][current.destination] = current.weight;
			tempGraph[current.destination][current.source] = current.weight;
			bool res = isCyclic(tempGraph);
			if (res)
			{
				tempGraph[current.source][current.destination] = 0;
				tempGraph[current.destination][current.source] = 0;
			}
			else
			{
				count++;
			}
		}
		/*for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				if (tempGraph[i][j] != 0)
				{
					cout << i << " -> " << j << " " << grid[i][j] << endl;
				}
			}
		}*/
		MinHeap h2(vertices - 1);
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				if (tempGraph[i][j] != 0)
				{
					if (!(h2.exists(i, j, tempGraph[i][j])))
						h2.insert(i, j, tempGraph[i][j]);
				}
			}
		}
		while (!(h2.isEmpty()))
		{
			Edge temp = h2.getTop();
			cout << temp.source << " -> " << temp.destination << " = " << temp.weight << endl;
			h2.deleteMin();
		}
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
	}
};

int main()
{
	Graph g1(5);
	g1.fillGrid();
	//g1.printGrid();
	/*g1.insertEdge(0, 1, 10);
	g1.insertEdge(0, 4, 20);
	g1.insertEdge(1, 2, 30);
	g1.insertEdge(1, 3, 40);
	g1.insertEdge(3, 4, 70);
	g1.BFS(0);*/

	/*g1.insertEdge(0, 2, 10);
	g1.insertEdge(0, 3, 20);
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

	/*g1.insertEdge(0, 1, 5);
	g1.insertEdge(1, 4, 9);
	g1.insertEdge(0, 2, 6);
	g1.insertEdge(2, 3, 4);
	g1.insertEdge(2, 1, 1);
	g1.insertEdge(2, 4, 10);
	g1.insertEdge(3, 4, 7);
	g1.prims(0);*/
	g1.insertEdge(0, 1, 6);
	g1.insertEdge(0, 2, 7);
	g1.insertEdge(1, 2, 15);
	g1.insertEdge(1, 3, 2);
	g1.insertEdge(1, 4, 12);
	g1.insertEdge(2, 3, 4);
	g1.insertEdge(3, 4, 9);
	g1.insertEdge(0, 1, 6);
	g1.kruskal();
}