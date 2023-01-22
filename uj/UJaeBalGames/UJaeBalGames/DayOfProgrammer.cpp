#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    constexpr int END_JULIAN_YEAR = 1918;
    constexpr int YEAR_DAY_COUNT[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    constexpr int DAY_OF_PROGRAMMER = 256;

    string result;
    int remainDayOfProgrammer = 256;
    int month = 1;
    bool isLeapYear;

    if (year <= END_JULIAN_YEAR)
        isLeapYear = (year % 4 == 0);
    else
        isLeapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

    for (int i = 0; i < 12; i++)
    {
        if (remainDayOfProgrammer < YEAR_DAY_COUNT[i])
        {
            month = i;
            break;
        }

        remainDayOfProgrammer -= YEAR_DAY_COUNT[i];

        if (i == 1 && isLeapYear)
            remainDayOfProgrammer -= 1;

        if (year == END_JULIAN_YEAR && i == 1)
            remainDayOfProgrammer += 13;
    }

    result = to_string(remainDayOfProgrammer) + "." + (month < 9 ? "0" : "") + to_string(month + 1) + "." + to_string(year);

    return result;
}

int main()
{
    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
