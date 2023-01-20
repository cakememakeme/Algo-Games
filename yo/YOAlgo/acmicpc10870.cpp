#include <iostream>

int solve(int n)
{
    if (n < 2)
    {
        return n;
    }

    return solve(n - 1) + solve(n - 2);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int ans = 0;
    std::cin >> ans;
    std::cout << solve(ans);
}