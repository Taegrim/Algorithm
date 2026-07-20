#include <iostream>

#include <vector>
#include <queue>

using namespace std;

// waiting_times[type][count] : 유형별로 count명 배치했을때 걸리는 시간들을 저장
vector<vector<int>> waiting_times;
int answer;

// n 명이 배치되었을 때 걸리는 시간
int GetTime(const vector<vector<pair<int, int>>>& vec, int type, int n)
{
    const auto& v = vec[type];

    int sum = 0;

    // 시작시간 + 걸리는 시간 = 끝나는 시간
    // 우선순위 큐로 가장 빨리 끝나는 시간부터 찾도록 함
    priority_queue<int, vector<int>, greater<int>> last_ends;

    // 첫 n명을 먼저 배치
    int idx = 0;
    for (; idx < n && idx < v.size(); ++idx)
    {
        last_ends.push(v[idx].first + v[idx].second);
    }

    for (idx; idx < v.size(); ++idx)
    {
        int start = v[idx].first;
        int last_end = last_ends.top();
        last_ends.pop();

        // 끝난 시간이 더 빠르다면 기다리지 않고 시작시간에 시작
        int actual_start = max(start, last_end);
        sum += actual_start - start;

        last_ends.push(actual_start + v[idx].second);
    }

    return sum;
}

void DFS(int k, int type, int remain, int total_time)
{
    if (type == k)
    {
        if (remain == 0)
        {
            answer = min(answer, total_time);
        }
        return;
    }

    for (int i = 0; i <= remain; ++i)
    {
        // 현재 type에 몇명 배치할지
        int count = 1 + i;

        // 다음 타입에 배치할 남은 인원, 현재 배치했을때 걸리는 시간을 DFS로 넘기기
        DFS(k, type + 1, remain - i, total_time + waiting_times[type][count]);
    }
}

// 상담유형 k, 멘토 n명
int solution(int k, int n, vector<vector<int>> reqs) {
    vector<vector<pair<int, int>>> v(k);
    answer = 1e9;
    
    for (const auto& req : reqs)
    {
        int type = req[2] - 1;
        int start = req[0];
        int duration = req[1];

        v[type].push_back({ start, duration });
    }

    // 한 유형에 줄 수 있는 최대 수
    int max_remain = n - k + 1;
    waiting_times.assign(k, vector<int>(max_remain + 1, 0)); 

    for (int type = 0; type < k; ++type)
    {
        // 타입별로 count명 배치했을 때 걸리는 시간 구해두기
        for (int count = 1; count <= max_remain; ++count)
        {
            waiting_times[type][count] = GetTime(v, type, count);
        }
    }

    int remain = n - k;
    DFS(k, 0, remain, 0);

    return answer;
}

int main()
{
    solution(3, 5, { {10, 60, 1}, {15, 100, 3}, {20, 30, 1},
        {30, 50, 3}, {50, 40, 1}, {60, 30, 2}, {65, 30, 1}, {70, 100, 2} });
    solution(2, 3, {{5, 55, 2}, {10, 90, 2}, {20, 40, 2}, {50, 45, 2}, {100, 50, 2}} );
}
