#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;

int DFS(const vector<vector<int>>& graph, int current)
{
    int token = 1;
    visited[current] = true;

    for (int next : graph[current]) {
        if (!visited[next]) {
            token += DFS(graph, next);
        }
    }

    return token;
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

        graph[b].push_back(a);
    }

    int max_value = -1;
    vector<int> answer(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        fill(visited.begin(), visited.end(), false);

        answer[i] = DFS(graph, i);
        max_value = max(max_value, answer[i]);
    }

    for (int i = 1; i <= n; ++i) {
        if (max_value == answer[i]) {
            cout << i << " ";
        }
    }
}
