#include <iostream>

using namespace std;

// w, h 방향으로 향하는 벡터? 기울기?

//
// 점 찍기와 비슷한 문제, 사각형의 오른쪽을 기준으로
// 직선이 더 위에있다면 유효한 사각형,
// 기울기를 이용해서 y값을 구하면 됨

// Y = (-h/w)X + h

long long solution(int w, int h) {
    long long answer = 0;

    // 0,0 에서 (w, h) 로 올라가는 거로 뒤집어서 생각
    // 사각형의 왼쪽과 직선을 비교하면 됨
    for (long long i = 0; i < w; ++i) {
        answer += (long long)h * i / w;
    }
    // 직선 아래만 구했으므로 2배 해서 위쪽까지
    answer *= 2;

    return answer;
}

int main()
{
    solution(8, 12);
}
