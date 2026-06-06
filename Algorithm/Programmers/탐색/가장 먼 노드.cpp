#include <iostream>

#include <vector>
#include <queue>

using namespace std;

// 1번 노드에서 최단 경로로 이동했을 때 간선이 가장 많은 노드들의 개수
// 간선별 비용 = 1로 동일 -> BFS

int max_dist;
int answer;
int MAX = 1e9;

void BFS(const vector<vector<int>>& graph)
{
    vector<int> visited(graph.size(), MAX);

    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    visited[1] = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (dist > max_dist) {
            // 현재 노드가 최대 거리일경우 갱신
            max_dist = dist;
            answer = 1;
        }
        else if (dist == max_dist) {
            // 현재 노드가 이전 최대거리와 같다면 개수만 증가
            ++answer;
        }

        int next_dist = dist + 1;

        for (int next : graph[node]) {
            // 최단거리일경우에만 방문
            if (next_dist < visited[next]) {
                visited[next] = next_dist;
                q.push({ next, next_dist });
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    max_dist = 0;
    answer = 0;

    vector<vector<int>> graph(n + 1, vector<int>());

    for (const auto& v : edge) {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }

    BFS(graph);

    return answer;
}

int main()
{
    solution(6, { {3, 6} ,{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });
}
