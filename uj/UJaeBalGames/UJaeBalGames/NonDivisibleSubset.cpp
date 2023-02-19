#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

//https://www.hackerrank.com/challenges/non-divisible-subset/problem
/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int _k = 1;

vector<vector<bool>> IsSatisfiedSum;

bool isSubSetSatisfied(const vector<int>& subSet)
{
    const int subSetSize = subSet.size();

    for(int i = 0; i < subSetSize - 1; i++)
    {
	    for(int j = i + 1; j < subSetSize; j++)
	    {
            if(IsSatisfiedSum[subSet[i]][subSet[j]] == false)
            {
                return false;
            }
	    }
    }

    return true;
}

bool makeArray(const int targetArrLength, const int startIdx, vector<int>& targetArr, const vector<int>& originArr)
{
    const int originArrSize = originArr.size();
	for(int i = startIdx; i < originArrSize; i++)
	{
        targetArr.push_back(i);

        if(targetArr.size() == targetArrLength)
        {
            if (isSubSetSatisfied(targetArr))
            {
                return true;
            }
        }
        else
        {
            if (isSubSetSatisfied(targetArr))
            {
                makeArray(targetArrLength, i + 1, targetArr, originArr);
            }
        }

        targetArr.pop_back();
	}

    return false;
}

int nonDivisibleSubset(int k, vector<int> s) {
    /*_k = k;

    const int sSize = s.size();

    for(int i = 0; i < sSize; i++)
    {
        vector<bool> satisfied;

	    for(int j = 0; j < sSize; j++)
	    {
            if (j <= i)
                satisfied.push_back(false);
            else
                satisfied.push_back(((s[i] + s[j]) % k) != 0);
	    }

        IsSatisfiedSum.push_back(satisfied);
    }

    for(int i = s.size(); i > 0; i--)
    {
        vector<int> arr;

        if (makeArray(i, 0, arr, s) == true)
            return i;
    }*/
    if (k == 1)
        return 1;

    vector<int> kRemain;

    kRemain.resize(k, 0);

    const int sSize = s.size();

    for(int i = 0; i < sSize; i++)
    {
        kRemain[s[i] % k]++;
    }

    int answer = min(kRemain[0], 1);

    const int halfK = k / 2;
    
    answer += (k % 2 != 0 ? max(kRemain[halfK], kRemain[halfK + 1]) : min(kRemain[halfK], 1));

    for (int i = 1; i < halfK; i++)
    {
        answer += max(kRemain[i], kRemain[k - i]);
    }

    return answer;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

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