#include <iostream>

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 두 점수가 모두 낮다면 인센티브 X

int solution(vector<vector<int>> scores) {
    // 완호 점수
    int wanho_manner = scores[0][0];
    int wanho_evaluation = scores[0][1];
    int wanho_sum = wanho_manner + wanho_evaluation;

    // 근무 태도, 동료 평가 정렬
    // 같은 근무 태도일 때 최대 평가를 나중에 갱신하기 위해 평가는 오름차순
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
        });

    int answer = 1;
    int max_evaluation = 0;

    // 동점자가 아니면 뒷 사람은 앞사람보다 항상 근무 태도가 낮으므로
    // 앞에서 구한 최대 동료 평가보다 낮으면 인센 X
    for (const auto& score : scores) {
        int manner = score[0];
        int evaluation = score[1];
        int sum = manner + evaluation;

        if (evaluation < max_evaluation) {
            if (manner == wanho_manner && evaluation == wanho_evaluation) {
                return -1;
            }
            continue;
        }

        if (sum > wanho_sum) {
            ++answer;
        }

        max_evaluation = max(max_evaluation, evaluation);
    }

    return answer;
}

int main()
{
    solution({ {2,2}, {1,4}, {3,2}, {3,2}, {2,1} });
}
