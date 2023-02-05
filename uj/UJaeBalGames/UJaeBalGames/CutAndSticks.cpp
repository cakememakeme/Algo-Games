#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <list>
#include <queue>
#include <set>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

//https://www.hackerrank.com/challenges/cut-the-sticks/problem
/*
 * Complete the 'cutTheSticks' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> cutTheSticks(vector<int> arr) {

    vector<int> result;

    list<int> remainSticks;

    int sticksSize = arr.size();
    int smallestStickLength = 1000;

    for(int i = 0; i < sticksSize; i++)
    {
        remainSticks.push_back(arr[i]);

        if (arr[i] < smallestStickLength)
            smallestStickLength = arr[i];
    }
    
    while(remainSticks.size() > 0)
    {
        result.push_back(remainSticks.size());

        int nextSmallestLength = 1000;

        for(list<int>::iterator it = remainSticks.begin(); it != remainSticks.end();)
        {
            const int remainStick = *it - smallestStickLength;

            if (remainStick == 0)
                it = remainSticks.erase(it);
            else
            {
                *it = remainStick;

                if (remainStick < nextSmallestLength)
                    nextSmallestLength = remainStick;

                ++it;
            }
        }

        smallestStickLength = nextSmallestLength;
    }

    return result;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
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
