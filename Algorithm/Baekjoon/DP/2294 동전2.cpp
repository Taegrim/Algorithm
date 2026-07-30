#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> dp(k + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int coin;
        cin >> coin;

        for (int j = coin; j <= k; ++j)
        {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[k] == 1e9)
    {
        dp[k] = -1;
    }

    cout << dp[k] << "\n";
}
