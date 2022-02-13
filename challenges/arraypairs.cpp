//https://www.hackerrank.com/challenges/array-pairs/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
long getMax(vector<int> arr, long unsigned int i, long unsigned int j)
{
    long max = arr.at(i);
    for (long unsigned int counter = i;counter <= j;counter++)
    {
        if (arr.at(counter) > max)
        {
            max = arr.at(counter);
        }
    }
    return max;
}
long solve(vector<int> arr) {
    
    //long pairs[10000000];
    long total = 0;
    long index = 0;
    long num1, num2;

    for (long unsigned int i = 0;i < (arr.size());i++)
    {
        for (long unsigned int j = i;j < arr.size();j++)
        {
            num1 = arr.at(i);
            num2 = arr.at(j);
            if ((i < j) && ((num1 * num2) <= getMax(arr, i, j)))
            {
                //cout << (i + 1) << ' ' << (j + 1) << endl;
                /*pairs[index] = i + 1;
                index++;
                pairs[index] = j + 1;
                index++;*/
                total++;    
            }
        }
    }
    //return (index / 2);
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    long result = solve(arr);

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
