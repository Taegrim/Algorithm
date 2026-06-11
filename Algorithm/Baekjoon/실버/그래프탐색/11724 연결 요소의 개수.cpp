#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;

void DFS(const vector<vector<int>>& graph, int current)
{
    visited[current] = true;

    for (int next : graph[current]) {
        if (!visited[next]) {
            DFS(graph, next);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS(graph, i);
            ++answer;
        }
    }
    cout << answer << "\n";
}
