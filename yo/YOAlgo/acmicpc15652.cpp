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
		for (auto iter : vec)
		{
			std::cout << iter << ' ';
		}
		std::cout << '\n';
		return;
	}

	const int last = vec.empty() ? 1 : vec.back();
	for (int i = last; i <= N; ++i)
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