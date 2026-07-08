#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> graph;
int R, C;
int answer = 0;

int dr[]{ -1, 0, 1, 0 };
int dc[]{ 0, 1, 0, -1 };

void DFS(int row, int col, int route, int depth)
{
    answer = max(answer, depth);

    for (int i = 0; i < 4; ++i)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

        int next = 1 << (graph[nr][nc] - 'A');
        if (route & next) continue;

        DFS(nr, nc, route | next, depth + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    graph.assign(R, vector<char>(C));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int bit = 1 << (graph[0][0] - 'A');
    DFS(0, 0, bit, 1);

    cout << answer << "\n";
}
