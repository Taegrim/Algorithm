#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// n개의 대학에서 강연 요청, 
// 각 대학에선 d일안에 오면 p 지불
// 하루에 한곳에서만 강연 가능 

// requests = [금액, 제한기한]
int solution(vector<vector<int>> requests) {
    int answer = 0;

    sort(requests.begin(), requests.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });

    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& req : requests)
    {
        int money = req[0];
        int deadline = req[1];

        pq.push(money);

        // 데드라인이 2인 경우엔 2개의 강의밖에 못함
        // 가장 금액이 낮은 강의부터 드랍
        // 제한기한이 빠른순으로 정렬했으므로 항상 맞음
        while (pq.size() > deadline)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    return answer;
}

int main()
{
    solution({ {20, 1}, {2, 1}, {10, 3}, {100, 2}, {8, 2}, {5, 20}, {50, 10} });
    solution({});
}
