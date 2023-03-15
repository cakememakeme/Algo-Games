#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/161989

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    const int sectionSize = section.size();

    for(int i = 0; i < sectionSize; i++)
    {
        const int startRollingPos = section[i];

        while(i + 1 < sectionSize && startRollingPos + m - 1 >= section[i + 1])
        {
            i++;
        }

        answer++;
    }

    return answer;
}

void main()
{
    const int n = 8;
    const int m = 4;
    const vector<int> selection{ 2, 3, 6 };
    cout << solution(n, m, selection);
}