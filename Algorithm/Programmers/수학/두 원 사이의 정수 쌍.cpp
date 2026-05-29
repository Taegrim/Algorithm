#include <iostream>

#include <vector>
#include <cmath>

using namespace std;

// 중심원, 반지름 r1, r2
// 두 원 사이(표면 포함)에 존재하는 점의 개수
// 점찍기와 유사한 문제


long long solution(int r1, int r2) {
    long long answer = 0;

    long long r1_sqaure = (long long)r1 * r1;
    long long r2_sqaure = (long long)r2 * r2;

    // 1사분면 계산
    for (long long i = 1; i <= r2; ++i) {
        // 바깥원은 넘으면 안되므로 정수변환 자동 내림처리
        long long max_y = (long long)sqrt(r2_sqaure - i * i);
        long long min_y = 0;

        // r1보다 i가 작을때만 처리
        // 안쪽원의 경계는 포함해야하므로 올림처리
        if (i < r1) {
            min_y = (long long)ceil(sqrt(r1_sqaure - i * i));
        }

        answer += max_y - min_y + 1;
    }

    // 4사분면까지 계산
    answer *= 4;

    return answer;
}

int main()
{
    solution(2, 3);
}
