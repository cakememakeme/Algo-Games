#include <iostream>
#include <vector>

long long dp[5010] = { 0 };

void solve(const int T)
{
	int value = 1;
	dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;
	for (int i = 6; i < 5010; i += 2)
	{
		for (int j = 2; j <= i; j += 2)
		{
			dp[i] += dp[j - 2] * dp[i - j];
			dp[i] %= 1000000007;
		}
	}

	std::vector<int> iVec;
	for (int i = 0; i < T; ++i)
	{
		int input;
		std::cin >> input;
		iVec.push_back(input);
	}

	for (int i = 0; i < iVec.size(); ++i)
	{
		std::cout << dp[iVec[i]] << '\n';
	}
}

//()
//
//(())
//()()
//
//((()))
//(()())
//()()()
//()(())
//(())()
//
//(((())))
//((()()))
//(()()())
//()()()()
//()((()))
//()(()())
//((()))()
//(()())()
//(())(())
//()()(())
//(())()()
//
//tlqkf

int main()
{
	int T;
	std::cin >> T;
	solve(T);

	return 0;
}