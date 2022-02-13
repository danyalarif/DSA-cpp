#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct node
{
    node* prev;
    double distance;
    int x;
    int y;
    node* next;
    node()
    {
        distance = 10000;
    }
};
class pqueue {
public:
    node* front = NULL;
    node* rear = NULL;
    void enqueue(double d, int x, int y)
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
        else if (front == rear)        //if only one element in queue
        {
            if (d >= front->distance)            //insert element after front
            {
                rear->next = temp;
                temp->prev = rear;
                rear = temp;
            }
            else
            {                    //inserting element before front
                temp->next = rear;
                rear->prev = temp;
                front = temp;
            }
        }
        else
        {
            if (d >= rear->distance)        //inserting at end of queue
            {
                rear->next = temp;
                temp->prev = rear;
                rear = temp;
                return;
            }
            node* temp2 = rear;
            while (temp2 != NULL && temp2->distance > d)
            {
                temp2 = temp2->prev;        //moving back till null is reached or a node with greater value is found
            }
            if (temp2 == NULL)            //inserting at start
            {
                temp->next = front;
                front->prev = temp;
                front = temp;
            }
            else
            {                                //inserting temp between temp2 and its next
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
    bool exists(int i, int j) {
        node* p = front;
        while (p != NULL) {
            if (p->x == i && p->y == j)
                return true;
            p = p->next;
        }
        return false;
    }
};
bool isValid(int i, int size)
{
    if (i >= 0 && i < size)
        return true;
    else
        return false;
}
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    bool** visited = new bool*[grid.size()];
    for (int i = 0;i < grid.size();i++)
    {
        visited[i] = new bool[grid.size()];
    }
    for (int i = 0;i < grid.size();i++)
    {
        for (int j = 0;j < grid.size();j++)
        {
            visited[i][j] = false;
        }
    }
    int total = grid.size();
    int count = 0;
    pqueue pq;
    pq.enqueue(0, startX, startY);
    visited[startX][startY] = true;
    while (!(pq.isEmpty()))
    {
        node* temp = pq.getFront();
        int x = temp->x;
        int y = temp->y;
        int currentX = x;
        int currentY = y;
        int d = temp->distance;
        pq.dequeue();
        int newd = d + 1;
        if (x == goalX && y == goalY)
        {
            return d;
        }
        //Left
        currentY = y - 1;
        while (isValid(currentY, total) && grid.at(currentX)[currentY] != 'X' && !(visited[currentX][currentY]))
        {
            pq.enqueue(newd, currentX, currentY);
            visited[currentX][currentY] = true;
            currentY = currentY - 1;
        }
        currentX = x;
        currentY = y;
        //Right
        currentY = y + 1;
        while (isValid(currentY, total) && grid.at(currentX)[currentY] != 'X' && !(visited[currentX][currentY]))
        {
            pq.enqueue(newd, currentX, currentY);
            visited[currentX][currentY] = true;
            currentY = currentY + 1;
        }
        currentX = x;
        currentY = y;
        //Top
        currentX = x - 1;
        while (isValid(currentX, total) && grid.at(currentX)[currentY] != 'X' && !(visited[currentX][currentY]))
        {
            pq.enqueue(newd, currentX, currentY);
            visited[currentX][currentY] = true;
            currentX = currentX - 1;
        }
        currentX = x;
        currentY = y;
        //Bottom
        currentX = x + 1;
        while (isValid(currentX, total) && grid.at(currentX)[currentY] != 'X' && !(visited[currentX][currentY]))
        {
            pq.enqueue(newd, currentX, currentY);
            visited[currentX][currentY] = true;
            currentX = currentX + 1;
        }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
