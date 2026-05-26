#include <iostream>

#include <vector>
#include <queue>

using namespace std;

// 최대 수용량(걸리는 시간), 최대 중량, 트럭별 무게

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 현재 다리 위 상태 (무게, 다리에 올라간 시간)
    queue<pair<int, int>> on_bridge;
    int total_weight{};
    int current_time{};
    int current_idx{};

    // 시간 증가시키면서 시뮬레이션
    // 대기중인 트럭이 남아있거나, 다리위에 트럭이 남아있으면 loop
    while (current_idx < truck_weights.size() || !on_bridge.empty()) {
        ++current_time;

        // 다리를 다 건넌 트럭 제거
        // 건넜을 때의 시간 = 올라간 시간 + length
        if (!on_bridge.empty() &&
            current_time - on_bridge.front().second >= bridge_length)
        {
            total_weight -= on_bridge.front().first;
            on_bridge.pop();
        }

        // 다리 위에 트럭 올리기
        if (current_idx < truck_weights.size() &&
            total_weight + truck_weights[current_idx] <= weight)
        {
            on_bridge.push({ truck_weights[current_idx], current_time });
            total_weight += truck_weights[current_idx];
            ++current_idx;
        }
    }

    return current_time;
}

int main()
{
    solution(2, 10, { 7,4,5,6 });
    solution(100, 100, { 10 });
    solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });
}
