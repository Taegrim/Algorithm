#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int n, m, k;

int DFS(int row, int col)
{
    visited[row][col] = true;
    int token = 1;

    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (graph[nr][nc] != 1 || visited[nr][nc]) continue;

        token += DFS(nr, nc);
    }

    return token;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    graph.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < k; ++i) {
        int row{}, col{};
        cin >> row >> col;

        graph[row - 1][col - 1] = 1;
    }

    int max_val = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && graph[i][j] == 1) {
                int val = DFS(i, j);
                max_val = max(max_val, val);
            }
        }
    }

    cout << max_val << "\n";
}
