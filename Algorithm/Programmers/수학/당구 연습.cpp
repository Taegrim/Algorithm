#include <iostream>

#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// 리스트 -> 공들의 위치,  공의 시작점은 같음
// 가로 m 세로 n, 시작공좌표 startX, startY, 목표 공 좌표 balls

// 벽에 튕긴다 -> 반사벡터를 뒤집으면 공에서부터 직선벡터가 나옴

int GetSquaredLength(int m, int n, int start_x, int start_y, int ball_x, int ball_y)
{
    int length = numeric_limits<int>::max();
    int x{}, y{};

    // 왼쪽 벽 반사, y가 같고, 치려는 공이 왼쪽이라면 불가능
    if (!(start_y == ball_y && ball_x < start_x)) {
        x = start_x + ball_x;
        y = abs(ball_y - start_y);

        length = min(length, x * x + y * y);
    }

    // 오른쪽 벽 반사, y가 같고, 치려는 공이 오른쪽이라면 불가능
    if (!(start_y == ball_y && ball_x > start_x)) {
        x = m - start_x + m - ball_x;
        y = abs(ball_y - start_y);

        length = min(length, x * x + y * y);
    }

    // 위쪽 벽 반사, x가 같고, 치려는 공이 위쪽이라면 불가능
    if (!(start_x == ball_x && ball_y > start_y)) {
        x = abs(ball_x - start_x);
        y = n - start_y + n - ball_y;

        length = min(length, x * x + y * y);
    }

    // 아래쪽 벽 반사, x가 같고, 치려는 공이 아래쪽이라면 불가능
    if (!(start_x == ball_x && ball_y < start_y)) {
        x = abs(ball_x - start_x);
        y = start_y + ball_y;

        length = min(length, x * x + y * y);
    }

    return length;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    answer.reserve(balls.size());

    for (const auto& ball : balls) {
        answer.push_back(GetSquaredLength(m, n, startX, startY, ball[0], ball[1]));
    }

    return answer;
}

int main()
{
    solution(10, 10, 3, 7, { {7,7}, {2,7}, {7,3}, {4, 6} });
}
