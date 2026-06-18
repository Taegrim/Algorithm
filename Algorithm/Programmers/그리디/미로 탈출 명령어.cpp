#include <iostream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;

// x,y -> r,c 로 이동, 총 이동거리는 k, 같은 격자는 두 번 이상 방문 가능

string solution(int n, int m, int x, int y, int r, int c, int k) {
    // 0 based 로 변경
    --x; --y; --r; --c;

    // 시작점부터 종료지점까지 거리 구하기
    int dist = abs(r - x) + abs(c - y);
    int remain = k - dist;

    // 주어진 이동거리보다 거리가 더 멀거나
    // 종료지점 도착했을때 남은 거리가 홀수면 이동횟수를 k에 맞출 수 없음
    if (k < dist || remain % 2 == 1) {
        return "impossible";
    }

    string answer;
    string dir = "dlru";
    int dr[] = { 1, 0, 0, -1 };
    int dc[] = { 0, -1, 1, 0 };

    // 이동횟수에 여유가 있다면 d, l, r, u 순서대로 가는것 시도
    while (remain > 0) {

        for (int i = 0; i < 4; ++i) {
            int nr = x + dr[i];
            int nc = y + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                x = nr;
                y = nc;
                answer += dir[i];
                break;
            }
        }

        // 남은 이동횟수 갱신, 여유 횟수 갱신
        --k;
        dist = abs(r - x) + abs(c - y);
        remain = k - dist;
    }

    // 여유횟수가 없다면 d, l, r, u 방향 순서대로 탈출지점으로 이동
    if (r > x) {
        answer += string(r - x, 'd');
    }
    if (c < y) {
        answer += string(y - c, 'l');
    }
    if (c > y) {
        answer += string(c - y, 'r');
    }
    if (r < x) {
        answer += string(x - r, 'u');
    }

    return answer;
}

int main()
{
    solution(3, 4, 2, 3, 3, 1, 5);
    solution(2, 2, 1, 1, 2, 2, 2);
    solution(3, 3, 1, 2, 3, 3, 4);
}
