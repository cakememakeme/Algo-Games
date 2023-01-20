#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

void solve(std::vector<int>& vec)
{
	std::vector<int> ans;

	std::vector<int> uniqueVec = vec;
	std::sort(uniqueVec.begin(), uniqueVec.end());
	uniqueVec.erase(std::unique(uniqueVec.begin(), uniqueVec.end()), uniqueVec.end());

	std::priority_queue<int> pQ;
	std::unordered_map<int, int> uM;
	for (int i = 0; i < uniqueVec.size(); ++i)
	{
		pQ.push(uniqueVec[i]);
	}

	while (!pQ.empty())
	{
		uM[pQ.top()] = pQ.size();
		pQ.pop();
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << uM[vec[i]] - 1 << ' ';
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::vector<int> vec;

	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int input = 0;
		std::cin >> input;
		vec.push_back(input);
	}

	solve(vec);

	return 0;
}