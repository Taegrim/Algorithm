#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, b;
vector<int> visited;

bool DFS(const vector<vector<int>>& graph, int current, int depth, int& ret)
{
    visited[current] = true;

    if (current == b) {
        ret = depth;
        return true;
    }

    for (int next : graph[current]) {
        if (!visited[next]) {
            if (DFS(graph, next, depth + 1, ret)) {
                return true;
            }
        }
    }
    return false;
}

void BFS(const vector<vector<int>>& graph, int start, int end, int& ret)
{
    queue<pair<int, int>> q;
    q.push({ start, 0 });

    while (!q.empty()) {
        auto [cur, depth] = q.front();
        q.pop();

        visited[cur] = true;

        if (cur == end) {
            ret = depth;
            return;
        }

        for (int next : graph[cur]) {
            if (!visited[next]) {
                q.push({ next, depth + 1 });
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> a >> b >> m;

    vector<vector<int>> graph(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ret = -1;
    //DFS(graph, a, 0, ret);
    BFS(graph, a, b, ret);

    cout << ret << endl;
}
