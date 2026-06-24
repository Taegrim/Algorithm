#include <iostream>

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// 1~n 까지의 지점,  출입구, 쉼터, 산봉우리
// 쉼터 or 산봉우리는 휴식 가능,  intensity는 휴식 없이 이동하는 긴 시간
// 시작점 - 산봉우리 - 시작점이 되도록, 산봉우리 1번만, 다른 출입구 방문 X
// 출발점, 산봉우리가 아니면 전부 쉼터
// intensity = 경로 중 가장 긴 시간

int min_intensity = 1e9;
int goal;
vector<vector<pair<int, int>>> graph;

void BFS(const vector<int>& gates, const unordered_set<int>& summits, int n)
{
    vector<int> intensity(n + 1, 1e9);

    // cost, next를 저장하는 pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for (int gate : gates)
    {
        pq.push({ 0, gate });
        intensity[gate] = 0;
    }

    while (!pq.empty())
    {
        auto [current_intensity, current] = pq.top();
        pq.pop();

        // 중복 노드가 들어올 수 있으니 현재와 기존 intensity 비교
        if (current_intensity > intensity[current]) continue;
        // 봉우리 도달하면 현재 경로는 끝
        if (summits.count(current)) continue;

        for (const auto& [next, next_cost] : graph[current])
        {
            // 기존에 구한 해당 경로의 intensity보다 크면 X
            int cost = max(next_cost, current_intensity);
            if (cost >= intensity[next]) continue;

            intensity[next] = cost;
            pq.push({ cost, next });
        }
    }

    for (int summit : summits)
    {
        if (intensity[summit] < min_intensity)
        {
            min_intensity = intensity[summit];
            goal = summit;
        }
        if (intensity[summit] == min_intensity && summit < goal)
        {
            goal = summit;
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    graph.assign(n + 1, vector<pair<int, int>>());
;
    for (const auto& path : paths)
    {
        graph[path[0]].push_back({ path[1], path[2] });
        graph[path[1]].push_back({ path[0], path[2] });
    }

    // 게이트
    unordered_set<int> s(summits.begin(), summits.end());

    BFS(gates, s, n);

    return { goal, min_intensity };
}

int main()
{
    solution(6, { {1, 2, 3} ,{2, 3, 5},{2, 4, 2},{2, 5, 4},{3, 4, 4},{4, 5, 3}, {4, 6, 1},{5, 6, 1} },
        { 1,3 }, { 5 });
    solution(7, {{1, 4, 4}, {1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6}},
        { 1 }, { 2,3,4 });
    solution(7, {{1, 2, 5}, {1, 4, 1}, {2, 3, 1}, {2, 6, 7}, {4, 5, 1}, {5, 6, 1}, {6, 7, 1}},
        { 3, 7 }, { 1, 5 });
    solution(5, {{1, 3, 10}, {1, 4, 20}, {2, 3, 4}, {2, 4, 6}, {3, 5, 20}, {4, 5, 6}},
        { 1,2 }, { 5 });
}
