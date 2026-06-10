#include <iostream>

#include <vector>

using namespace std;

// 연속 부분수열에 펄스 수열을 각 원소끼리 곱함
// 펄스 수열 : 1, -1이 번갈아 나오는 수열

// 연속 펄스 부분수열의 합 중 가장 큰 것 구하기

long long solution(vector<int> sequence) {
    // 직전까지의 음수곱, 양수곱의 최대값을 이용하면 될것
    long long prev_plus = sequence[0];
    long long prev_minus = -sequence[0];

    long long answer = max(prev_plus, prev_minus);

    for (int i = 1; i < sequence.size(); ++i) {
        // i번째가 1을 곱해야 하는 경우, i-1은 음수곱
        //   - prev_minus + sequence[i], sequence[i] 중 큰값
        long long plus = max(prev_minus + (long long)sequence[i], (long long)sequence[i]);

        // i번째가 -1 을 곱해야 하는 경우, i-1은 양수곱
        //   - prev_plus - sequence[i],  -sequence[i] 중 큰값
        long long minus = max(prev_plus - (long long)sequence[i], (long long)-sequence[i]);

        prev_plus = plus;
        prev_minus = minus;

        answer = max(answer, max(plus, minus));
    }

    return answer;
}

int main()
{
    solution({ 2, 3, -6, 1, 3, -1, 2, 4 });
}
