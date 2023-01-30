#include <iostream>
#include <vector>

int N, M;

void input()
{
	std::cin >> N >> M;
}

void recursive_dfs(std::vector<int>& vec)
{
	if (vec.size() >= M)
	{
		for (auto i : vec)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		vec.push_back(i);
		recursive_dfs(vec);
		vec.pop_back();
	}
}

void solve()
{
	std::vector<int> vec;
	recursive_dfs(vec);
}

void output()
{

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	input();
	solve();
	output();
	return 0;
}