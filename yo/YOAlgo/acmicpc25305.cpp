#include <iostream>
#include <vector>
#include <algorithm>

int N, k;
std::vector<int> vec;

void input()
{
	std::cin >> N >> k;
	for (int i = 0; i < N; ++i)
	{
		int input;
		std::cin >> input;
		vec.push_back(input);
	}
}

void solve()
{
	std::sort(vec.begin(), vec.end());
}

void output()
{
	std::cout << vec[vec.size() - k];
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