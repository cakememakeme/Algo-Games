#include <iostream>
#include <vector>

void solve(const std::vector<int>& vec, const std::vector<std::pair<int, int>>& dists)
{
	for (const std::pair<int, int>& iter : dists)
	{
		int beforeFirstIdx = iter.first - 2;
		int secondIdx = iter.second - 1;
		int sum = vec[secondIdx];
		if (beforeFirstIdx >= 0)
		{
			sum -= vec[beforeFirstIdx];
		}
		std::cout << sum << '\n';
	}
}

int main()
{
	int N;
	int M;
	std::vector<int> vec;
	std::vector<std::pair<int, int>> dists;
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;
		vec.push_back(input);
		if (i > 0)
		{
			vec[i] += vec[i - 1];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int first;
		int second;
		std::cin >> first >> second;
		dists.push_back({ first, second });
	}

	solve(vec, dists);

	return 0;
}