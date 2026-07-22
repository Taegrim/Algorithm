#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<char>> graph;
unordered_set<char> route;
int r, c;
int max_depth;

int dr[]{ -1, 0, 1, 0 };
int dc[]{ 0, 1, 0, -1 };

void DFS(int row, int col, int depth)
{
    max_depth = max(max_depth, depth);

    for (int i = 0; i < 4; ++i)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;

        char next = graph[nr][nc];
        if (route.count(next)) continue;

        route.insert(next);
        DFS(nr, nc, depth + 1);
        route.erase(next);
    }
}

int main()
{
    cin >> r >> c;
    graph.assign(r, vector<char>(c));

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> graph[i][j];
        }
    }

    route.insert(graph[0][0]);
    DFS(0, 0, 1);

    cout << max_depth << "\n";
}
