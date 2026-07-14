#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int max_count = 0;
vector<vector<int>> graph;
vector<pair<int, int>> zero;
vector<pair<int, int>> virus;

constexpr int MAX_COUNT = 3;

int dr[]{ -1, 0, 1, 0 };
int dc[]{ 0, 1, 0, -1 };

void CheckSafeCount()
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> g = graph;
    
    for (const auto& [r, c] : virus)
    {
        q.push({ r,c });
        visited[r][c] = true;
    }

    while (q.size())
    {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (visited[nr][nc] || g[nr][nc] != 0) continue;

            visited[nr][nc] = true;
            g[nr][nc] = 2;
            q.push({ nr, nc });
        }
    }

    int count = 0;
    for (const auto& [row, col] : zero)
    {
        if (g[row][col] == 0)
        {
            ++count;
        }
    }
    max_count = max(max_count, count);
}

void DFS(int current, int count)
{
    if (count == MAX_COUNT)
    {
        CheckSafeCount();
        return;
    }

    for (int i = current; i < zero.size(); ++i)
    {
        const auto& [row, col] = zero[i];

        graph[row][col] = 1;
        DFS(i + 1, count + 1);
        graph[row][col] = 0;
    }
}

int main()
{
    cin >> n >> m;
    graph.assign(n, vector<int>(m));
    zero.reserve(64);
    virus.reserve(10);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 0)
            {
                zero.push_back({ i, j });
            }
            else if (graph[i][j] == 2)
            {
                virus.push_back({ i, j });
            }
        }
    }

    DFS(0, 0);

    cout << max_count << "\n";
}
