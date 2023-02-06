#include <iostream>
#include <vector>

long long A, B, C;
std::vector<int> Vec;

void input()
{
	std::cin >> A >> B >> C;
	//Vec = std::vector<int>(B, A);
}
//
//long long recursive_dq(int from, int to)
//{
//	if (to <= from)
//	{
//		return A;
//	}
//
//	int half = (to - from) / 2 + from;
//	return recursive_dq(from, half) * recursive_dq(half + 1, to);
//}

void solve()
{
	//long long a = 1;
	//while (B > 0)
	//{
	//	if (B % 2 == 1)
	//	{
	//		a *= A;
	//		a %= C;
	//	}
	//	A *= A;
	//	B /= 2;
	//}
	//std::cout << a;
	//std::cout << recursive_dq(0, B) % C;
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