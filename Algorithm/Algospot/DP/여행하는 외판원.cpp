#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<double>> dist;
vector<vector<double>> dp;
// dp[i][j] = j 도시를 방문했고, 현재 i에 있을때
//            앞으로 남은 도시들을 방문하기 위한 최솟값

constexpr double MAX = 1e100;

// 현재 위치, 방문한 도시들(비트 연산)
double ShortestPath(int current, int visited)
{
    // 모든 도시를 방문했다면 종료
    if (visited == (1 << n) - 1)
    {
        return 0.0;
    }

    double& ret = dp[current][visited];
    if (ret > -0.5)
    {
        return ret;
    }

    ret = MAX;
    for (int next = 0; next < n; ++next)
    {
        // and 연산이 0이 아니면 방문한것
        if (visited & (1 << next))
        {
            continue;
        }

        // next까지의 거리 + 재귀
        ret = min(ret, dist[current][next] + ShortestPath(next, visited | (1 << next)));
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
        cin >> n;
        dist.assign(n, vector<double>(n, 0));
        dp.assign(n, vector<double>(1 << n, -1.0));

        for (auto& v : dist)
        {
            for (double& d : v)
            {
                cin >> d;
            }
        }

        double answer = MAX;
        for (int i = 0; i < n; ++i)
        {
            answer = min(answer, ShortestPath(i, 1 << i));
        }

        cout.precision(10);
        cout << fixed;
        cout << answer << "\n";
    }
}
