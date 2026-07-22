#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;

int DFS(const vector<vector<int>>& graph, int current)
{
    visited[current] = true;

    int answer = 1;

    for (int next : graph[current]) {
        if (!visited[next]) {
            answer += DFS(graph, next);
        }
    }

    return answer;
}

int main()
{
    // 컴퓨터 수
    int n;
    cin >> n;

    //간선 수
    int k;
    cin >> k;

    vector<vector<int>> graph(n + 1);
    visited.assign(n + 1, false);

    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << DFS(graph, 1) - 1 << "\n";
}
