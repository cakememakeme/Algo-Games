#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// https://www.hackerrank.com/challenges/counting-valleys/
 /*
  * Complete the 'countingValleys' function below.
  *
  * The function is expected to return an INTEGER.
  * The function accepts following parameters:
  *  1. INTEGER steps
  *  2. STRING path
  */

int countingValleys(int steps, string path) {
    int curLevel = 0;
    int result = 0;
    const int pathSize = path.size();

    for(int i = 0; i < pathSize; i++)
    {
        switch(path[i])
        {
        case 'U' :
            if(curLevel == -1)
            {
                result++;
            }
            curLevel++;
            break;
        case 'D' :
            curLevel--;
            break;
        }

        if (i >= steps)
            break;
    }

    return result;
}

int main()
{
    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

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
