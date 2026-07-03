#include <iostream>

#include <string>
#include <vector>

using namespace std;

// s ~ e 사이의 수 중 억억단에서 가장 많이 등장한 수
//  -> 약수 개수?

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    vector<int> counts(e + 1, 0);

    // 약수 개수 전처리, 에라토네스 체
    for (int i = 1; i <= e; ++i)
    {
        for (int j = i; j <= e; j += i)
        {
            ++counts[j];
        }
    }

    // 역순으로 검사해서 약수가 가장 많은 수 저장
    vector<int> dp(e + 1, 0);
    int count = counts[e];  // 약수 가장 많은 개수
    dp[e] = e;

    for (int i = e - 1; i >= 1; --i)
    {
        // 현재 숫자가 약수가 더 많거나 같다면 dp 현재 수로
        if (count <= counts[i])
        {
            count = counts[i];
            dp[i] = i;
        }
        // 현재 숫자가 약수가 더 적다면 이전 dp 값 그대로
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    for (int start : starts)
    {
        answer.push_back(dp[start]);
    }

    return answer;
}

int main()
{
    solution(8, { 1,3,7 });
}
