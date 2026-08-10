#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<vector<double>> dp;

// 현재 높이, 지난 날짜
double Func(int height, int day)
{
    // 높이를 미리 도달했다면 조기종료
    if (height >= n)
    {
        return 1.0;
    }

    // 높이 도달을 못했지만 날짜를 넘은 경우
    if (day >= m)
    {
        return 0.0;
    }


    double& ret = dp[height][day];
    if (ret != -1.0)
    {
        return ret;
    }

    // 2칸 오르는 확률은 75퍼, 1칸오르는 확률은 25퍼
    return ret = Func(height + 2, day + 1) * 0.75 + Func(height + 1, day + 1) * 0.25;
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
        dp.assign(n + 2, vector<double>(m + 1, -1));

        cout << fixed;
        cout.precision(10);
        cout << Func(0, 0) << "\n";
    }
}
