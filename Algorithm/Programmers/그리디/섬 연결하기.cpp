#include <iostream>

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 최소 비용으로 모든 섬 통행 가능하게

vector<int> nodes;
int answer;

int FindParent(int current)
{
    // 자기자신이 부모면 종료
    if (current == nodes[current]) {
        return current;
    }

    // 아닐 경우엔 부모를 따라 찾아감
    return nodes[current] = FindParent(nodes[current]);
}

void Kruskal(vector<vector<int>> costs, int n)
{
    nodes.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        nodes[i] = i;
    }

    // 코스트 낮은 순서대로 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
        });

    int count = 0;
    for (const auto& v : costs) {
        int parent_a = FindParent(v[0]);
        int parent_b = FindParent(v[1]);
        int cost = v[2];

        if (parent_a != parent_b) {
            answer += cost;
            nodes[parent_b] = parent_a;
            ++count;

            // 간선이 n-1 개면 모든섬을 연결할 수 있으므로 빠져나오기
            if (count == n - 1) {
                break;
            }
        }
    }
}

void Prim(const vector<vector<int>>& costs, int n)
{
    // 비용, 도착 섬
    using node = pair<int, int>;

    vector<vector<node>> graph(n);

    // 그래프 만들기
    for (const auto& cost : costs) {
        graph[cost[0]].push_back({ cost[1], cost[2] });
        graph[cost[1]].push_back({ cost[0], cost[2] });
    }

    priority_queue<node, vector<node>, greater<node>> pq;
    vector<bool> visited(n, false);

    pq.push({ 0, 0 });

    int count = 0;

    while (!pq.empty() && count < n) {
        auto [cost, current] = pq.top();
        pq.pop();

        if (visited[current]) continue;

        visited[current] = true;
        answer += cost;
        ++count;

        for (const auto& [next, next_cost] : graph[current]) {
            if (!visited[next]) {
                pq.push({ next_cost, next });
            }
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    answer = 0;

    Kruskal(costs, n);
    //Prim(costs, n);

    return answer;
}

int main()
{
    solution(4, { {0,1,1} ,{0,2,2},{1,2,5},{1,3,1},{2,3,8} });
}
