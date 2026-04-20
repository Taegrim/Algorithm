#include <iostream>

#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 동일한 가짓수의 토핑 수로 나누기

//// 매번 양쪽을 나누고 set으로 체크할 경우 시간초과!
//int solution(vector<int> topping) {
//    int answer = 0;
//
//    for (int i = 0; i < topping.size(); ++i) {
//        unordered_set<int> left(topping.begin(), topping.begin() + i);
//        unordered_set<int> right(topping.begin() + i, topping.end());
//
//        if (left.size() == right.size()) {
//            ++answer;
//        }
//    }
//
//    return answer;
//}

// 양쪽을 동시에 체크하면?
//  -> 오른쪽 방향으로 순회하면서 오른쪽 정보를 알아야함
//     순회하면서 몇종류인지 체크, 남은게 몇종류인지 체크

int solution(vector<int> topping) {
    int answer = 0;

    // 왼쪽, 오른쪽 토핑의 종류와 개수 unordered_map
    // 왼쪽은 종류만 알아도 되므로 unordered_set으로 해도 됨
    unordered_map<int, int> left, right;

    // 탐색 전 남은 종류 초기화
    for (int i : topping) {
        ++right[i];
    }

    for (int i : topping) {
        // 왼쪽에 추가
        ++left[i];

        // 오른쪽 남은 토핑에서 제거
        --right[i];
        if (right[i] == 0) {
            right.erase(i);
        }

        if (left.size() == right.size()) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    solution({ 1, 2, 1, 3, 1, 4, 1, 2 });
    solution({ 1, 2, 3, 1, 4 });
}
