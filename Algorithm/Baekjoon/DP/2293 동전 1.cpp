#include <iostream>
#include <vector>

using namespace std;

vector<int> coins;
int dp[10004];

int n, k;

int main()
{
    cin >> n >> k;

    dp[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;

        for (int j = temp; j <= k; ++j)
        {
            dp[j] += dp[j - temp];
        }
    }

    cout << dp[k] << "\n";
}
