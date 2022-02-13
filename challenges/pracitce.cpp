
#include <iostream>

using namespace std;

bool allVisited(bool* visited, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!(visited[i]))
			return false;
	}
	return true;
}
void replaceString(string text)
{
	string str = "";
	int current = 0;
	char* letters = new char[text.length()];
	bool* visited = new bool[text.length()];
	for (int i = 0; i < text.length(); i++)
	{
		letters[i] = (char)text[i];
		visited[i] = (bool)false;
	}
//	while (true)
	//{
		int prev = -1;
		//if (allVisited(visited, text.length()))
			//break;
		int i = 0;
		//cout << "A";
		while (i < text.length())
		{
			if (!(visited[i]))
			{
				if (i == 0)
				{
					str += letters[i];
					visited[i] = true;
				}
				else
				{
					if (str[str.length() - 1] != letters[i])
					{
						str += letters[i];
						visited[i] = true;
						if (prev != -1)
							i = prev - 1;
					}
					else
					{
						/*if (i == text.length() - 1)
						{
							cout << "Not Possible" << endl;
							return;
						}*/
						if (prev == -1)
							prev = i;
					}
				}
			}
			i++;
			if (i == text.length() && str.length() != text.length())
			{
				cout << "Not Possible" << endl;
				return;
			}
		}
	//}
	cout << str << endl;
}

int main()
{
	string str = "mmooee";
	replaceString(str);
}