#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;   // 무게, 가치
vector<vector<int>> dp;

int n, k;

int Func(int idx, int weight)
{
    // 탐색 끝
    if (idx < 0)
    {
        return 0;
    }

    if (dp[idx][weight] != -1)
    {
        return dp[idx][weight];
    }

    int w = v[idx].first;
    int val = v[idx].second;

    int& ret = dp[idx][weight];

    // 현재 물건을 넣지 않는 경우, 이전값 그대로 사용
    ret = Func(idx - 1, weight);

    // 현재 물건을 넣는 경우
    if (weight - w >= 0)
    {
        ret = max(ret, Func(idx - 1, weight - w) + val);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    v.resize(n);
    dp.assign(n + 1, vector<int>(k + 1, -1));

    for (auto& [weight, value] : v)
    {
        cin >> weight >> value;
    }

    cout << Func(n - 1, k) << "\n";
}
