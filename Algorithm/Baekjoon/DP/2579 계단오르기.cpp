#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    // i번째 칸을 따로 밟음, 밟지않았을 때, 연속해서 밟았을때
    // dp[i][0] = v[i] + dp[i-1][1] -> 현재칸만 밟으려면 이전칸은 안밟아야 함
    // dp[i][1] = max(dp[i-1][0], dp[i-1][2]) -> 밟지않았을때, 이전칸을 반드시 밟아야함
    // dp[i][2] = v[i] + dp[i-1][0] -> 연속해서 밟으려면 이전칸을 반드시 밟아야함
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = v[0];
    dp[0][1] = 0;
    dp[0][2] = -1e9;  // 첫번째 칸이 연속인건 불가능

    if (n >= 2)
    {
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = v[i] + dp[i - 1][1];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = v[i] + dp[i - 1][0];
        }
    }

    cout << max(dp[n - 1][0], dp[n - 1][2]) << "\n";
}
