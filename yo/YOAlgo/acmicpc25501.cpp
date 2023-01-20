#include <iostream>
#include <string>
#include <cstring>

int cnt = 0;

int recursion(const char* s, int l, int r) {
	++cnt;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int loop = 0;
	std::cin >> loop;
	for (int i = 0; i < loop; ++i)
	{
		std::string str;
		std::cin >> str;
		std::cout << isPalindrome(str.c_str()) << ' ' << cnt << '\n';
		cnt = 0;
	}
	return 0;
}