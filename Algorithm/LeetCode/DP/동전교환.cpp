#include <iostream>
#include <vector>

using namespace std;

vector<int> coins;
vector<int> dp;

constexpr int MAX = 1e9;

int Topdown(int num)
{
    if (num == 0)
    {
        return 0;
    }

    if (num < 0)
    {
        return MAX;
    }

    // 이미 있다면 
    if (dp[num] != -1)
    {
        return dp[num];
    }

    int ret = MAX;

    for (int coin : coins)
    {
        int prev = Topdown(num - coin);

        if (prev != MAX)
        {
            ret = min(ret, prev + 1);
        }
    }

    return dp[num] = ret;
}

int Bottomup(int num)
{
    vector<int> dp(num + 1, MAX);

    dp[0] = 0;

    for (int i = 1; i <= num; ++i)
    {
        for (int coin : coins)
        {
            if (i - coin < 0) continue;
            if (dp[i - coin] == MAX) continue;

            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[num];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    coins.assign(m, 0);
    dp.assign(n + 1, -1);

    for (int i = 0; i < m; ++i)
    {
        cin >> coins[i];
    }

    int topdown = Topdown(n);
    int bottomup = Bottomup(n);

    cout << (topdown == MAX ? -1 : topdown) << '\n';
    cout << (bottomup == MAX ? -1 : bottomup) << '\n';
}
