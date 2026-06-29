#include <iostream>
#include <queue>

using namespace std;

vector<vector<char>> graph;
int n, m;

int BFS(int sr, int sc)
{
    vector<vector<int>> visited(n, vector<int>(m, 1e9));

    queue<pair<int, int>> q;
    q.push({ sr, sc });
    visited[sr][sc] = 0;

    int hour = 0;

    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0 ,-1 };

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();

        int current_hour = visited[row][col];

        for (int i = 0; i < 4; ++i)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (current_hour + 1 > visited[nr][nc] || graph[nr][nc] == 'W') continue;

            visited[nr][nc] = current_hour + 1;
            q.push({ nr, nc });
            hour = max(hour, current_hour + 1);
        }
    }

    return hour;
}

int main()
{
    cin >> n >> m;

    graph.assign(n, vector<char>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int max_hour = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (graph[i][j] == 'L')
            {
                max_hour = max(max_hour, BFS(i, j));
            }
        }
    }

    cout << max_hour << "\n";
}
