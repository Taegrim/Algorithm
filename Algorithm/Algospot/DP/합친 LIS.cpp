#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int n, m;
vector<vector<int>> dp;
vector<int> a;
vector<int> b;

constexpr long long MIN = numeric_limits<long long>::min();

int GetJLIS(int index_a, int index_b)
{
    int& ret = dp[index_a + 1][index_b + 1];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;

    long long num_a = (index_a == -1) ? MIN : a[index_a];
    long long num_b = (index_b == -1) ? MIN : b[index_b];
    long long max_num = max(num_a, num_b);

    // A에서 찾기
    for (int next = index_a + 1; next < n; ++next)
    {
        if (max_num >= a[next]) continue;

        ret = max(ret, GetJLIS(next, index_b) + 1);
    }

    // B에서 찾기
    for (int next = index_b + 1; next < m; ++next)
    {
        if (max_num >= b[next]) continue;

        ret = max(ret, GetJLIS(index_a, next) + 1);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        dp.assign(n + 1, vector<int>(m + 1, -1));
        a.assign(n, 0);
        b.assign(m, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }

        cout << GetJLIS(-1, -1) << "\n";
    }
}
