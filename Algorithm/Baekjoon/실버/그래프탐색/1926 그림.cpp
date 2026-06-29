#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> visited;
int m, n;

int BFS(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({ sr, sc });
    visited[sr][sc] = true;

    int count = 1;

    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0 ,-1 };

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (visited[nr][nc] || graph[nr][nc] == 0) continue;

            visited[nr][nc] = true;
            q.push({ nr, nc });
            ++count;
        }
    }

    return count;
}

int main()
{
    cin >> n >> m;

    graph.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<int>(m, false));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int max_extent = 0;
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                max_extent = max(max_extent, BFS(i, j));
                ++count;
            }
        }
    }

    cout << count << "\n" << max_extent << "\n";
}
