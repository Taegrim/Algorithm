#include <iostream>

#include <vector>
#include <limits>

using namespace std;

// 임의의 인접한 2개의 풍선 고르고 하나 터트린 다음 밀착
//  - 번호가 작은 풍선 터트리기는 최대 1번만 (기회 1번)

// 최후까지 남기는게 가능한 풍선 개수 반환
//  -> 나머지를 전부 터트릴수 있는가

// i번째 풍선의 왼쪽에서 무엇이 남을 수 있는지, 오른쪽에서 무엇이 남을 수 있는지
// -> 기회를 안쓰면 최솟값이 남음

int solution(vector<int> a) {
    int answer = 0;

    int n = a.size();

    vector<int> right_min(n);
    right_min[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        right_min[i] = min(right_min[i + 1], a[i]);
    }

    int left_min = std::numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // 왼쪽 오른쪽에서 하나라도 현재보다 큰게 나오면 됨
        if (left_min >= a[i] || right_min[i] >= a[i]) {
            ++answer;
        }

        left_min = min(left_min, a[i]);
    }

    return answer;
}

int main()
{
    solution({ 9,-1,-5 });
    solution({ -16,27,65,-2,58,-92,-71,-68,-61,-33 });
}
