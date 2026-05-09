#include <iostream>

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstdlib>

using namespace std;

// wires[0] <-> wires[1] 간선

// 간선 bfs 로 탐색하면서 연결된 개수 세기
int CountTowers(const vector<vector<int>>& towers, int start, int blocked, int n)
{
    vector<bool> visited(n + 1, false);

    int count = 0;
    queue<int> next_towers;

    visited[start] = true;
    next_towers.push(start);

    //탐색 가능하면 큐에 넣어가면서 탐색
    while (!next_towers.empty()) {
        int current = next_towers.front();
        next_towers.pop();
        ++count;

        for (int next : towers[current]) {
            if (!visited[next] && next != blocked) {
                visited[next] = true;
                next_towers.push(next);
            }
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> towers(n + 1);

    // 양방향 간선 연결
    for (const auto& wire : wires) {
        towers[wire[0]].push_back(wire[1]);
        towers[wire[1]].push_back(wire[0]);
    }

    int min_diff = numeric_limits<int>::max();

    // 하나씩 연결 끊어가면서 확인
    for (const auto& wire : wires) {
        int tower1 = wire[0];
        int tower2 = wire[1];

        int count1 = CountTowers(towers, tower1, tower2, n);

        // 한쪽을 구하면 나머진 n - count 가 됨
        int count2 = n - count1;

        min_diff = min(min_diff, abs(count1 - count2));
    }

    return min_diff;
}

int main()
{
    solution(9, { {1,3}, {2,3}, {3,4}, {4,5}, {4,6}, {4,7}, {7,8}, {7,9} });
    solution(4, { {1,2}, {2,3}, {3,4} });
    solution(7, { {1,2}, {2,7}, {3,7}, {3,4}, {4,5}, {6,7} });
}
