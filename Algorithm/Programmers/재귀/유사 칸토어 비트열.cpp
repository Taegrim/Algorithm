#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 직전의 비트열에서 1을 11011로 치환하고 0을 00000으로 치환함
// 0번째 비트열은 "1"

//               1
//   1     1     0     1     1
// 11011 11011 00000 11011 11011

// 5의 단위로 늘어남

long long PrevNumber(long long num, int n)
{
    // 1번째 칸토어 비트열 확인
    if (n == 1) {
        if (num == 2) {
            return 0;
        }
        else {
            return 1;
        }
    }

    // 현재 속해있는 구간에서 몇번째 숫자인지
    long long current = num % 5;

    // n 이 1까지 내려가면서 이전 숫자들을 구하는 방식
    long long prev = PrevNumber(num / 5, n - 1);

    // 이전 숫자가 1이면 현재 가운데 숫자는 0, 나머진 1
    if (prev == 1) {
        if (current == 2) {
            return 0;
        }
        else {
            return 1;
        }
    }
    // 이전 숫자가 0이면 무조건 0 변환
    else {
        return 0;
    }
}

int solution(int n, long long l, long long r) {
    int answer = 0;

    // 직전 숫자를 알 수 있다면?
    for (long long ll = l; ll <= r; ++ll) {
        long long prev = PrevNumber(ll - 1, n);

        if (prev == 1) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    solution(2, 4, 17);
}
