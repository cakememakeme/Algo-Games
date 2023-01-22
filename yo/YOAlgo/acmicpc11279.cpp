#include <iostream>
#include <queue>

int N;
std::priority_queue<int> pq;

void input()
{
	std::cin >> N;
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		int input = 0;
		std::cin >> input;

		if (input != 0)
		{
			pq.emplace(input);
		}
		else
		{
			int output = 0;
			if (!pq.empty())
			{
				output = pq.top();
				pq.pop();
			}
			std::cout << output << '\n';
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	input();
	solve();
	return 0;
}