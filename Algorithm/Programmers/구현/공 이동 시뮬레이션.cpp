#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    // 범위 구간 지정
    long long top = x;
    long long down = x;
    long long left = y;
    long long right = y;

    // 역방향 시뮬레이션
    // 현재 위치가 벽과 닿아있다면 거리 내에 아무 위치에서 올 수 있음
    //  -> 이동할 수 있는 구간으로 표현
    for (int i = queries.size() - 1; i >= 0; --i)
    {
        long long dx = queries[i][1];

        if (queries[i][0] == 0)
        {
            // 왼쪽으로 이동했었음
            // 벽에 안붙어있다면 정확히 dx 거리에서 와야함
            if (left != 0)
            {
                left += dx;
            }
            right = min(right + dx, (long long)(m - 1));
        }
        else if (queries[i][0] == 1)
        {
            // 오른쪽으로 이동했었음
            if (right != m - 1)
            {
                right -= dx;
            }
            left = max(left - dx, 0LL);
        }
        else if (queries[i][0] == 2)
        {
            // 위로 이동했었음
            if (top != 0)
            {
                top += dx;
            }
            down = min(down + dx, (long long)(n - 1));
        }
        else if (queries[i][0] == 3)
        {
            // 아래로 이동했었음
            if (down != n - 1)
            {
                down -= dx;
            }
            top = max(top - dx, 0LL);
        }

        // 이전 지점이 범위를 벗어나면 도착할 수 없음
        if (left > right || top > down)
        {
            return 0;
        }
    }

    return (right - left + 1) * (down - top + 1);
}

int main()
{
    solution(2, 2, 0, 0, {{2, 1}, {0, 1}, {1, 1}, {0, 1}, {2, 1}} );
    solution(2, 5, 0, 1, {{3, 1}, {2, 2}, {1, 1}, {2, 3}, {0, 1}, {2, 1}} );
}
