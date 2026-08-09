#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;

int BottomUp()
{
    vector<int> dp(n, 1);   // BottomUp DP

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

    return ret;
}

vector<int> dp; // TopDown DP

int GetLIS(int idx)
{
    int& ret = dp[idx];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;
    for (int i = idx + 1; i < n; ++i)
    {
        if (v[idx] >= v[i]) continue;

        ret = max(ret, GetLIS(i) + 1);
    }

    return ret;
}

int TopDown()
{
    int ret = 1;
    for (int i = 0; i < n; ++i)
    {
        ret = max(ret, GetLIS(i));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        v.assign(n, 0);     // 수열 초기화
        dp.assign(n, -1);    // 탑다운 DP 초기화

        for (int& i : v)
        {
            cin >> i;
        }

        cout << BottomUp() << "\n";
        cout << TopDown() << "\n";

    }
}
