#include <iostream>
#include <vector>

int N, M;

void input()
{
	std::cin >> N >> M;
}

void output(std::vector<int>& vec)
{
	for (int i : vec)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

void recursive_dfs(std::vector<int>& vec)
{
	if (vec.size() >= M)
	{
		output(vec);
		return;
	}

	for (int i = vec[vec.size() - 1] + 1; i <= N; ++i)
	{
		vec.push_back(i);
		recursive_dfs(vec);
		vec.pop_back();
	}
}

void solve()
{
	std::vector<int> vec;
	for (int i = 1; i <= N; ++i)
	{
		vec.push_back(i);
		recursive_dfs(vec);
		vec.pop_back();
	}
}

int main()
{
	input();
	solve();
	return 0;
}