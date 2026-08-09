#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// s개 숫자만 이용해서 양자화
// 숫자별 오차 제곱의 합이 최소화 되도록

vector<int> v;
vector<int> sum;
vector<int> square_sum;
vector<vector<int>> dp;
int n, s;

constexpr int MAX = 1e9;

// (v[i] - 평균)^2 의 합
// v[i]*2 - 2 * 평균 * v[i] + 평균^2  의 합
// 제곱의 부분합 - 2*평균*구간합 + 평균^2 * 구간 길이
int GetMin(int left, int right)
{
    // 평균값이 최소오차

    // 구간합, 제곱합
    int num = sum[right] - (left == 0 ? 0 : sum[left - 1]);
    int square_num = square_sum[right] - (left == 0 ? 0 : square_sum[left - 1]);

    int len = right - left + 1;

    // 평균값
    int val = static_cast<int>(0.5 + (double)num / len);

    return square_num - 2 * val * num + val * val * len;
}

int F(int start, int remain)
{
    if (start == n)
    {
        return 0;
    }

    // 숫자가 남았지만 구간을 더 나눌수가 없다면 불가능한 것
    if (remain == 0)
    {
        return MAX;
    }

    int& ret = dp[start][remain];
    if (ret != -1)
    {
        return ret;
    }

    ret = MAX;
    for (int len = 1; len + start <= n; ++len)
    {
        ret = min(ret, GetMin(start, start + len - 1) + F(start + len, remain - 1));
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
        cin >> n >> s;

        v.assign(n, 0);
        dp.assign(n + 1, vector<int>(s + 1, -1));
        sum.assign(n, 0);
        square_sum.assign(n, 0);

        for (int& num : v)
        {
            cin >> num;
        }

        sort(v.begin(), v.end());

        sum[0] = v[0];
        square_sum[0] = v[0] * v[0];

        for (int i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + v[i];
            square_sum[i] = square_sum[i - 1] + v[i] * v[i];
        }

        cout << F(0, s) << "\n";
    }

}
