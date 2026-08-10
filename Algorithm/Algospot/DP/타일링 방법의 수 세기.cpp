#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp;
int n;

constexpr int MAX = 1000000007;

// n-1 에서 세로블록 1개로 채운 경우, n-2에서 가로블록 2개로 채운 경우
// F(n) = F(n-1) + F(n-2) -> 피보나치
long long Func(int width)
{
    if (width <= 1)
    {
        return 1;
    }

    long long& ret = dp[width];
    if (ret != -1)
    {
        return ret;
    }

    return ret = (Func(width - 1) + Func(width - 2)) % MAX;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        dp.assign(n + 1, -1);

        cout << Func(n) << "\n";
    }
}
