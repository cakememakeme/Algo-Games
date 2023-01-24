#include <iostream>
#include <string>
#include <unordered_set>

std::string S;
std::unordered_set<std::string> hash;

void input()
{
	std::cin >> S;
}

void solve()
{
	for (int size = 1; size <= S.size(); ++size)
	{
		for (int j = 0; j < S.size(); ++j)
		{
			if (j + size > S.size())
			{
				break;
			}
			std::string str;
			str.assign(S, j, size);
			hash.insert(str);
		}
	}
}

void output()
{
	std::cout << hash.size();
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