#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

void printArrFunc(const vector<int>& printArr)
{
	for (int i = 0; i < printArr.size(); i++)
	{
		cout << printArr[i] << " ";
	}

	cout << endl;
}

void makePrintArr(vector<int>& printArr, int startIndex)
{
	for (int i = startIndex; i < N + 1; i++)
	{
		printArr.push_back(i);
		if (printArr.size() == M)
		{
			printArrFunc(printArr);
			printArr.pop_back();
		}
		else
		{
			makePrintArr(printArr, i + 1);
			printArr.pop_back();
		}
	}
}

int main()
{
	cin >> N >> M;

	vector<int> printArr;
	makePrintArr(printArr, 1);

}