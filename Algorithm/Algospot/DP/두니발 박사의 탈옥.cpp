#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> dp;
vector<vector<int>> graph;
int count;
int n, d, p;
// n : 마을수, d : 지난일수, p : 교도소 번호

// 현재 위치, 지난 날짜
// 탈옥후 day가 지난 날에 current에 있을 확률
double Func(int current, int day)
{
    // 0일째로 돌아가면
    if (day == 0)
    {
        // 교도소인지 확인
        return current == p ? 1.0 : 0.0;
    }

    double& ret = dp[current][day];
    if (ret > -0.5)
    {
        return ret;
    }

    ret = 0.0;
    for (int prev : graph[current])
    {
        ret += Func(prev, day - 1) / graph[prev].size();
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
        cin >> n >> d >> p;

        graph.assign(n, vector<int>());
        dp.assign(n + 1, vector<double>(d + 1, -1.0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int k;
                cin >> k;

                if (k == 1)
                {
                    graph[i].push_back(j);
                }
            }
        }

        // 확률을 계산할 마을의 수
        int T;
        cin >> T;

        cout << fixed;
        cout.precision(8);

        for (int i = 0; i < T; ++i)
        {
            int target;
            cin >> target;

            cout << Func(target, d) << " ";
        }
        cout << "\n";

    }
}
