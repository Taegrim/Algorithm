#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int n;

void DFS(int row, int col, int height)
{
    visited[row][col] = true;

    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        // 방문하지 않았고, 높이가 height보다 높을때만 방문
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (visited[nr][nc] || graph[nr][nc] <= height) continue;

        DFS(nr, nc, height);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    graph.assign(n, vector<int>(n, 0));

    int min_height = 1e9;
    int max_height = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];

            min_height = min(min_height, graph[i][j]);
            max_height = max(max_height, graph[i][j]);
        }
    }

    int ret = 1;
    for (int k = min_height; k < max_height; ++k) {
        visited.assign(n, vector<bool>(n, false));

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 높이가 더 높고 방문하지 않은 경우 DFS
                if (graph[i][j] > k && !visited[i][j]) {
                    DFS(i, j, k);
                    ++cnt;
                }
            }
        }

        ret = max(ret, cnt);
    }


    cout << ret << "\n";
}
