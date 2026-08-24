#include <iostream>

using namespace std;

int main()
{
    int a = 16;
    int b = 4;
    int n = 1;  // 하위 n번째 비트

    // 특정 원소만 끄기
    a &= ~(1 << n);

    // 특정 원소 토글
    a ^= (1 << n);

    // 포함 여부 확인
    (a & (1 << n));

    // 켜져있는 것중 가장 작은 비트 구하기
    // 음수는 보수로 사용하는것 이용
    a & ~a;

    // 켜져있는 것중 가장 작은 비트 끄기
    a &= (a - 1);

    // 모든 부분집합 순회
    for (int subset = a; subset; subset = ((subset - 1) & a))
    {
    }

    // a를 2^n 으로 나누기
    (a >> n);

    // a를 b로 나눈 나머지
    (a & (b - 1));
}
