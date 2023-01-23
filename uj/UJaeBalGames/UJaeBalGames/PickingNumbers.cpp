#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

//https://www.hackerrank.com/challenges/picking-numbers/problem
/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    constexpr int MAX_A_NUM = 100;

    bool isChecked[MAX_A_NUM] = { false, };
    const int aSize = a.size();
    int result = 0;
    for(int i = 0; i < aSize; i++)
    {
        const int startNum = a[i];
	    if(isChecked[startNum] == true)
	    {
		    continue;
	    }

        int lowerLength = 1;
        int higherLength = 1;

        for(int j = i + 1; j < aSize; j++)
        {
            const int gap = startNum - a[j];
	        if(gap == 0)
	        {
                lowerLength++;
                higherLength++;
	        }
            else if(gap == -1)
            {
                lowerLength++;
            }
            else if(gap == 1)
            {
                higherLength++;
            }
        }

        result = max(result, higherLength);
        result = max(result, lowerLength);
    }

    return result;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    cout << result << "\n";

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
