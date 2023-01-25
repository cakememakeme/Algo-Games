#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/150365?language=cpp

int direction[4][2] = { {0, 1}, {-1, 0}, {1, 0}, {0, -1} };
char dirChar[4] = { 'd','l','r','u' };
int sizeX = 0;
int sizeY = 0;
int curStep = 0;
int maxStep = 0;
int endX = 0;
int endY = 0;

//dfs 이거 테케 31번에서 시간초과남
bool makeRoad(int x, int y, string& answer)
{
    if (curStep == maxStep)
    {
        if (x == endX && y == endY)
            return true;

        return false;
    }

    if (maxStep - curStep < abs(endX - x) + abs(endY - y))
        return false;

	for(int i = 0; i < 4; i++)
	{
        const int nextX = direction[i][0] + x;
        const int nextY = direction[i][1] + y;
		if(nextX < 0 || nextX >= sizeX
            || nextY < 0 || nextY >= sizeY)
            continue;

        answer += dirChar[i];
        curStep++;
        
        if (makeRoad(nextX, nextY, answer) == true)
            return true;

        answer.pop_back();
        curStep--;
	}

    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";

    sizeX = m;
    sizeY = n;
    int startX = y - 1;
    int startY = x - 1;
    endY = r - 1;
    endX = c - 1;
    maxStep = k;

    //d l r u

    if (endY > startY)
    {
        while(abs(startX - endX) + abs(startY - endY) < maxStep - curStep && startY < sizeY - 1)
        {
            startY++;
            answer += 'd';
            curStep++;
        }
    }

    if (endX < startX)
    {
        while (abs(startX - endX) + abs(startY - endY) < maxStep - curStep && startX > 0)
        {
            startX--;
            answer += 'l';
            curStep++;
        }
    }

    if(makeRoad(startX, startY, answer))
    {
        return answer;
    }

    return "impossible";
}

//다른 답지보고 배껴서 풀어본것
//string solution(int n, int m, int x, int y, int r, int c, int k) {
//    string answer = "";
//
//    sizeX = m;
//    sizeY = n;
//    int startX = y - 1;
//    int startY = x - 1;
//    endY = r - 1;
//    endX = c - 1;
//    maxStep = k;
//    curStep = maxStep - (abs(startX - endX) + abs(startY - endY));
//
//    k -= (abs(startX - endX) + abs(startY - endY));
//
//    if (k < 0 || k % 2 != 0)
//        return "impossible";
//
//    //d l r u
//    int remainDistance[4] = {0,};
//
//    if (startX > endX)
//        remainDistance[1] = startX - endX;
//    else
//        remainDistance[2] = endX - startX;
//    if (startY > endY)
//        remainDistance[3] = startY - endY;
//    else
//        remainDistance[0] = endY - startY;
//
//	answer.append(remainDistance[0], 'd');
//    int d = min(k / 2, n - (x + remainDistance[0]));
//    answer.append(d, 'd');
//    remainDistance[3] += d;
//    k -= 2 * d;
//
//    answer.append(remainDistance[1], 'l');
//    int l = min(k / 2, y - remainDistance[1] - 1);
//    answer.append(l, 'l');
//    remainDistance[2] += l;
//    k -= 2 * l;
//
//    int asd = k / 2;
//    for(int i = 0; i < asd; i++)
//    {
//        answer += "rl";
//    }
//    answer.append(remainDistance[2], 'r');
//    answer.append(remainDistance[3], 'u');
//
//    return answer;
//
//}

void main()
{
    cout << solution(2, 2, 1, 1, 2, 2, 2);
}