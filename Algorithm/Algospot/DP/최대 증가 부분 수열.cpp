#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        dp.assign(n, 1);

        for (int& i : v)
        {
            cin >> i;
        }

        int ret = 1;
        for (int i = 1; i < n; ++i)
        {
            //i 에 대해서 이전 작은 숫자 확인
            // 가장 큰 값 + 1

            for (int j = 0; j < i; ++j)
            {
                if (v[i] > v[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(ret, dp[i]);
        }

        cout << ret << "\n";
    }
}
