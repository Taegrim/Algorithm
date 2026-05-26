#include <iostream>

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 이전에 나온 몸무게들에 한해서만 계산

long long solution(vector<int> weights) {
    long long answer = 0;

    sort(weights.begin(), weights.end());

    // 여태까지 등장한 사람들의 무게와, 해당 무게가 몇명인지
    map<int, int> m;

    // 1:1, 2:3, 1:2, 3:4 계산
    // 정수 몸무게만 있으므로 떨어지는 계산만 처리하면 됨
    for (int weight : weights) {
        // 1:1
        if (m.count(weight)) {
            answer += m[weight];
        }

        // 2:3
        if ((weight * 2) % 3 == 0) {
            if (m.count(weight * 2 / 3)) {
                answer += m[weight * 2 / 3];
            }
        }

        // 1:2
        if (weight % 2 == 0) {
            if (m.count(weight / 2)) {
                answer += m[weight / 2];
            }
        }

        // 3:4
        if ((weight * 3) % 4 == 0) {
            if (m.count(weight * 3 / 4)) {
                answer += m[weight * 3 / 4];
            }
        }

        // 계산한 몸무게 map 에 집어넣음
        ++m[weight];
    }

    return answer;
}

int main()
{
    solution({ 100, 180, 360, 100, 270 });

}
