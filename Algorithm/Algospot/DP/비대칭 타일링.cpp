#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 1000000007;

int n;
vector<int> dp;

// 타일링 경우의수 구하는 함수
int Tiling(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int& ret = dp[n];
    if (ret != -1)
    {
        return ret;
    }

    return ret = (Tiling(n - 2) + Tiling(n - 1)) % MAX;
}

// 대칭인 경우만 구하기
// 절반을 배치하면 나머지 절반은 그대로 뒤집어서 배치한것과 같음
int MirrorTiling(int n)
{
    if (n % 2 == 1)
    {
        // n이 홀수라면 가운데 세로 타일 하나 배치,
        // 0 ~ n/2 까지 배치하면 반대는 동일함
        return Tiling(n / 2);
    }
    else
    {
        // n이 짝수라면
        // 1. 정중앙을 기준으로 그대로 좌우 대칭
        // 2. 가운데 가로타일 2개 배치한 경우, 0 ~ (n/2 - 1)
        return (Tiling(n / 2) + Tiling(n / 2 - 1)) % MAX;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        dp.assign(n + 1, -1);

        cout << (Tiling(n) - MirrorTiling(n) + MAX) % MAX << "\n";
    }
}
