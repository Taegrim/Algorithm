#include <iostream>
#include <vector>

using namespace std;

constexpr int CACHE_SIZE = 201;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        m /= 100;

        vector<int> price(n + 1);
        vector<int> pref(n + 1);

        for (int i = 0; i < n; ++i)
        {
            cin >> price[i] >> pref[i];
            price[i] /= 100;
        }

        vector<int> dp(CACHE_SIZE, -1);

        int ret = 0;
        dp[0] = 0;

        for (int budget = 1; budget <= m; ++budget)
        {
            int cand = 0;

            for (int dish = 0; dish < n; ++dish)
            {
                if (budget >= price[dish])
                {
                    cand = max(cand, dp[(budget - price[dish]) % CACHE_SIZE] + pref[dish]);
                }
            }

            dp[budget % CACHE_SIZE] = cand;
            ret = max(ret, cand);
        }

        cout << ret << "\n";
    }
}
