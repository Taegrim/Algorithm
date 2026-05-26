#include <iostream>

#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// 1~N 까지의 마을
// 간선별로 걸리는 시간 다름
// K시간 이하로 배달 가능한 결과 반환 (자기자신 포함)
// (a, b, c) -> a, b는 마을, c는 걸리는 시간

const int INF = 1e9;

// BFS 응용 풀이 (기존 풀이)
void ShortestPath(const vector<vector<pair<int,int>>>& graph, vector<int>& times, int start)
{
    times[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 현재 마을을 오는데까지 걸리는 시간 + 다음 지역을 가는데 걸리는 시간 합이
        // 기존 해당 마을까지 가는데 걸리는 시간보다 작을때만 갱신
        for (const auto& [next, weight] : graph[current]) {
            int next_weight = times[current] + weight;

            if (next_weight < times[next]) {
                times[next] = next_weight;
                q.push(next);
            }
        }
    }
}


// 다익스트라 풀이 (추가 풀이)
void Dijkstra(const vector<vector<pair<int, int>>>& graph, vector<int>& times, int start)
{
    times[start] = 0;

    using IntPair = pair<int, int>;

    // 다익스트라는 우선순위 큐 사용
    // 항상 최단시간만을 먼저 체크해서 오래걸리는 시간은 무시하는 방식
    priority_queue<IntPair, vector<IntPair>, greater<IntPair>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [current_cost, current] = pq.top();
        pq.pop();

        // 이미 더 짧은 거리로 갱신이 되었다면 넘어감
        if (current_cost > times[current]) {
            continue;
        }

        for (const auto& [next, weight] : graph[current]) {
            int next_weight = current_cost + weight;

            if (next_weight < times[next]) {
                times[next] = next_weight;
                pq.push({ next_weight, next });
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    // 연결된 마을, 걸리는 시간을 저장
    vector<vector<pair<int, int>>> graph(N + 1);

    // a 마을부터 특정 마을까지 걸리는 시간
    vector<int> times(N + 1, INF);

    // 가중치 간선 연결
    for (const auto& v : road) {
        int a = v[0];
        int b = v[1];
        int weight = v[2];

        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    ShortestPath(graph, times, 1);

    answer = count_if(times.begin() + 1, times.end(), [K](int number) {
        return number <= K;
        });

    return answer;
}

int main()
{
    solution(5, { {1,2,1}, {2,3,3}, {5,2,2}, {1,4,2}, {5,3,1}, {5,4,2} }, 3);
    solution(6, { {1,2,1}, {1,3,2}, {2,3,2}, {3,4,3}, {3,5,2}, {3,5,3}, {5,6,1} }, 4);
}
