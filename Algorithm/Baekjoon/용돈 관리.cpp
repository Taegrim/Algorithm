#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// N일동안 사용할 금액 계산, M번만 빼서 쓰기
// 한번에 K원 인출, 모자라면 남은금액 넣고 다시 K 인출
//  -> M번 맞추기 위해 모자라지 않아도 넣고 K 인출 가능

// money_list 는 매일 사용할 금액, M은 인출할 횟수
int solution(vector<int> money_list, int M) 
{

    int left = 0;
    int right = 0;

    for (int money : money_list)
    {
        left = max(left, money);
        right += money;
    }

    int answer = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // 용돈 사용 확인

        int remain = mid;
        int count = 1;
        
        for (int money : money_list)
        {
            if (remain < money)
            {
                ++count;
                remain = mid;
            }

            remain -= money;
        }

        if (count > M)
        {
            // 횟수보다 더많이 인출함 -> 돈이 부족함
            left = mid + 1;
        }
        else if (count <= M)
        {
            // 횟수보다 더 적게 인출함 -> 가능한 경우이므로 정답 후보
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}

int main()
{
    solution({ 100, 400, 300, 100, 500, 101, 400 }, 5);
}
