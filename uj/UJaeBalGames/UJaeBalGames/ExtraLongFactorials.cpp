#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <set>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

//https://www.hackerrank.com/challenges/extra-long-factorials/problem
/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

string multiplyInt(const string& leftStr, const string& rightStr)
{
    string result;

    const int leftSize = leftStr.size();
    const int rightSize = rightStr.size();

    for(int i = 0; i < rightSize; i++)
    {
	    for(int j = 0; j < leftSize; j++)
	    {
            const int r = (rightStr[i] - '0') * pow(10, i);
            const int l = (leftStr[j] - '0');

            int rl = r * l;

            if(result.size() <= j)
            {
                result.push_back('0');
            }

            const int resultInt_J = result[j] - '0' + rl;
            int nextDigitPlusNum = resultInt_J / 10;
            //result[j] += (rl % 10);

            if (result[j] - '0' >= 10)
            {
                nextDigitPlusNum++;
            }

            result[j] = (resultInt_J % 10) + '0';

            if(nextDigitPlusNum > 0)
            {
                for(int k = j; nextDigitPlusNum > 0; k++)
                {
	                if(k + 1 >= result.size())
	                {
                        result.push_back('0');
	                }

                    const int digitPlusResult = result[k + 1] - '0' + nextDigitPlusNum;
                	result[k + 1] = (digitPlusResult % 10) + '0';
                    nextDigitPlusNum = digitPlusResult / 10;
                    
                }
            }
	    }
    }

    reverse(result.begin(), result.end());

    return result;
}

void extraLongFactorials(int n) {
    string fin = to_string(1);

    for(int i = 1; i <= n; i++)
    {
        string right = to_string(i);
        
        reverse(fin.begin(), fin.end());
        reverse(right.begin(), right.end());

        fin = multiplyInt(fin, right);
    }

    cout << fin << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
