#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

// 미사일 최소로 모든 폭격 미사일 요격

// A의 폭격 미사일 - x축에 평행한 직선, 정수쌍 (s,e)로 표현, s랑 e는 포함 X
// B는 x좌표에서 y축에 수평이 되게 발사해서 걸친 모든 미사일 관통해 요격
//  - 요격 미사일은 실수 x에서 발사 가능


// 구간을 나누는 방식
int solution(vector<vector<int>> targets) {
    int answer = 0;

    // x가 작은 순으로 정렬
    sort(targets.begin(), targets.end());

    int left = targets[0][0];
    int right = targets[0][1];

    for (int i = 1; i < targets.size(); ++i) {
        int new_left = targets[i][0];
        int new_right = targets[i][1];

        // 새 미사일이 구간 내에 들어오면 구간 갱신
        if (new_left < right) {
            left = max(left, new_left);
            right = min(right, new_right);
        }
        // 구간 밖이라면 기존은 요격하고 새로운 구간 갱신
        else {
            ++answer;
            left = new_left;
            right = new_right;
        }
    }
    // 마지막은 항상 요격
    ++answer;

    return answer;
}


// 끝점 기준 체크
int solution(vector<vector<int>> targets) {
    int answer = 1;

    // 끝점 기준 정렬
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });

    int end = targets[0][1];

    for (int i = 1; i < targets.size(); ++i) {
        int start = targets[i][0];

        // 새 미사일의 시작점이 끝점보다 크거나 같다면 요격 불가능
        // 한번 요격하고 갱신
        if (start >= end) {
            ++answer;
            end = targets[i][1];
        }
    }

    return answer;
}

int main()
{
    solution({ {4,5} ,{4,8},{10,14},{11,13},{5,12},{3,7},{1,4} });
}
