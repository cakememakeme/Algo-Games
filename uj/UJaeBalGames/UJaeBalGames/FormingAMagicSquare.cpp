#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

//https://www.hackerrank.com/challenges/magic-square-forming/
/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

void rotateMatrix(int matrix[3][3])
{
    int tempMatrix[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tempMatrix[j][3 - 1 - i] = matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
}

int formingMagicSquare(vector<vector<int>> s) {
    constexpr int LINE_NUM = 3;
    constexpr int LINE_SUM = 15;

    int magic_square[3][3] = { {8, 3, 4,}, {1, 5, 9}, {6, 7, 2} };
    int magic_square2[3][3] = { {6,7,2} , {1,5,9}, {8,3,4,} };

    int result = INT_MAX;
    
    for(int rotIndex = 0; rotIndex < 4; rotIndex++)
    {
        int cost = 0;
        int cost2 = 0;

	    for(int i = 0; i < 3; i++)
	    {
		    for(int j = 0; j < 3; j++)
		    {
                cost += abs(magic_square[i][j] - s[i][j]);
                cost2 += abs(magic_square2[i][j] - s[i][j]);
		    }
	    }

        result = min(result, cost);
        result = min(result, cost2);

        rotateMatrix(magic_square);
        rotateMatrix(magic_square2);
    }

    return result;
}

int main()
{
    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
