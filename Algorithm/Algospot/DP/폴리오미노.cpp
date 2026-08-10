#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp;

constexpr int MAX = 10'000'000;

// 현재 남은 정사각형의 개수, 현재 맨 윗줄에 놓은 정사각형의 수
long long Func(int n, int first)
{
    // 남은 정사각형을 맨 윗줄에 모두 사용했으면 종료
    if (n == first)
    {
        return 1;
    }

    long long& ret = dp[n][first];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;
    for (int next = 1; next <= n - first; ++next)
    {
        // 배치할 블럭은 (first + next - 1) 만큼 위치를 둘 수 있기 때문에 곱함
        long long add = Func(n - first, next) * (first + next - 1);

        ret = (ret + add) % MAX;
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
        int n;
        cin >> n;
        dp.assign(n + 1, vector<long long>(n + 1, -1));

        // 첫줄에 놓일 개수 판정
        long long answer = 0;
        for (int first = 1; first <= n; ++first)
        {
            answer = (answer + Func(n, first)) % MAX;
        }

        cout << answer << "\n";
    }
}
