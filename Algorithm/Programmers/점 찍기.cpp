#include <iostream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 원점으로부터 길이가 d인 원,
// 1사분면만 확인함
// 점의 간격은 k
//  찍을 수 있는 점의 개수 - d / k + 1


long long solution(int k, int d) {
    long long answer = 0;

    // x를 0 ~ d 까지 순회하면서 가능한 y의 개수 구하기
    // y^2 <= d*d - i * i
    // y <= sqrt(d*d - i*i) -> N
    //      N / k + 1 개
    for (long long i = 0; i <= d; i += k) {
        long long N = sqrt((long long)d * d - i * i);

        answer += N / k + 1;
    }

    return answer;
}

int main()
{
    solution(2, 4);
    solution(1, 5);
}
