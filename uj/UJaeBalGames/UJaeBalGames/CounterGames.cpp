#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <set>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

//https://www.hackerrank.com/challenges/counter-game/problem
/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

string counterGame(unsigned long long n) {
    constexpr unsigned long long MAX_POWER_OF_2 = static_cast<unsigned long long>(1) << 63;

    string players[2];
    players[0] = "Richard";
    players[1] = "Louise";

    int turnCount = 0;

    unsigned long remainN = n;

    while (remainN != 1)
    {
        bool isPowerOf2 = false;
        unsigned long long nearestPowerOf2 = MAX_POWER_OF_2;

        for (int i = 63; i > -1; i--)
        {
            const unsigned long long powerOf2 = static_cast<unsigned long long>(1) << i;
            if ((remainN ^ powerOf2) == 0)
            {
                isPowerOf2 = true;
                break;
            }

            if (nearestPowerOf2 > remainN && remainN > powerOf2)
            {
                nearestPowerOf2 = powerOf2;
                break;
            }
        }

        if (isPowerOf2)
            remainN = remainN >> 1;
        else
            remainN -= nearestPowerOf2;

        turnCount++;
    }

    return players[turnCount % 2];
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

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
