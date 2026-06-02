#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

// cap 수용량, n 배달할 집 개수
// deliveries : i+1 번째 집에 배달할 상자 개수
// pickups : i+1 번째 집에서 수거할 상자 개수

// 가장 멀리 배달 갔다가 돌아오면서 수거하기
// 그 다음으로 멀리갔다가 돌아오면서 수거하기

void RemoveVector(vector<int>& v)
{
    while (!v.empty() && v.back() == 0) {
        v.pop_back();
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    // 뒤에 0이라면 제거, 갈필요 없음
    RemoveVector(deliveries);
    RemoveVector(pickups);

    while (!deliveries.empty() || !pickups.empty()) {
        long long delivery_dist = deliveries.size();
        long long pickup_dist = pickups.size();

        long long max_dist = max(delivery_dist, pickup_dist);
        answer += max_dist * 2;

        if (!deliveries.empty()) {
            int current_delivery = cap;
            
            for (int i = delivery_dist - 1; i >= 0 && current_delivery > 0; --i) {
                // 전부 배달 가능하면
                if (current_delivery >= deliveries[i]) {
                    current_delivery -= deliveries[i];
                    deliveries[i] = 0;
                }
                else {
                    deliveries[i] -= current_delivery;
                    current_delivery = 0;
                    break;
                }
            }
        }

        if (!pickups.empty()) {
            int current_pickup = cap;
            
            for (int i = pickup_dist - 1; i >= 0 && current_pickup > 0; --i) {
                // 전부 수거 가능하면
                if (current_pickup >= pickups[i]) {
                    current_pickup -= pickups[i];
                    pickups[i] = 0;
                }
                else {
                    pickups[i] -= current_pickup;
                    current_pickup = 0;
                    break;
                }
            }
        }

        RemoveVector(deliveries);
        RemoveVector(pickups);
    }

    return answer;
}

int main()
{
    solution(4, 5, { 1,0,3,1,2 }, { 0,3,0,4,0 });
    solution(2, 7, { 1, 0, 2, 0, 1, 0, 2 }, { 0, 2, 0, 1, 0, 2, 0 });
}
