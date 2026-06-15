#include <iostream>

#include <vector>
#include <queue>

using namespace std;

// 간선 길이 1
// n : 총 지역수, roads : 왕복 가능한 길 정보
// sources : 부대원들이 위치한 서로다른 지역, destination : 목적지

int MAX = 1e9;
vector<int> dists;

// 부대에서 각 지역들까지 걸리는 시간 기록
void BFS(const vector<vector<int>>& graph, int start)
{
    queue<pair<int, int>> q;

    dists[start] = 0;
    q.push({ start, 0 });

    while (!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (dists[next] > dist + 1) {
                dists[next] = dist + 1;
                q.push({ next, dist + 1 });
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    answer.reserve(sources.size());

    vector<vector<int>> graph(n + 1, vector<int>());
    dists.assign(n + 1, MAX);

    for (const auto& road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }

    // 반대로 목적지에서 부대원들까지 걸리는 시간을 구하기
    BFS(graph, destination);

    for (int source : sources) {
        if (dists[source] == MAX) {
            dists[source] = -1;
        }

        answer.push_back(dists[source]);
    }

    return answer;
}

int main()
{
    solution(3, { {1,2}, {2,3} }, { 2,3 }, 1);
    solution(5, { {1,2}, {1,4},{2,4},{2,5},{4,5} }, { 1,3,5 }, 5);
}
