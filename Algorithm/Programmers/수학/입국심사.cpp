#include <iostream>

#include <vector>

using namespace std;

// 빈 심사대로 가서 심사, 더 빨리 끝나는 심사대가 있다면 기다렸다가 받기 가능

// 시간 안에 n명을 모두 처리할 수 있는지 확인
// 특정 시간을 심사대로 나누면 처리할 수 있는 사람 수가 나옴

long long solution(int n, vector<int> times) {
    long long answer = 0;

    // 최소 = 1, 제일 오래걸리는 시간 = 가장 오래걸리는 심사관 * n
    long long left = 1;
    long long right = 1;

    for (int time : times) {
        right = max(right, (long long)time);
    }
    right *= (long long)n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long count = 0;
        for (int time : times) {
            count += mid / time;

            // 이미 처리 가능하면 빠져나오기
            if (count >= n) {
                break;
            }
        }

        // 처리 가능하면 구간을 왼쪽으로 이동
        if (count >= n) {
            answer = mid;
            right = mid - 1;
        }
        // 처리 불가능하면 구간을 오른쪽으로 이동
        else {
            left = mid + 1;
        }
    }

    return answer;
}

int main()
{
    solution(6, { 7, 10 });
}
