#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int n, m;

void DFS(int row, int col)
{
    visited[row][col] = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (visited[nr][nc] || graph[nr][nc] == 1) continue;

        DFS(nr, nc);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    graph.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }

    int ret = 0;
    while (true) {
        // 바깥 부분을 전부 visited 로 만들기
        visited.assign(n, vector<bool>(m, false));
        DFS(0, 0);

        vector<pair<int, int>> melt;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (graph[i][j] == 0) continue;

                int air = 0;

                // 치즈인경우 바깥과 2면 이상 닿아있는지 확인해서 vector에 저장
                for (int k = 0; k < 4; ++k) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (visited[nr][nc] == 1) {
                        ++air;
                    }
                }

                if (air >= 2) {
                    melt.push_back({ i, j });

                }
            }
        }

        if (melt.empty()) break;

        ++ret;

        for (const auto& [r, c] : melt) {
            graph[r][c] = 0;
        }
    }

    cout << ret << "\n";
}
