#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

//https://www.hackerrank.com/challenges/utopian-tree/problem
/*
 * Complete the 'utopianTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int cachedUtopianTree[61] = { 1, 0, };
int cachedUtopianTreeMaxIndex = 0;

int utopianTree(int n) {
    if (n > 60)
        return 0;
    
    int result = cachedUtopianTree[min(n, cachedUtopianTreeMaxIndex)];

    for(int i = cachedUtopianTreeMaxIndex + 1; i <= n; i++)
    {
        result += (i % 2 == 1) ? result : 1;
        cachedUtopianTree[i] = result;
    }

    cachedUtopianTreeMaxIndex = max(cachedUtopianTreeMaxIndex, n);

    return result;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = utopianTree(n);

        cout << result << "\n";
    }

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
