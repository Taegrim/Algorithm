#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> dp(9);

    // N을 이어붙이는 용도
    int paste = 0;

    for (int i = 1; i <= 8; ++i)
    {
        paste = paste * 10 + N;
        dp[i].insert(paste);

        // 좌항식에 N을 left개, 우항식에 N을 Right개 사용했을 때
        // 나올 수 있는 모든 경우를 dp[i]에 저장
        for (int left = 1; left < i; ++left)
        {
            int right = i - left;

            for (int a : dp[left])
            {
                for (int b : dp[right])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);

                    // 0 나누기 방지
                    if (b != 0)
                    {
                        dp[i].insert(a / b);
                    }
                }
            }
        }

        if (dp[i].count(number))
        {
            answer = i;
            break;
        }
    }

    return answer;
}

int main()
{
    solution(5, 12);
    solution(2, 11);
}
