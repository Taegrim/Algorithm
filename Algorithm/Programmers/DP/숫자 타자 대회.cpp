#include <iostream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> points;
constexpr int MAX = 1e9;

int GetCost(int current, int target)
{
    if (current == target)
    {
        return 1;
    }

    auto& [sr, sc] = points[current];
    auto& [tr, tc] = points[target];

    int row_dist = abs(sr - tr);
    int col_dist = abs(sc - tc);

    int cost = 0;

    // 대각선 이동이 가능하면
    while (row_dist > 0 && col_dist > 0)
    {
        cost += 3;
        --row_dist;
        --col_dist;
    }

    // 둘중 하난 0이 됐으므로 2를 곱해서 더해도 됨
    cost += row_dist * 2;
    cost += col_dist * 2;

    return cost;
}

int solution(string numbers) {
    int n = numbers.size();

    // 0~9 숫자들 좌표 매기기
    points.assign(10, {});
    int count = 0;
    for (int i = 1; i < 10; ++i)
    {
        points[i].first = count / 3;
        points[i].second = count % 3;
        ++count;
    }
    points[0].first = 3;
    points[0].second = 1;

    // dp[left][right] 현재 왼손, 오른손 위치에 놓였을때의 최소 비용
    //  -> 이전까지의 비용
    vector<vector<int>> dp(10, vector<int>(10, MAX));
    vector<vector<int>> next(10, vector<int>(10, MAX)); // 현재 손을 움직인 경우의 비용
    dp[4][6] = 0;

    for (char c : numbers)
    {
        int num = c - '0';

        next.assign(10, vector<int>(10, MAX));

        for (int left = 0; left < 10; ++left)
        {
            for (int right = 0; right < 10; ++right)
            {
                if (dp[left][right] == MAX) continue;

                // 이전까지의 비용
                int cost = dp[left][right];

                // 왼손또는 오른손이 이미 놓여있다면 움직일 필요 없음
                if (left == num || right == num)
                {
                    next[left][right] = min(next[left][right], cost + 1);
                    continue;
                }

                // 왼손 움직이기
                next[num][right] = min(next[num][right], cost + GetCost(left, num));

                // 오른손 움직이기
                next[left][num] = min(next[left][num], cost + GetCost(right, num));
            }
        }

        dp = move(next);
    }

    int answer = MAX;

    for (int left = 0; left < 10; ++left)
    {
        for (int right = 0; right < 10; ++right)
        {
            answer = min(answer, dp[left][right]);
        }
    }

    return answer;
}

int main()
{
    solution("1756");
    solution("5123");
}
