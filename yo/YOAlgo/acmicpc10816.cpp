#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int N, M;
std::vector<int> vec1, vec2;
std::unordered_map<int, int> hash;

void input()
{
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int input = 0;
		std::cin >> input;
		vec1.push_back(input);
		++hash[input];
	}

	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int input = 0;
		std::cin >> input;
		vec2.push_back(input);
	}
}

void solve()
{
	//std::sort(vec1.begin(), vec1.end());

	for (int i = 0; i < M; ++i)
	{
		std::cout << hash[vec2[i]] << ' ';
	}
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