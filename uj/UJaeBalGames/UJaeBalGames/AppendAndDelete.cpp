#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    bool isSuccess = true;

    int sameStrSize = 0;

    const int sSize = s.size();
    const int tSize = t.size();

    for (int i = 0; i < sSize && i < tSize; i++)
    {
        if (s[i] != t[i])
            break;

        sameStrSize++;
    }

    const int needDeleteStrSize = sSize - sameStrSize;
    const int needAddStrSize = tSize - sameStrSize;

    if (sameStrSize == 0)
    {
        isSuccess = (k >= tSize + sSize);
    }
    else
    {
        const int remainK = k - needAddStrSize - needDeleteStrSize;
        if (remainK < 0)
            isSuccess = false;
        else
        {
            if (remainK % 2 == 0)
            {
                isSuccess = true;
            }
            else
            {
                isSuccess = (k >= tSize + sSize);
            }
        }
    }

    return isSuccess ? string("Yes") : string("No");
}

int main()
{
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

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
