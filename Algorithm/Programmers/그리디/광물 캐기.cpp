#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum pick { dia, iron, stone, COUNT };


// 곡괭이를 선택하면 5개를 연속으로 캠
// 최소 피로도 구하기
// 최대한 같은 곡괭이, 아니면 한단계 낮은 곡괭이를 선택해야함

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    int total_picks = 0;
    for (int pick : picks) {
        total_picks += pick;
    }

    // 캘 수 있는 최대 광물 수
    int max_minerals = min((int)minerals.size(), total_picks * 5);

    vector<vector<int>> v;

    // 5개마다 각 곡괭이를 사용했을때 필요한 피로도 구하기
    for (int i = 0; i < max_minerals; i += 5) {
        vector<int> cost(COUNT, 0);

        for (int j = i; j < i + 5; ++j) {
            if (max_minerals <= j) break;

            if (minerals[j] == "diamond") {
                cost[dia] += 1;
                cost[iron] += 5;
                cost[stone] += 25;
            }
            else if (minerals[j] == "iron") {
                cost[dia] += 1;
                cost[iron] += 1;
                cost[stone] += 5;
            }
            else {
                cost[dia] += 1;
                cost[iron] += 1;
                cost[stone] += 1;
            }
        }

        v.push_back(cost);
    }

    // 돌곡괭이 기준으로 가장 피로도가 많이 드는 순으로 정렬
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[stone] > b[stone];
        });

    // 피로도가 많이 소모되는 것부터 상위 곡괭이로 캐기
    for (const auto& cost : v) {
        if (picks[dia] > 0) {
            answer += cost[dia];
            --picks[dia];
        }
        else if (picks[iron] > 0) {
            answer += cost[iron];
            --picks[iron];
        }
        else if (picks[stone] > 0) {
            answer += cost[stone];
            --picks[stone];
        }
    }

    return answer;
}

int main()
{
    solution({ 1,2,3 }, { "diamond", "diamond", "diamond",
        "iron", "iron", "diamond", "iron", "stone" });
    solution({ 0,1,1 }, { "diamond", "diamond", "diamond", "diamond", "diamond",
        "iron", "iron", "iron", "iron", "iron", "diamond" });
}
