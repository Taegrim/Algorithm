#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int sr, sc, tr, tc;
    cin >> sr >> sc >> tr >> tc;
    sr--; sc--; tr--; tc--;

    vector<vector<char>> graph(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j];
        }
    }

    graph[sr][sc] = 0;

    int dr[]{ -1, 0, 1, 0 };
    int dc[]{ 0, 1, 0, -1 };

    int count = 0;
    while (graph[tr][tc] != '0')
    {
        ++count;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        visited[sr][sc] = true;
        graph[sr][sc] = 0;

        vector<pair<int, int>> v;
        while (q.size())
        {
            auto [row, col] = q.front();
            q.pop();

            if (row == tr && col == tc)
            {
                graph[tr][tc] = '0';
                break;
            }

            for (int i = 0; i < 4; ++i)
            {
                int nr = dr[i] + row;
                int nc = dc[i] + col;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (visited[nr][nc]) continue;
                if (graph[nr][nc] == '1')
                {
                    v.push_back({ nr, nc });
                    continue;
                }

                q.push({ nr, nc });
                visited[nr][nc] = true;
            }
        }

        for (const auto& [row, col] : v)
        {
            graph[row][col] = '0';
        }
    }
    cout << count << "\n";

}
