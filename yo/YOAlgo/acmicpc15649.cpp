#include <iostream>
#include <algorithm>
#include <vector>

void recursive_dfs(const int depth, const int num, std::vector<int>& vec)
{
	if (depth <= vec.size())
	{
		for (int i : vec)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = 1; i <= num; ++i)
	{
		if (std::find(vec.begin(), vec.end(), i) == vec.end())
		{
			vec.push_back(i);
			recursive_dfs(depth, num, vec);
			vec.pop_back();
		}
	}
}

void solve(int n, int m)
{
	std::vector<int> vec;
	recursive_dfs(m, n, vec);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::vector<int> vec;

	int n = 0;
	int m = 0;
	std::cin >> n >> m;

	solve(n, m);

	return 0;
}