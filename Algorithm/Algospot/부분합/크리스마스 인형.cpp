#include <iostream>
#include <vector>

using namespace std;

// 한번할때 주문 가능한 방법 개수, 여러번하면 겹치지않게 최대 몇번
// 누적합이 K의 배수여야 함

// (psum[right] - psum[left]) % k == 0
//  -> psum[right] % k == psum[left] % k
//     누적합 자체를 k로 나눈 나머지를 저장하고 비교하면 됨

vector<int> v;
vector<int> psum;   // psum[i] : 누적합을 k로 나눈 나머지

int n, k;

constexpr int MOD = 20091101;

int GetOnce()
{
    vector<long long> counts(k);

    // 해당 나머지가 몇번 나왔는지 확인
    for (int num : psum)
    {
        ++counts[num];
    }

    long long ret = 0;

    for (long long c : counts)
    {
        // 가능한 구간에서 2개를 선택하는 경우 더하기
        // nC2
        ret += c * (c - 1) / 2;
        ret %= MOD;
    }

    return (int)ret;
}

int GetMultiple()
{
    vector<int> dp(n + 1);     // dp[i] : 앞에서 i개를 이용해서 만들 수 있는 최대 주문 개수
    vector<int> prev(k, -1);   // prev[remain] : 나머지가 remain이었던 가장 최근의 index

    prev[psum[0]] = 0;

    for (int i = 1; i <= n; ++i)
    {
        // i번째를 선택안한 경우
        dp[i] = dp[i - 1];

        int remain = psum[i];

        if (prev[remain] != -1)
        {
            // 선택한 경우는 [prev[remain] ~ i) 가 1번이 됨
            // 따라서 그 이전에 만들 수 있는 최대 주문개수 + 1 이 선택한 경우
            //  -> dp[prev[remain]] + 1
            dp[i] = max(dp[i], dp[prev[remain]] + 1);
        }

        prev[remain] = i;
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        v.assign(n, 0);
        psum.assign(n + 1, 0);

        for (int& i : v)
        {
            cin >> i;
        }

        // 누적합 전처리
        psum[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            psum[i] = (psum[i - 1] + v[i - 1]) % k;
        }

        cout << GetOnce() << " ";
        cout << GetMultiple() << "\n";
    }
}
