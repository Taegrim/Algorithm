#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<pair<double, double>> points;
vector<vector<double>> dist;
int n;

bool BFS(double mid)
{
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;
    int count = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // 현재기지와 다른 기지들의 거리 확인
        for (int next = 0; next < n; ++next)
        {
            // 이미 방문했다면 건너뜀
            if (visited[next]) continue;

            // 통신이 가능하면 연결
            if (dist[current][next] <= mid)
            {
                visited[next] = true;
                q.push(next);
                ++count;
            }
        }
    }

    return count == n;
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

        points.assign(n, pair<double, double>());
        dist.assign(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; ++i)
        {
            cin >> points[i].first >> points[i].second;
        }

        // 기지들간의 거리 계산
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (i == j) continue;

                double x = points[i].first - points[j].first;
                double y = points[i].second - points[j].second;

                dist[i][j] = dist[j][i] = sqrt(x * x + y * y);
            }
        }

        double left = 0;
        double right = 2000.0;

        for (int i = 0; i < 100; ++i)
        {
            double mid = left + (right - left) / 2.0;

            // mid 거리로 모든 기지가 연결되어있는지 확인
            if (BFS(mid))
            {
                // 연결가능하면 줄여보기
                right = mid;
            }
            else
            {
                // 불가능하면 늘리기
                left = mid;
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << right << "\n";
    }
}
