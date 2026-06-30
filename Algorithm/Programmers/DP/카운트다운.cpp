#include<iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 남은점수 이상 점수내면 실격
// 같은 라운드에 종료되면 싱글 or 불 개수로 판정,  같다면 선공 승리

// [최소 턴, 싱글 + 불 개수] 리턴

vector<int> solution(int target) {
    vector<int> answer;

    // 싱글 or 불
    int singles[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,50 };
    int doubles[] = { 22, 24, 26, 28, 30, 32, 34, 36, 38, 40 };
    int triples[] = { 21, 27, 33, 39, 42, 45, 48, 51, 54, 57, 60 };

    // 최소횟수, 불+싱글 개수 dp
    vector<pair<int, int>> dp(target + 1, {1e9, 0});
    queue<pair<int, int>> q;

    for (int num : singles)
    {
        if (num > target) continue;

        q.push({ num, 1 });
        dp[num] = { 1,1 };
    }
    for (int num : doubles)
    {
        if (num > target) continue;

        q.push({ num, 1 });
        dp[num] = { 1,0 };
    }
    for (int num : triples)
    {
        if (num > target) continue;

        q.push({ num, 1 });
        dp[num] = { 1,0 };
    }

    while (!q.empty())
    {
        auto [cur, count] = q.front();
        q.pop();

        int next_count = count + 1;

        for (int num : singles)
        {
            int next = cur + num;
            int next_bools = dp[cur].second + 1;

            if (next > target) continue;

            // 최소횟수거나, 같다면 불 수가 많을때 처리
            if (next_count < dp[next].first || 
                (next_count == dp[next].first && next_bools > dp[next].second))
            {
                dp[next] = { next_count, next_bools };
                q.push({ next, next_count });
            }
        }

        for (int num : doubles)
        {
            int next = cur + num;
            int next_bools = dp[cur].second;

            if (next > target) continue;

            // 최소횟수거나, 같다면 불 수가 많을때 처리
            if (next_count < dp[next].first ||
                (next_count == dp[next].first && next_bools > dp[next].second))
            {
                dp[next] = { next_count, next_bools };
                q.push({ next, next_count });
            }
        }

        for (int num : triples)
        {
            int next = cur + num;
            int next_bools = dp[cur].second;

            if (next > target) continue;

            // 최소횟수거나, 같다면 불 수가 많을때 처리
            if (next_count < dp[next].first ||
                (next_count == dp[next].first && next_bools > dp[next].second))
            {
                dp[next] = { next_count, next_bools };
                q.push({ next, next_count });
            }
        }
    }

    return { dp[target].first, dp[target].second };
}

int main()
{
    solution(21);
    solution(58);
}
